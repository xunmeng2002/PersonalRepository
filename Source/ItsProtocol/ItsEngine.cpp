#pragma warning(disable: 4311 4302)
#include "pch.h"
#include "OfferDlg.h"
#include "AccountInfo.h"
#include "ItsEngine.h"
#include "Logger.h"
#include "ItsUtility.h"
#include "ItsFields.h"
#include "command_id.h"
#include "TimeUtility.h"
#include "Event.h"
#include "Sqlite.h"


ItsEngine::ItsEngine(const std::string& channelID, const std::string& tcpBindIP, const std::string& tcpBindPort, const std::string& udpIP, const std::string& udpPort)
	:ThreadBase("ItsEngine"), m_MdbSubscriber(nullptr), m_ChannelID(channelID), m_OrderLocalIDBuff{ 0 }, m_UdpRemoteIP(udpIP), m_UdpRemotePort(udpPort)
{
	m_LogBuff = new char[BuffSize];
	m_Tcp = new TcpSelectServer();
	((TcpSelectServer*)m_Tcp)->SetBindAddressInfo(tcpBindIP.c_str(), tcpBindPort.c_str());
	m_Tcp->Subscriber(this);

	m_UdpClient = new UdpClient();
	m_UdpClient->SetRemoteAddress(udpIP.c_str(), udpPort.c_str());
	m_AccountInfo = new AccountInfo();
}
ItsEngine::~ItsEngine()
{
	delete m_UdpClient;
	m_UdpClient = nullptr;
	
	delete m_Tcp;
	m_Tcp = nullptr;

	delete[] m_LogBuff;
	m_LogBuff = nullptr;
}
void ItsEngine::SetOfferDlg(COfferDlg* offerDlg, AccountInfo* accountInfo)
{
	m_OfferDlg = offerDlg;
	*m_AccountInfo = *accountInfo;
}
void ItsEngine::RegisterSubscriber(MdbSubscriber* mdbSubscriber)
{
	m_MdbSubscriber = mdbSubscriber;
}
void ItsEngine::RegisterSqlite(Sqlite* sqlite)
{
	m_Sqlite = sqlite;
}
bool ItsEngine::Init()
{
	if (!m_UdpClient->Init(false))
	{
		return false;
	}
	m_Tcp->SetSocketTimeOut(100);
	return m_Tcp->Init();
}

void ItsEngine::ThreadInit()
{
	ThreadBase::ThreadInit();
	m_MdbSubscriber->ReqLogin();
}
void ItsEngine::Run()
{
	m_Tcp->HandleTcpEvent();
	HandleRecvData();
}
void ItsEngine::CheckLoginStatus()
{
	if (m_LoginStatus.load())
	{
		return;
	}
	m_MdbSubscriber->ReqLogin();
}

void ItsEngine::OnConnect(int sessionID, const char* ip, const char* port)
{
	m_SessionIDs.insert(sessionID);

	CheckLoginStatus();
}
void ItsEngine::OnDisConnect(int sessionID, const char* ip, const char* port)
{
	m_SessionIDs.erase(sessionID);
}
void ItsEngine::OnRecv(TcpEvent* tcpEvent)
{
	m_RecvDatas.push_back(tcpEvent);
}

