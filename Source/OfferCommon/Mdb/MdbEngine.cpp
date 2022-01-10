#include "MdbEngine.h"
#include  "Logger.h"
#include "TcpSelectClient.h"
#include "MemCacheTemplateSingleton.h"
#include "DataType.h"
#include "Event.h"
#include "ItsUtility.h"
#include "command_id.h"
#include "Utility.h"
#include "TimeUtility.h"
#include "Mdb.h"

using std::to_string;


MdbEngine::MdbEngine(const std::string& channelID)
	:ThreadBase("MdbEngine"), m_ItsPublisher(nullptr), m_MdbSubscriber(nullptr), m_Mdb(nullptr), m_ChannelID(channelID)
{
	m_LogBuff = new char[BuffSize];
}
MdbEngine::~MdbEngine()
{
	if (m_LogBuff)
	{
		delete[] m_LogBuff;
	}
	m_LogBuff = nullptr;
	sqlite3_close(m_Mdb);
}

void MdbEngine::RegisterItsPublisher(ItsPublisher* itsPublisher)
{
	m_ItsPublisher = itsPublisher;
}
void MdbEngine::RegisterSubscriber(MdbSubscriber* mdbSubscriber)
{
	m_MdbSubscriber = mdbSubscriber;
}
bool MdbEngine::Init(const char* dbName)
{
	sqlite3_open(dbName, &m_Mdb);
	Mdb::GetInstance().SetDB(m_Mdb);
	Mdb::GetInstance().SetCallback(this);
	Mdb::GetInstance().CreateAllTables();
	Mdb::GetInstance().SelectAllTables();

	return true;
}
void MdbEngine::ReqInsertOrder(int sessionID, ItsInsertOrder* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventInsertOrder;
	myEvent->NumParams.push_back(sessionID);
	myEvent->Field = field;
	OnEvent(myEvent);
}
void MdbEngine::ReqInsertOrderCancel(int sessionID, ItsInsertOrderCancel* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventInsertOrderCancel;
	myEvent->NumParams.push_back(sessionID);
	myEvent->Field = field;
	OnEvent(myEvent);
}
void MdbEngine::OnRtnOrder(Order* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnOrder;
	myEvent->Field = field;
	OnEvent(myEvent);
}
void MdbEngine::OnRtnTrade(Trade* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnTrade;
	myEvent->Field = field;
	OnEvent(myEvent);
}
void MdbEngine::OnErrRtnOrderCancel(OrderCancel* field)
{
	auto myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnErrRtnOrderCancel;
	myEvent->Field = field;
	OnEvent(myEvent);
}

void MdbEngine::SelectMdbOrderSequenceCallback(OrderSequence* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbOrderSequenceCallback %s", m_LogBuff);

	m_OrderSequences.insert(field);
}
void MdbEngine::SelectMdbOrderCallback(Order* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbOrderCallback %s", m_LogBuff);

	m_Orders.insert(field);
}
void MdbEngine::SelectMdbOrderCancelCallback(OrderCancel* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbOrderCancelCallback %s", m_LogBuff);

	m_OrderCancels.insert(field);
}
void MdbEngine::SelectMdbTradeCallback(Trade* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SelectMdbTradeCallback %s", m_LogBuff);

	m_Trades.insert(field);
}

