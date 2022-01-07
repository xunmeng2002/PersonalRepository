#pragma once
#include "ThreadBase.h"
#include "ItsInterface.h"
#include "MdbInterface.h"
#include <set>

struct sqlite3;
class MdbEngine : public ThreadBase, public ItsSubscriber, public MdbPublisher, public MdbCallback
{
	
public:
	MdbEngine();
	~MdbEngine();
	void RegisterItsPublisher(ItsPublisher* itsPublisher);
	void RegisterSubscriber(MdbSubscriber* mdbSubscriber);
	bool Init(const char* dbName = "");
	virtual void ReqInsertOrder(int sessionID, ItsInsertOrder* field) override;
	virtual void ReqInsertOrderCancel(int sessionID, ItsInsertOrderCancel* field) override;
	virtual void OnRtnOrder(Order* field) override;
	virtual void OnRtnTrade(Trade* field) override;
	virtual void OnErrRtnOrderCancel(OrderCancel* field) override;

	virtual void SelectMdbOrderSequenceCallback(OrderSequence* field) override;
	virtual void SelectMdbOrderCallback(Order* field) override;
	virtual void SelectMdbOrderCancelCallback(OrderCancel* field) override;
	virtual void SelectMdbTradeCallback(Trade* field) override;


	virtual void Run() override;
	virtual void HandleEvent() override;
	void HandleInsertOrder(int sessionID, ItsInsertOrder* field);
	void HandleInsertOrderCancel(int sessionID, ItsInsertOrderCancel* field);
	void SendResponse(int sessionID, const string& sequenceNo, const string& errorID = "0", const string& errorMsg = "");
	void HandleRtnOrder(Order* field);
	void HandleRtnTrade(Trade* field);
	void HandleErrRtnOrderCancel(OrderCancel* field);

private:
	std::string GetNextOrderLocalID(const string& tradingDay);
	Order* GetOrder(const string& orderLocalID, const string& tradingDay, const string& orderSysID);
	Order* GetOrderFromOrderSysID(const string& tradingDay, const string& orderSysID);
	Order* GetOrderFromOrderLocalID(const string& orderLocalID);
	OrderCancel* GetOrderCancelFromOrderLocalID(const string& orderLocalID);
	bool CheckAndAddTrade(Trade* trade);

private:
	sqlite3* m_Mdb;

	std::set<OrderSequence*> m_OrderSequences;
	std::set<Order*> m_Orders;
	std::set<OrderCancel*> m_OrderCancels;
	std::set<Trade*> m_Trades;

	ItsPublisher* m_ItsPublisher;
	MdbSubscriber* m_MdbSubscriber;

	std::string m_ChannelID;
	char* m_LogBuff;
	char m_OrderLocalIDBuff[32];
};