void ItsEngine::UpdateLoginStatus(bool loginStatus)
{
	m_LoginStatus.store(loginStatus);
	m_AccountInfo->LoginStatus = loginStatus;
	m_OfferDlg->UpdateLoginStatus(m_AccountInfo->AccountID, loginStatus);
}
void ItsEngine::OnRtnOrder(Order* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleRtnOrder: %s", m_LogBuff);
	m_OfferDlg->UpdateRtnOrderNum(m_AccountInfo->AccountID, ++m_AccountInfo->RtnOrderNum);
	auto order = GetOrder(field->OrderLocalID, field->InsertDate, field->OrderSysID);
	if (order != nullptr)
	{
		order->OrderSysID = field->OrderSysID;
		order->OrderStatus = field->OrderStatus;
		if (field->VolumeTraded > order->VolumeTraded)
		{
			order->VolumeTraded = field->VolumeTraded;
			if (order->VolumeTraded == order->Volume)
			{
				order->OrderStatus = OrderStatus::AllTraded;
			}
		}
		order->ErrorID = field->ErrorID;
		order->ErrorMsg = field->ErrorMsg;
		order->ExchangeInsertDate = field->ExchangeInsertDate.empty() ? order->ExchangeInsertDate : field->ExchangeInsertDate;
		order->ExchangeInsertTime = field->ExchangeInsertTime.empty() ? order->ExchangeInsertTime : field->ExchangeInsertTime;
		order->CancelDate = field->CancelDate.empty() ? order->CancelDate : field->CancelDate;
		order->CancelTime = field->CancelTime.empty() ? order->CancelTime : field->CancelTime;
		order->IsLocalOrder = IsLocalOrder::Local;
	}
	else
	{
		order = new Order(*field);
		order->IsLocalOrder = IsLocalOrder::Others;
		AddOrder(order);

		order->ToString(m_LogBuff, BuffSize);
		WRITE_LOG(LogLevel::Warning, "Other Source Order. %s", m_LogBuff);
	}
	m_Sqlite->OnOrder(order);

	PushOrder(order);
}
void ItsEngine::OnRtnTrade(Trade* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleRtnTrade: %s", m_LogBuff);

	m_OfferDlg->UpdateRtnTradeNum(m_AccountInfo->AccountID, ++m_AccountInfo->TradeNum);
	m_OfferDlg->UpdateRtnTradeNum(m_AccountInfo->AccountID, ++m_AccountInfo->RtnTradeNum);
	m_AccountInfo->TradeVolume += field->Volume;
	m_OfferDlg->UpdateRtnTradeNum(m_AccountInfo->AccountID, m_AccountInfo->TradeVolume);

	PushTrade(field);
	CheckAndAddTrade(field);
}
void ItsEngine::OnErrRtnOrderCancel(OrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleErrRtnOrderCancel: %s", m_LogBuff);

	auto orderCancel = GetOrderCancelFromOrderLocalID(field->OrderLocalID);
	if (orderCancel != nullptr)
	{
		orderCancel->ErrorID = field->ErrorID;
		orderCancel->ErrorMsg = field->ErrorMsg;
	}
	else
	{
		orderCancel = new OrderCancel(*field);
		orderCancel->ToString(m_LogBuff, BuffSize);
		WRITE_LOG(LogLevel::Warning, "Other Source OrderCancel. %s", m_LogBuff);

		AddOrderCancel(orderCancel);
	}
	m_Sqlite->OnOrderCancel(orderCancel);

	PushOrderCancel(field);
}


void ItsEngine::SelectMdbOrderSequenceCallback(OrderSequence* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbOrderSequenceCallback %s", m_LogBuff);

	m_OrderSequences.insert(field);
}
void ItsEngine::SelectMdbOrderCallback(Order* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbOrderCallback %s", m_LogBuff);

	AddOrder(field);
}
void ItsEngine::SelectMdbOrderCancelCallback(OrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbOrderCancelCallback %s", m_LogBuff);

	AddOrderCancel(field);
}
void ItsEngine::SelectMdbTradeCallback(Trade* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbTradeCallback %s", m_LogBuff);

	m_Trades.insert(field);
}

