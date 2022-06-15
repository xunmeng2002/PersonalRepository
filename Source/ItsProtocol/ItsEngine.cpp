#include "ItsEngine.h"
#include "Logger.h"
#include "ItsUtility.h"
#include "ItsFields.h"
#include "command_id.h"
#include "TimeUtility.h"
#include "Event.h"


ItsEngine::ItsEngine(const std::string& channelID, const std::string& tcpBindIP, const std::string& tcpBindPort, const std::string& udpIP, const std::string& udpPort)
	:ThreadBase("ItsEngine"), m_ItsMdb(nullptr), m_Mdb(nullptr), m_MdbSubscriber(nullptr), m_ChannelID(channelID), m_OrderLocalIDBuff{ 0 }, m_UdpRemoteIP(udpIP), m_UdpRemotePort(udpPort)
{
	m_LogBuff = new char[BuffSize];
	m_Tcp = new TcpSelectServer();
	((TcpSelectServer*)m_Tcp)->SetBindAddressInfo(tcpBindIP.c_str(), tcpBindPort.c_str());
	m_Tcp->Subscriber(this);

	m_UdpClient = new UdpClient();
	m_UdpClient->SetRemoteAddress(udpIP.c_str(), udpPort.c_str());
}
ItsEngine::~ItsEngine()
{
	delete m_UdpClient;
	m_UdpClient = nullptr;
	
	delete m_Tcp;
	m_Tcp = nullptr;

	delete[] m_LogBuff;
	m_LogBuff = nullptr;
	sqlite3_close(m_ItsMdb);
	sqlite3_close(m_Mdb);
}
void ItsEngine::RegisterSubscriber(MdbSubscriber* mdbSubscriber)
{
	m_MdbSubscriber = mdbSubscriber;
}
bool ItsEngine::Init()
{
	sqlite3_open("Its.db", &m_ItsMdb);
	ItsMdb::GetInstance().SetDB(m_ItsMdb);
	ItsMdb::GetInstance().SetCallback(this);
	ItsMdb::GetInstance().CreateAllTables();
	//ItsMdb::GetInstance().SelectAllTables();

	sqlite3_open("Mdb.db", &m_Mdb);
	Mdb::GetInstance().SetDB(m_ItsMdb);
	Mdb::GetInstance().SetCallback(this);
	Mdb::GetInstance().CreateAllTables();
	Mdb::GetInstance().SelectAllTables();

	if (!m_UdpClient->Init(false))
	{
		return false;
	}
	return m_Tcp->Init();
}


void ItsEngine::Run()
{
	m_Tcp->HandleTcpEvent();
	CheckEvent();
	HandleEvent();
	HandleRecvData();
}
void ItsEngine::HandleEvent()
{
	MyEvent* myEvent = nullptr;
	while (myEvent = (MyEvent*)GetEvent())
	{
		switch (myEvent->EventID)
		{
		case EventOnRtnOrder:
		{
			HandleRtnOrder((Order*)myEvent->Field);
			break;
		}
		case EventOnRtnTrade:
		{
			HandleRtnTrade((Trade*)myEvent->Field);
			break;
		}
		case EventOnErrRtnOrderCancel:
		{
			HandleErrRtnOrderCancel((OrderCancel*)myEvent->Field);
			break;
		}
		default:
			break;
		}
		myEvent->Free();
	}
}

void ItsEngine::OnConnect(int sessionID, const char* ip, const char* port)
{
	m_SessionIDs.insert(sessionID);
}
void ItsEngine::OnDisConnect(int sessionID, const char* ip, const char* port)
{
	m_SessionIDs.erase(sessionID);
}
void ItsEngine::OnRecv(TcpEvent* tcpEvent)
{
	m_RecvDatas.push_back(tcpEvent);
}

