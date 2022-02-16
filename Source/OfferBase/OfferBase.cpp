#include "OfferBase.h"
#include "Logger.h"


OfferBase::OfferBase(const char* name)
	:ThreadBase(name)
{
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
		default:
			WRITE_LOG(LogLevel::Warning, "UnHandled Event. EventID:[%s]", myEvent->EventID);
			break;
		}
		myEvent->Free();
	}
}