void ItsEngine::HandleRecvData()
{
	while (!m_RecvDatas.empty())
	{
		auto tcpEvent = m_RecvDatas.front();
		m_RecvDatas.pop_front();
		while (tcpEvent->Length > 0)
		{
			int len = *(unsigned short*)(tcpEvent->ReadPos);
			_ASSERT(len + sizeof(unsigned short) == tcpEvent->Length);
			if (tcpEvent->Length < len + sizeof(unsigned short))
			{
				WRITE_LOG(LogLevel::Error, "Invalid Message:[%s] Message len:[%d], recv Length:[%d]", tcpEvent->ReadPos, len + sizeof(unsigned short), tcpEvent->Length);
				return;
			}
			tcpEvent->Shift(sizeof(unsigned short));
			WRITE_LOG(LogLevel::Info, "ItsMsg Len:[%d], Recv:[%s]", len, tcpEvent->ReadPos);

			const char* end = tcpEvent->ReadPos + len;
			m_ItsItems.clear();
			GetItsItems(tcpEvent->ReadPos, end, m_ItsItems);
			tcpEvent->Shift(len);
			if (!CheckItsMessage(m_ItsItems))
			{
				WRITE_LOG(LogLevel::Error, "Invalid Message:[%s], len:[%d]", tcpEvent->ReadPos, len);
				break;;
			}
			auto cmd = atoi(m_ItsItems[1].c_str());
			switch (cmd)
			{
			case CMS_CID_INSERT_ORDER:
			{
				ItsHandleInsertOrder(tcpEvent->SessionID, new ItsInsertOrder(m_ItsItems));
				break;
			}
			case CMS_CID_CANCEL_ORDER:
			{
				ItsHandleCancelOrder(tcpEvent->SessionID, new ItsInsertOrderCancel(m_ItsItems));
				break;
			}
			default:
				break;
			}
		}
		tcpEvent->Free();
	}
}
void ItsEngine::ItsHandleInsertOrder(int sessionID, ItsInsertOrder* field)
{
	auto it = find_if(m_InsertOrderKeys.begin(), m_InsertOrderKeys.end(), [&](ItsInsertOrderKey* key) {
		return key->TradingDay == field->TradingDay && key->RequestID == field->RequestID;
		});
	if (it != m_InsertOrderKeys.end())
	{
		return SendResponse(sessionID, field->SequenceNo, "-1", "Duplicate Order");
	}
	if (!m_LoginStatus)
	{
		m_MdbSubscriber->ReqLogin();
		return SendResponse(sessionID, field->SequenceNo, "-1", "Offer not Login");
	}
	
	m_InsertOrderKeys.insert(new ItsInsertOrderKey({ field->TradingDay, field->RequestID }));
	

	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);

	Order* order = new Order();
	order->TradingDay = GetLocalDate();
	order->AccountID = field->AccountID;
	order->CurrencyID = field->CurrencyID;
	order->ExchangeID = field->ExchangeID;
	order->InstrumentID = field->InstrumentID;
	order->OrderLocalID = GetNextOrderLocalID(field->TradingDay);
	order->OrderSysID = "";
	order->Direction = ConvertToDirection(field->Direction);
	order->OffsetFlag = OffsetFlag::Open;
	order->HedgeFlag = HedgeFlag::Speculation;
	order->OrderPriceType = ConvertToOrderPriceType(field->OrderPriceType);
	order->Price = atof(field->Price.c_str());
	order->Volume = atoi(field->Volume.c_str());
	order->VolumeTraded = 0;
	order->OrderStatus = OrderStatus::Inserting;
	order->RequestID = field->RequestID;
	order->FrontID = "";
	order->SessionID = sessionID;
	order->InsertDate = field->TradingDay;
	order->InsertTime = GetLocalTime();
	order->ExchangeInsertDate = "";
	order->ExchangeInsertTime = "";
	order->CancelDate = "";
	order->CancelTime = "";
	order->ForceCloseReason = ForceCloseReason::NotForceClose;
	order->IsLocalOrder = IsLocalOrder::Local;
	order->TimeCondition = ConvertToTimeCondition(field->TimeCondition);
	order->GTDDate = "";
	order->VolumeCondition = ConvertToVolumeCondition(field->VolumeCondition);
	if (order->VolumeCondition == VolumeCondition::CV)
	{
		order->MinVolume = order->Volume;
	}
	else
	{
		order->MinVolume = atoi(field->MinVolume.c_str());
	}
	order->ContingentCondition = ContingentCondition::Immediately;
	order->StopPrice = 0.0;
	order->IsSwapOrder = 0;
	order->T1Valid = atoi(field->T1Valid.c_str());

	order->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);
	AddOrder(order);
	if (order->TimeCondition != TimeCondition::GFD)
	{
		return SendResponse(sessionID, field->SequenceNo, "-1", "Unsupported TimeCondition");
	}

	SendResponse(sessionID, field->SequenceNo);
	m_MdbSubscriber->ReqInsertOrder(order);
	
	m_Sqlite->OnItsInsertOrder(field);
	m_Sqlite->OnOrder(order);
	m_OfferDlg->UpdateReqOrderNum(m_AccountInfo->AccountID, ++m_AccountInfo->ReqOrderNum);
}
void ItsEngine::ItsHandleCancelOrder(int sessionID, ItsInsertOrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);
	if (!m_LoginStatus)
	{
		m_MdbSubscriber->ReqLogin();
		return SendResponse(sessionID, field->SequenceNo, "-1", "Offer not Login");
	}

	auto order = GetOrder(field->OrderLocalID, field->TradingDay, field->OrderSysID);
	if (!order)
	{
		static char buff[256];
		sprintf(buff, "Cannot find Order for TradingDay:%s, OrderSysID:%s, OrderLocalID:%s", field->TradingDay.c_str(), field->OrderSysID.c_str(), field->OrderLocalID.c_str());
		WRITE_LOG(LogLevel::Warning, "%s", buff);
	}

	auto orderCancel = new OrderCancel();
	orderCancel->TradingDay = GetLocalDate();
	orderCancel->AccountID = "";
	orderCancel->ExchangeID = field->ExchangeID;
	orderCancel->InstrumentID = field->InstrumentID;
	orderCancel->OrderLocalID = GetNextOrderLocalID(field->TradingDay);
	if (!order)
	{
		orderCancel->OrigOrderLocalID = field->OrderLocalID;
		orderCancel->OrderSysID = field->OrderSysID;
	}
	else
	{
		orderCancel->OrigOrderLocalID = order->OrderLocalID;
		orderCancel->OrderSysID = order->OrderSysID;
	}
	orderCancel->Direction = ConvertToDirection(field->Direction);
	orderCancel->OrderRef = field->OrderRef;
	orderCancel->FrontID = field->FrontID;
	orderCancel->SessionID = atoi(field->SessionID.c_str());
	orderCancel->ErrorID = 0;
	orderCancel->ErrorMsg = "";
	orderCancel->InsertDate = field->TradingDay;
	orderCancel->CancelDate = GetLocalDate();

	AddOrderCancel(orderCancel);
	SendResponse(sessionID, field->SequenceNo);
	m_MdbSubscriber->ReqInsertOrderCancel(orderCancel);

	m_Sqlite->OnOrderCancel(orderCancel);
	m_Sqlite->OnItsInsertOrderCancel(field);

	m_OfferDlg->UpdateReqCancelNum(m_AccountInfo->AccountID, ++m_AccountInfo->ReqCancelNum);

	if (order->OrderStatus == OrderStatus::Canceled || order->OrderStatus == OrderStatus::AllTraded || order->OrderStatus == OrderStatus::PartTradedCanceled || order->OrderStatus == OrderStatus::Error)
	{
		PushOrder(order);
		if (order->OrderStatus == OrderStatus::AllTraded || order->OrderStatus == OrderStatus::PartTradedCanceled)
		{
			PushTradeOfOrder(order);
		}
	}
}

