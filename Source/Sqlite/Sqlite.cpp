#include "Sqlite.h"
#include "ItsMdb.h"
#include "Mdb.h"
#include "ItsEngine.h"


Sqlite::Sqlite()
	:ThreadBase("Sqlite")
{
	sqlite3_open("Mdb.db", &m_SqliteDB);

	ItsMdb::GetInstance().SetDB(m_SqliteDB);
	Mdb::GetInstance().SetDB(m_SqliteDB);
}
Sqlite::~Sqlite()
{
	sqlite3_close(m_SqliteDB);
}
bool Sqlite::Init(ItsEngine* itsEngine)
{
	ItsMdb::GetInstance().SetCallback(itsEngine);
	ItsMdb::GetInstance().CreateAllTables();
	//ItsMdb::GetInstance().SelectAllTables();

	Mdb::GetInstance().SetCallback(itsEngine);
	Mdb::GetInstance().CreateAllTables();
	Mdb::GetInstance().SelectAllTables();
	return true;
}

void Sqlite::OnItsInsertOrder(ItsInsertOrder* itsInsertOrder)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventItsInsertOrder;
	myEvent->Field = itsInsertOrder;
	OnEvent(myEvent);
}
void Sqlite::OnItsInsertOrderCancel(ItsInsertOrderCancel* itsInsertOrderCancel)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventItsInsertOrderCancel;
	myEvent->Field = itsInsertOrderCancel;
	OnEvent(myEvent);
}
void Sqlite::OnItsRspOrder(ItsRspOrder* itsRspOrder)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventItsRspOrder;
	myEvent->Field = itsRspOrder;
	OnEvent(myEvent);
}
void Sqlite::OnItsRtnOrder(ItsOrder* itsOrder)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventItsRtnOrder;
	myEvent->Field = itsOrder;
	OnEvent(myEvent);
}
void Sqlite::OnItsRtnTrade(ItsTrade* itsTrade)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventItsRtnTrade;
	myEvent->Field = itsTrade;
	OnEvent(myEvent);
}
void Sqlite::OnItsRtnOrderCancel(ItsErrRtnOrderCancel* itsErrRtnOrderCancel)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventItsRtnOrderCancel;
	myEvent->Field = itsErrRtnOrderCancel;
	OnEvent(myEvent);
}

void Sqlite::OnOrderSequence(OrderSequence* orderSequence)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOrderSequence;
	myEvent->Field = orderSequence;
	OnEvent(myEvent);
}
void Sqlite::OnOrder(Order* order)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnOrder;
	myEvent->Field = order;
	OnEvent(myEvent);
}
void Sqlite::OnTrade(Trade* trade)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnTrade;
	myEvent->Field = trade;
	OnEvent(myEvent);
}
void Sqlite::OnOrderCancel(OrderCancel* orderCancel)
{
	MyEvent* myEvent = MyEvent::Allocate();
	myEvent->EventID = EventOnRtnOrderCancel;
	myEvent->Field = orderCancel;
	OnEvent(myEvent);
}

void Sqlite::HandleEvent()
{
	auto myEvent = (MyEvent*)GetEvent();
	if (myEvent == nullptr)
	{
		return;
	}
	switch (myEvent->EventID)
	{
	case EventItsInsertOrder:
	{
		ItsInsertOrder* itsInsertOrder = (ItsInsertOrder*)myEvent->Field;
		ItsMdb::GetInstance().InsertRecord(itsInsertOrder);
		break;
	}
	case EventItsInsertOrderCancel:
	{
		ItsInsertOrderCancel* itsInsertOrderCancel = (ItsInsertOrderCancel*)myEvent->Field;
		ItsMdb::GetInstance().InsertRecord(itsInsertOrderCancel);
		break;
	}
	case EventItsRspOrder:
	{
		ItsRspOrder* itsRspOrder = (ItsRspOrder*)myEvent->Field;
		ItsMdb::GetInstance().InsertRecord(itsRspOrder);
		break;
	}
	case EventItsRtnOrder:
	{
		ItsOrder* itsOrder = (ItsOrder*)myEvent->Field;
		ItsMdb::GetInstance().InsertRecord(itsOrder);
		break;
	}
	case EventItsRtnTrade:
	{
		ItsTrade* itsTrade = (ItsTrade*)myEvent->Field;
		ItsMdb::GetInstance().InsertRecord(itsTrade);
		break;
	}
	case EventItsRtnOrderCancel:
	{
		ItsErrRtnOrderCancel* itsErrRtnOrderCancel = (ItsErrRtnOrderCancel*)myEvent->Field;
		ItsMdb::GetInstance().InsertRecord(itsErrRtnOrderCancel);
		break;
	}


	case EventOrderSequence:
	{
		OrderSequence* orderSequence = (OrderSequence*)myEvent->Field;
		Mdb::GetInstance().InsertRecord(orderSequence);
		myEvent->Field = nullptr;
		break;
	}
	case EventOnRtnOrder:
	{
		Order* order = (Order*)myEvent->Field;
		Mdb::GetInstance().InsertRecord(order);
		myEvent->Field = nullptr;
		break;
	}
	case EventOnRtnTrade:
	{
		Trade* trade = (Trade*)myEvent->Field;
		Mdb::GetInstance().InsertRecord(trade);
		myEvent->Field = nullptr;
		break;
	}
	case EventOnRtnOrderCancel:
	{
		OrderCancel* orderCancel = (OrderCancel*)myEvent->Field;
		Mdb::GetInstance().InsertRecord(orderCancel);
		break;
	}
	default:
		break;
	}
	delete myEvent->Field;
	myEvent->Free();
}