void MdbEngine::Run()
{
	CheckEvent();
	HandleEvent();
}
void MdbEngine::HandleEvent()
{
	MyEvent* myEvent = nullptr;
	while (myEvent = (MyEvent*)GetEvent())
	{
		switch (myEvent->EventID)
		{
		case EventInsertOrder:
		{
			auto sessionID = myEvent->NumParams[0];
			HandleInsertOrder(sessionID, (ItsInsertOrder*)myEvent->Field);
			break;
		}
		case EventInsertOrderCancel:
		{
			auto sessionID = myEvent->NumParams[0];
			HandleInsertOrderCancel(sessionID, (ItsInsertOrderCancel*)myEvent->Field);
			break;
		}
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
void MdbEngine::HandleInsertOrder(int sessionID, ItsInsertOrder* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "%s", m_LogBuff);

	Order* order = new Order();
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
void MdbEngine::HandleInsertOrderCancel(int sessionID, ItsInsertOrderCancel* field)
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

	auto orderCancel = new OrderCancel();
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
	delete field;
}
void MdbEngine::SendResponse(int sessionID, const string& sequenceNo, const string& errorID, const string& errorMsg)
{
	ItsRspOrder itsRspOrder;
	itsRspOrder.ProtocolType = "A";
	itsRspOrder.SequenceNo = sequenceNo;
	itsRspOrder.Reserve1 = "1";
	itsRspOrder.Reserve2 = "0";
	itsRspOrder.ErrorID = errorID;
	itsRspOrder.ErrorMsg = errorMsg;

	m_ItsPublisher->OnRspOrder(sessionID, &itsRspOrder);
	
	itsRspOrder.ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "SendResponse: %s", m_LogBuff);
}
void MdbEngine::HandleRtnOrder(Order* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleRtnOrder: %s", m_LogBuff);
	auto order = GetOrder(field->OrderLocalID, field->InsertDate, field->OrderSysID);
	if (order != nullptr)
	{
		order->OrderSysID = field->OrderSysID;
		if (field->VolumeTraded > order->VolumeTraded)
		{
			order->VolumeTraded = field->VolumeTraded;
		}
		order->OrderStatus = field->OrderStatus;
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
	itsOrder.Command = to_string(CMS_CID_BROADCAST_MA_ORDER);
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
	itsOrder.SessionID = to_string(order->SessionID);
	itsOrder.BrokerOrderID = order->OrderLocalID;
	itsOrder.VolumeTotalOriginal = to_string(order->Volume);
	itsOrder.VolumeTraded = to_string(order->VolumeTraded);
	itsOrder.InsertDate = order->InsertDate;
	itsOrder.TradingDay = order->InsertDate;
	itsOrder.LimitPrice = to_string(order->Price);
	itsOrder.IsLocalOrder = (char)order->IsLocalOrder;
	itsOrder.UserProductInfo = order->UserProductInfo;
	itsOrder.TimeCondition = (char)order->TimeCondition;
	itsOrder.GTDDate = order->GTDDate;
	itsOrder.VolumeCondition = (char)order->VolumeCondition;
	itsOrder.MinVolume = order->MinVolume;
	itsOrder.ContingentCondition = (char)order->ContingentCondition;
	itsOrder.StopPrice = to_string(order->StopPrice);
	itsOrder.IsSwapOrder = to_string(order->IsSwapOrder);

	m_ItsPublisher->OnRtnOrder(&itsOrder);
}
void MdbEngine::HandleRtnTrade(Trade* field)
{
	field->ToString(m_LogBuff, BuffSize);
	WRITE_LOG(LogLevel::Info, "HandleRtnTrade: %s", m_LogBuff);

	if (!CheckAndAddTrade(field))
	{
		return;
	}

	ItsTrade itsTrade;
	itsTrade.ProtocolType = "B";
	itsTrade.Command = to_string(CMS_CID_BROADCAST_MA_TRADE);
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
	itsTrade.Volume = to_string(field->Volume);
	itsTrade.TradeDate = field->TradeDate;
	itsTrade.TradingDay = field->TradeDate;
	itsTrade.Price = to_string(field->Price);
	itsTrade.TradeType = (char)TradeType::Common;
	itsTrade.ExchangeTradeID = field->TradeID;

	m_ItsPublisher->OnRtnTrade(&itsTrade);
}
void MdbEngine::HandleErrRtnOrderCancel(OrderCancel* field)
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
	itsErrRtnOrderCancel.Command = to_string(CMS_CID_BROADCAST_MA_CANCEL_FAILED);
	itsErrRtnOrderCancel.ChannelID = m_ChannelID;
	itsErrRtnOrderCancel.BrokerOrderID = orderCancel->OrigOrderLocalID;
	itsErrRtnOrderCancel.OrderRef = orderCancel->OrderRef;
	itsErrRtnOrderCancel.FrontID = orderCancel->FrontID;
	itsErrRtnOrderCancel.SessionID = to_string(orderCancel->SessionID);
	itsErrRtnOrderCancel.ExchangeID = orderCancel->ExchangeID;
	itsErrRtnOrderCancel.OrderSysID = orderCancel->OrderSysID;
	itsErrRtnOrderCancel.ErrorID = to_string(orderCancel->ErrorID);
	itsErrRtnOrderCancel.ErrorMsg = orderCancel->ErrorMsg;
	itsErrRtnOrderCancel.TradingDay = orderCancel->CancelDate;
	m_ItsPublisher->OnErrRtnOrderCancel(&itsErrRtnOrderCancel);
}


string MdbEngine::GetNextOrderLocalID(const string& tradingDay)
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
	sprintf(m_OrderLocalIDBuff, "%s%08d", tradingDay.c_str(), orderLocalID);
	return string(m_OrderLocalIDBuff);
}
Order* MdbEngine::GetOrder(const string& orderLocalID, const string& tradingDay, const string& orderSysID)
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
Order* MdbEngine::GetOrderFromOrderSysID(const string& tradingDay, const string& orderSysID)
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
Order* MdbEngine::GetOrderFromOrderLocalID(const string& orderLocalID)
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
OrderCancel* MdbEngine::GetOrderCancelFromOrderLocalID(const string& orderLocalID)
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
bool MdbEngine::CheckAndAddTrade(Trade* trade)
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