void ItsEngine::OnRtnOrder(Order* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnOrder;
	myEvent->Field = field;
	OnEvent(myEvent);
}
void ItsEngine::OnRtnTrade(Trade* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnTrade;
	myEvent->Field = field;
	OnEvent(myEvent);
}
void ItsEngine::OnErrRtnOrderCancel(OrderCancel* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnErrRtnOrderCancel;
	myEvent->Field = field;
	OnEvent(myEvent);
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

	m_Orders.insert(field);
}
void ItsEngine::SelectMdbOrderCancelCallback(OrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbOrderCancelCallback %s", m_LogBuff);

	m_OrderCancels.insert(field);
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
void ItsEngine::ItsHandleInsertOrder(int sessionID, ItsInsertOrder* itsInsertOrder)
{
	auto it = find_if(m_InsertOrderKeys.begin(), m_InsertOrderKeys.end(), [&](ItsInsertOrderKey* key) {
		return key->TradingDay == itsInsertOrder->TradingDay && key->RequestID == itsInsertOrder->RequestID;
		});
	if (it != m_InsertOrderKeys.end())
	{
		SendResponse(sessionID, itsInsertOrder->SequenceNo, "0", "重复报单");
		return;
	}
	m_InsertOrderKeys.insert(new ItsInsertOrderKey({ itsInsertOrder->TradingDay, itsInsertOrder->RequestID }));
	ItsMdb::GetInstance().InsertRecord(itsInsertOrder);
	HandleInsertOrder(sessionID, itsInsertOrder);
}
void ItsEngine::ItsHandleCancelOrder(int sessionID, ItsInsertOrderCancel* itsInsertOrderCancel)
{
	ItsMdb::GetInstance().InsertRecord(itsInsertOrderCancel);
	HandleCancelOrder(sessionID, itsInsertOrderCancel);
}

void ItsEngine::HandleInsertOrder(int sessionID, ItsInsertOrder* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);

	Order* order = new Order();
	order->TradingDay = GetLocalDate();
	order->AccountID = field->AccountID;
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
	order->MinVolume = atoi(field->MinVolume.c_str());
	order->ContingentCondition = ContingentCondition::Immediately;
	order->StopPrice = 0.0;
	order->IsSwapOrder = 0;

	Mdb::GetInstance().InsertRecord(order);
	m_Orders.insert(order);
	m_MdbSubscriber->ReqInsertOrder(order);
	SendResponse(sessionID, field->SequenceNo);
	delete field;
}
void ItsEngine::HandleCancelOrder(int sessionID, ItsInsertOrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);
	auto order = GetOrder(field->BrokerOrderID, field->TradingDay, field->OrderSysID);
	if (!order)
	{
		static char buff[256];
		sprintf(buff, "找不到报单，委托日期:[%s], 交易所报单编号:[%s]，经纪公司报单编号:[%s]", field->TradingDay.c_str(), field->OrderSysID.c_str(), field->BrokerOrderID.c_str());
		SendResponse(sessionID, field->SequenceNo, "-1", buff);

		field->ToString(m_LogBuff, BuffSize);
		WRITE_LOG(LogLevel::Warning, "Cannot find Order While Cancel Order. %s", m_LogBuff);
	}
	else
	{
		auto orderCancel = new OrderCancel();
		orderCancel->TradingDay = GetLocalDate();
		orderCancel->AccountID = "";
		orderCancel->ExchangeID = field->ExchangeID;
		orderCancel->InstrumentID = field->InstrumentID;
		orderCancel->OrderLocalID = GetNextOrderLocalID(field->TradingDay);
		orderCancel->OrigOrderLocalID = order->OrderLocalID;
		orderCancel->OrderSysID = order->OrderSysID;
		orderCancel->Direction = ConvertToDirection(field->Direction);
		orderCancel->OrderRef = field->OrderRef;
		orderCancel->FrontID = field->FrontID;
		orderCancel->SessionID = atoi(field->SessionID.c_str());
		orderCancel->ErrorID = 0;
		orderCancel->ErrorMsg = "";
		orderCancel->InsertDate = field->TradingDay;
		orderCancel->CancelDate = GetLocalDate();

		Mdb::GetInstance().InsertRecord(orderCancel);
		m_OrderCancels.insert(orderCancel);
		m_MdbSubscriber->ReqInsertOrderCancel(orderCancel);
		SendResponse(sessionID, field->SequenceNo);
	}
}
void ItsEngine::HandleRtnOrder(Order* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleRtnOrder: %s", m_LogBuff);
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
		order->StatusMsg = field->StatusMsg;
		order->ExchangeInsertDate = field->ExchangeInsertDate;
		order->ExchangeInsertTime = field->ExchangeInsertTime;
		order->CancelDate = field->CancelDate;
		order->CancelTime = field->CancelTime;
		order->IsLocalOrder = IsLocalOrder::Local;
		delete field;
	}
	else
	{
		order = field;
		order->IsLocalOrder = IsLocalOrder::Others;
		m_Orders.insert(order);

		order->ToString(m_LogBuff, BuffSize);
		WRITE_LOG(LogLevel::Warning, "Other Source Order. %s", m_LogBuff);
	}
	Mdb::GetInstance().InsertRecord(order);

	ItsOrder itsOrder;
	itsOrder.ProtocolType = "B";
	itsOrder.Command = std::to_string(CMS_CID_BROADCAST_MA_ORDER);
	itsOrder.ChannelID = m_ChannelID;
	itsOrder.ExchangeID = order->ExchangeID;
	itsOrder.InstrumentID = order->InstrumentID;
	itsOrder.OrderRef = "";
	itsOrder.InsertTime = order->InsertTime;
	itsOrder.CancelTime = order->CancelTime;
	itsOrder.OrderSysID = order->OrderSysID;
	itsOrder.StatusMsg = order->StatusMsg;
	itsOrder.Direction = (char)order->Direction;
	itsOrder.CombOffsetFlag = (char)order->OffsetFlag;
	itsOrder.CombHedgeFlag = (char)order->HedgeFlag;
	itsOrder.OrderPriceType = (char)order->OrderPriceType;
	itsOrder.OrderStatus = (char)order->OrderStatus;
	itsOrder.ForceCloseReason = (char)order->ForceCloseReason;
	itsOrder.RequestID = order->RequestID;
	itsOrder.FrontID = order->FrontID;
	itsOrder.SessionID = std::to_string(order->SessionID);
	itsOrder.BrokerOrderID = order->OrderLocalID;
	itsOrder.VolumeTotalOriginal = std::to_string(order->Volume);
	itsOrder.VolumeTraded = std::to_string(order->VolumeTraded);
	itsOrder.InsertDate = order->InsertDate;
	itsOrder.TradingDay = order->InsertDate;
	itsOrder.LimitPrice = std::to_string(order->Price);
	itsOrder.IsLocalOrder = (char)order->IsLocalOrder;
	itsOrder.UserProductInfo = order->UserProductInfo;
	itsOrder.TimeCondition = (char)order->TimeCondition;
	itsOrder.GTDDate = order->GTDDate;
	itsOrder.VolumeCondition = (char)order->VolumeCondition;
	itsOrder.MinVolume = order->MinVolume;
	itsOrder.ContingentCondition = (char)order->ContingentCondition;
	itsOrder.StopPrice = std::to_string(order->StopPrice);
	itsOrder.IsSwapOrder = std::to_string(order->IsSwapOrder);

	SendUdp(&itsOrder);
}
void ItsEngine::HandleRtnTrade(Trade* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleRtnTrade: %s", m_LogBuff);

	CheckAndAddTrade(field);

	ItsTrade itsTrade;
	itsTrade.ProtocolType = "B";
	itsTrade.Command = std::to_string(CMS_CID_BROADCAST_MA_TRADE);
	itsTrade.ChannelID = m_ChannelID;
	itsTrade.ExchangeID = field->ExchangeID;
	itsTrade.InstrumentID = field->InstrumentID;
	itsTrade.OrderRef = "";
	itsTrade.OrderSysID = field->OrderSysID;
	itsTrade.TradeTime = field->TradeTime;
	itsTrade.TradeID = field->TradeID;
	itsTrade.Direction = (char)field->Direction;
	itsTrade.OffsetFlag = (char)field->OffsetFlag;
	itsTrade.HedgeFlag = (char)field->HedgeFlag;
	itsTrade.BrokerOrderID = field->OrderLocalID;
	itsTrade.Volume = std::to_string(field->Volume);
	itsTrade.TradeDate = field->TradeDate;
	itsTrade.TradingDay = field->TradeDate;
	itsTrade.Price = std::to_string(field->Price);
	itsTrade.TradeType = (char)TradeType::Common;
	itsTrade.ExchangeTradeID = field->TradeID;

	SendUdp(&itsTrade);
}
void ItsEngine::HandleErrRtnOrderCancel(OrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleErrRtnOrderCancel: %s", m_LogBuff);

	auto orderCancel = GetOrderCancelFromOrderLocalID(field->OrderLocalID);
	if (orderCancel != nullptr)
	{
		orderCancel->ErrorID = field->ErrorID;
		orderCancel->ErrorMsg = field->ErrorMsg;
		delete field;
	}
	else
	{
		orderCancel = field;
		orderCancel->ToString(m_LogBuff, BuffSize);
		WRITE_LOG(LogLevel::Warning, "Other Source OrderCancel. %s", m_LogBuff);

		m_OrderCancels.insert(orderCancel);
	}
	Mdb::GetInstance().InsertRecord(orderCancel);

	ItsErrRtnOrderCancel itsErrRtnOrderCancel;
	itsErrRtnOrderCancel.ProtocolType = "B";
	itsErrRtnOrderCancel.Command = std::to_string(CMS_CID_BROADCAST_MA_CANCEL_FAILED);
	itsErrRtnOrderCancel.ChannelID = m_ChannelID;
	itsErrRtnOrderCancel.BrokerOrderID = orderCancel->OrigOrderLocalID;
	itsErrRtnOrderCancel.OrderRef = orderCancel->OrderRef;
	itsErrRtnOrderCancel.FrontID = orderCancel->FrontID;
	itsErrRtnOrderCancel.SessionID = std::to_string(orderCancel->SessionID);
	itsErrRtnOrderCancel.ExchangeID = orderCancel->ExchangeID;
	itsErrRtnOrderCancel.OrderSysID = orderCancel->OrderSysID;
	itsErrRtnOrderCancel.ErrorID = std::to_string(orderCancel->ErrorID);
	itsErrRtnOrderCancel.ErrorMsg = orderCancel->ErrorMsg;
	itsErrRtnOrderCancel.TradingDay = orderCancel->CancelDate;
	
	SendUdp(&itsErrRtnOrderCancel);
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
		Mdb::GetInstance().InsertRecord(orderSequence);
	}
	else
	{
		orderLocalID = ++((*it)->MaxOrderLocalID);
		Mdb::GetInstance().InsertRecord(*it);
	}
	auto date = tradingDay.substr(4, 4);
	sprintf(m_OrderLocalIDBuff, "%s%06d", date.c_str(), orderLocalID);
	return string(m_OrderLocalIDBuff);
}
Order* ItsEngine::GetOrder(const string& orderLocalID, const string& tradingDay, const string& orderSysID)
{
	Order* order = nullptr;
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
OrderCancel* ItsEngine::GetOrderCancelFromOrderLocalID(const string& orderLocalID)
{
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
		return false;
	}
	m_Trades.insert(trade);
	Mdb::GetInstance().InsertRecord(trade);
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