void ItsEngine::PushOrder(Order* order)
{
	ItsOrder* itsOrder = new ItsOrder();
	itsOrder->ProtocolType = "B";
	itsOrder->Command = std::to_string(CMS_CID_BROADCAST_MA_ORDER);
	itsOrder->ChannelID = m_ChannelID;
	itsOrder->ExchangeID = order->ExchangeID;
	itsOrder->InstrumentID = order->InstrumentID;
	itsOrder->OrderRef = "";
	itsOrder->InsertTime = order->InsertTime;
	itsOrder->CancelTime = order->CancelTime;
	itsOrder->OrderSysID = order->OrderSysID;
	itsOrder->StatusMsg = order->ErrorMsg;
	itsOrder->Direction = (char)order->Direction;
	itsOrder->CombOffsetFlag = (char)order->OffsetFlag;
	itsOrder->CombHedgeFlag = (char)order->HedgeFlag;
	itsOrder->OrderPriceType = (char)order->OrderPriceType;
	itsOrder->OrderStatus = (char)order->OrderStatus;
	itsOrder->ForceCloseReason = (char)order->ForceCloseReason;
	itsOrder->RequestID = order->RequestID;
	itsOrder->FrontID = order->FrontID;
	itsOrder->SessionID = std::to_string(order->SessionID);
	itsOrder->OrderLocalID = order->OrderLocalID;
	itsOrder->VolumeTotalOriginal = std::to_string(order->Volume);
	itsOrder->VolumeTraded = std::to_string(order->VolumeTraded);
	itsOrder->InsertDate = order->InsertDate;
	itsOrder->TradingDay = order->InsertDate;
	itsOrder->LimitPrice = std::to_string(order->Price);
	itsOrder->IsLocalOrder = (char)order->IsLocalOrder;
	itsOrder->UserProductInfo = order->UserProductInfo;
	itsOrder->TimeCondition = (char)order->TimeCondition;
	itsOrder->GTDDate = order->GTDDate;
	itsOrder->VolumeCondition = (char)order->VolumeCondition;
	itsOrder->MinVolume = order->MinVolume;
	itsOrder->ContingentCondition = (char)order->ContingentCondition;
	itsOrder->StopPrice = std::to_string(order->StopPrice);
	itsOrder->IsSwapOrder = std::to_string(order->IsSwapOrder);

	SendUdp(itsOrder);
	itsOrder->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);
	m_Sqlite->OnItsRtnOrder(itsOrder);
}
void ItsEngine::PushTrade(Trade* field)
{
	ItsTrade* itsTrade = new ItsTrade();
	itsTrade->ProtocolType = "B";
	itsTrade->Command = std::to_string(CMS_CID_BROADCAST_MA_TRADE);
	itsTrade->ChannelID = m_ChannelID;
	itsTrade->ExchangeID = field->ExchangeID;
	itsTrade->InstrumentID = field->InstrumentID;
	itsTrade->OrderRef = "";
	itsTrade->OrderSysID = field->OrderSysID;
	itsTrade->TradeTime = field->TradeTime;
	itsTrade->TradeID = field->TradeID;
	itsTrade->Direction = (char)field->Direction;
	itsTrade->OffsetFlag = (char)field->OffsetFlag;
	itsTrade->HedgeFlag = (char)field->HedgeFlag;
	itsTrade->OrderLocalID = field->OrderLocalID;
	itsTrade->Volume = std::to_string(field->Volume);
	itsTrade->TradeDate = field->TradeDate;
	itsTrade->TradingDay = field->TradeDate;
	itsTrade->Price = std::to_string(field->Price);
	itsTrade->TradeType = (char)TradeType::Common;
	itsTrade->ExchangeTradeID = field->TradeID;

	SendUdp(itsTrade);
	itsTrade->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);
	m_Sqlite->OnItsRtnTrade(itsTrade);
}
void ItsEngine::PushTradeOfOrder(Order* order)
{
	for (auto it = find_if(m_Trades.begin(), m_Trades.end(), [&](Trade* trade) { return trade->OrderSysID == order->OrderSysID; });
		it != m_Trades.end(); 
		it = find_if(++it, m_Trades.end(), [&](Trade* trade) { return trade->OrderSysID == order->OrderSysID; }))
	{
		PushTrade(*it);
	}
}
void ItsEngine::PushOrderCancel(OrderCancel* orderCancel)
{
	ItsErrRtnOrderCancel* itsErrRtnOrderCancel = new ItsErrRtnOrderCancel();
	itsErrRtnOrderCancel->ProtocolType = "B";
	itsErrRtnOrderCancel->Command = std::to_string(CMS_CID_BROADCAST_MA_CANCEL_FAILED);
	itsErrRtnOrderCancel->ChannelID = m_ChannelID;
	itsErrRtnOrderCancel->OrderLocalID = orderCancel->OrigOrderLocalID;
	itsErrRtnOrderCancel->OrderRef = orderCancel->OrderRef;
	itsErrRtnOrderCancel->FrontID = orderCancel->FrontID;
	itsErrRtnOrderCancel->SessionID = std::to_string(orderCancel->SessionID);
	itsErrRtnOrderCancel->ExchangeID = orderCancel->ExchangeID;
	itsErrRtnOrderCancel->OrderSysID = orderCancel->OrderSysID;
	itsErrRtnOrderCancel->ErrorID = std::to_string(orderCancel->ErrorID);
	itsErrRtnOrderCancel->ErrorMsg = orderCancel->ErrorMsg;
	itsErrRtnOrderCancel->TradingDay = orderCancel->CancelDate;

	SendUdp(itsErrRtnOrderCancel);
	itsErrRtnOrderCancel->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);
	m_Sqlite->OnItsRtnOrderCancel(itsErrRtnOrderCancel);
}


