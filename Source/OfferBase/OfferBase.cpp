#include "OfferBase.h"
#include "Logger.h"


OfferBase::OfferBase(const char* name)
	:ThreadBase(name), m_MdbPublisher(nullptr)
{
}
void OfferBase::RegisterMdbPublisher(MdbPublisher* mdbPublisher)
{
	m_MdbPublisher = mdbPublisher;
}
void OfferBase::ReqInsertOrder(Order* order)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventInsertOrder;
	myEvent->Field = order;
	OnEvent(myEvent);
}
void OfferBase::ReqInsertOrderCancel(OrderCancel* orderCancel)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventInsertOrderCancel;
	myEvent->Field = orderCancel;
	OnEvent(myEvent);
}
void OfferBase::ReqQryOrder()
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventQryOrder;
	myEvent->Field = nullptr;
	OnEvent(myEvent);
}
void OfferBase::ReqQryTrade()
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventQryTrade;
	myEvent->Field = nullptr;
	OnEvent(myEvent);
}
void OfferBase::OnRtnOrder(Order* order)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnOrder;
	myEvent->Field = order;
	OnEvent(myEvent);
}
void OfferBase::OnRtnTrade(Trade* trade)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnTrade;
	myEvent->Field = trade;
	OnEvent(myEvent);
}
void OfferBase::OnErrRtnOrderCancel(OrderCancel* orderCancel)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnErrRtnOrderCancel;
	myEvent->Field = orderCancel;
	OnEvent(myEvent);
}


void OfferBase::HandleEvent()
{
	MyEvent* myEvent = nullptr;
	while (myEvent = (MyEvent*)GetEvent())
	{
		switch (myEvent->EventID)
		{
		case EventInsertOrder:
		{
			HandleInsertOrder((Order*)myEvent->Field);
			break;
		}
		case EventInsertOrderCancel:
		{
			HandleInsertOrderCancel((OrderCancel*)myEvent->Field);
			break;
		}
		case EventQryOrder:
		{
			HandleQryOrder();
			break;
		}
		case EventQryTrade:
		{
			HandleQryTrade();
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
		}
		default:
			WRITE_LOG(LogLevel::Warning, "UnHandled Event. EventID:[%s]", myEvent->EventID);
			break;
		}
		myEvent->Free();
	}
}