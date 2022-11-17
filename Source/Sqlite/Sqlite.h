#pragma once
#include "sqlite3.h"
#include "ThreadBase.h"
#include "MdbTables.h"
#include "ItsFields.h"
#include "Logger.h"


class ItsEngine;

class Sqlite : public ThreadBase
{
	
public:
	Sqlite();
	~Sqlite();
	bool Init(ItsEngine* itsEngine);

	void OnItsInsertOrder(ItsInsertOrder* itsInsertOrder);
	void OnItsInsertOrderCancel(ItsInsertOrderCancel* itsInsertOrderCancel);
	void OnItsRspOrder(ItsRspOrder* itsRspOrder);
	void OnItsRtnOrder(ItsOrder* itsOrder);
	void OnItsRtnTrade(ItsTrade* itsTrade);
	void OnItsRtnOrderCancel(ItsErrRtnOrderCancel* itsErrRtnOrderCancel);

	void OnOrderSequence(OrderSequence* orderSequence);
	void OnOrder(Order* order);
	void OnTrade(Trade* trade);
	void OnOrderCancel(OrderCancel* orderCancel);

protected:
	virtual void HandleEvent() override;


private:
	sqlite3* m_SqliteDB;
};