string ItsEngine::GetNextOrderLocalID(const string& tradingDay)
{
	auto it = find_if(m_OrderSequences.begin(), m_OrderSequences.end(), [&](OrderSequence* orderSequence) {
		return orderSequence->TradingDay == tradingDay;
		});
	auto orderLocalID = 0;
	if (it == m_OrderSequences.end())
	{
		orderLocalID = 1;
		auto orderSequence = new OrderSequence();
		orderSequence->TradingDay = tradingDay;
		orderSequence->MaxOrderLocalID = orderLocalID;
		m_OrderSequences.insert(orderSequence);
		m_Sqlite->OnOrderSequence(orderSequence);
	}
	else
	{
		orderLocalID = ++((*it)->MaxOrderLocalID);
		m_Sqlite->OnOrderSequence(*it);
	}
	
	auto date = tradingDay.substr(4, 4);
	sprintf(m_OrderLocalIDBuff, "%s%06d", date.c_str(), orderLocalID);
	return string(m_OrderLocalIDBuff);
}
void ItsEngine::AddOrder(Order* order)
{
	std::lock_guard<std::mutex> guard(m_OrdersMutex);
	m_Orders.insert(order);
}
Order* ItsEngine::GetOrder(const string& orderLocalID, const string& tradingDay, const string& orderSysID)
{
	Order* order = nullptr;
	std::lock_guard<std::mutex> guard(m_OrdersMutex);
	if (!orderLocalID.empty())
	{
		order = GetOrderFromOrderLocalID(orderLocalID);
	}
	if (!order && !tradingDay.empty() && !orderSysID.empty())
	{
		order = GetOrderFromOrderSysID(tradingDay, orderSysID);
	}
	return order;
}
Order* ItsEngine::GetOrderFromOrderSysID(const string& tradingDay, const string& orderSysID)
{
	auto it = find_if(m_Orders.begin(), m_Orders.end(), [&](Order* order) {
		return order->OrderSysID == orderSysID;
		});
	if (it == m_Orders.end())
	{
		return nullptr;
	}
	return *it;
}
Order* ItsEngine::GetOrderFromOrderLocalID(const string& orderLocalID)
{
	auto it = find_if(m_Orders.begin(), m_Orders.end(), [&](Order* order) {
		return order->OrderLocalID == orderLocalID;
		});
	if (it == m_Orders.end())
	{
		return nullptr;
	}
	return *it;
}
void ItsEngine::AddOrderCancel(OrderCancel* orderCancel)
{
	m_OrderCancels.insert(orderCancel);
}
OrderCancel* ItsEngine::GetOrderCancelFromOrderLocalID(const string& orderLocalID)
{
	std::lock_guard<std::mutex> guard(m_OrderCancelsMutex);
	auto it = find_if(m_OrderCancels.begin(), m_OrderCancels.end(), [&](OrderCancel* orderCancel) {
		return orderCancel->OrderLocalID == orderLocalID;
		});
	if (it == m_OrderCancels.end())
	{
		return nullptr;
	}
	return *it;
}
bool ItsEngine::CheckAndAddTrade(Trade* trade)
{
	auto it = find_if(m_Trades.begin(), m_Trades.end(), [&](Trade* item) {
		return item->TradeDate == trade->TradeDate && item->OrderSysID == trade->OrderSysID && item->TradeID == trade->TradeID;
		});
	if (it != m_Trades.end())
	{
		trade->ToString(m_LogBuff, BuffSize);
		WRITE_LOG(LogLevel::Warning, "Trade already exist. %s", m_LogBuff);
		delete trade;
		return false;
	}
	m_Trades.insert(trade);
	m_Sqlite->OnTrade(trade);
	return true;
}

void ItsEngine::SendResponse(int sessionID, const string& sequenceNo, const string& errorID, const string& errorMsg)
{
	ItsRspOrder itsRspOrder;
	itsRspOrder.ProtocolType = "A";
	itsRspOrder.SequenceNo = sequenceNo;
	itsRspOrder.Reserve1 = "1";
	itsRspOrder.Reserve2 = "0";
	itsRspOrder.ErrorID = errorID;
	itsRspOrder.ErrorMsg = errorMsg;

	
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	tcpEvent->EventID = EventSend;
	tcpEvent->SessionID = sessionID;
	auto len = (unsigned short)itsRspOrder.ToStream(tcpEvent->Buff + sizeof(unsigned short), BuffSize - sizeof(unsigned short));
	*(unsigned short*)tcpEvent->Buff = len;
	tcpEvent->Length = len + sizeof(unsigned short);
	m_Tcp->Send(tcpEvent);
}
