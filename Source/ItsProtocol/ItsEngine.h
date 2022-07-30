#pragma once
#include <set>
#include <vector>
#include <list>
#include <string>
#include "TcpSelectServer.h"
#include "ItsInterface.h"
#include "MdbInterface.h"
#include "ItsMdb.h"
#include "Mdb.h"
#include "UdpClient.h"


struct ItsInsertOrderKey
{
	std::string TradingDay;
	std::string RequestID;
};

struct sqlite3;
class ItsEngine : public ThreadBase, public TcpSubscriber, public MdbPublisher, public ItsMdbCallback, public MdbCallback
{
public:
	ItsEngine(const std::string& channelID, const std::string& tcpBindIP, const std::string& tcpBindPort, const std::string& udpIP, const std::string& udpPort);
	~ItsEngine();
	void RegisterSubscriber(MdbSubscriber* mdbSubscriber);
	bool Init();

protected:
	virtual void Run() override;
	virtual void HandleEvent() override;

public:
	virtual void OnConnect(int sessionID, const char* ip, const char* port) override;
	virtual void OnDisConnect(int sessionID, const char* ip, const char* port) override;
	virtual void OnRecv(TcpEvent* tcpEvent) override;

	virtual void OnRtnOrder(Order* field) override;
	virtual void OnRtnTrade(Trade* field) override;
	virtual void OnErrRtnOrderCancel(OrderCancel* field) override;

	virtual void SelectMdbOrderSequenceCallback(OrderSequence* field) override;
	virtual void SelectMdbOrderCallback(Order* field) override;
	virtual void SelectMdbOrderCancelCallback(OrderCancel* field) override;
	virtual void SelectMdbTradeCallback(Trade* field) override;

protected:
	void HandleRecvData();
	void ItsHandleInsertOrder(int sessionID, ItsInsertOrder* itsInsertOrder);
	void ItsHandleCancelOrder(int sessionID, ItsInsertOrderCancel* itsInsertOrderCancel);

	void HandleInsertOrder(int sessionID, ItsInsertOrder* field);
	void HandleCancelOrder(int sessionID, ItsInsertOrderCancel* field);
	void HandleRtnOrder(Order* field);
	void HandleRtnTrade(Trade* field);
	void HandleErrRtnOrderCancel(OrderCancel* field);

	template<typename T>
	void SendUdp(T* field)
	{
		ItsMdb::GetInstance().InsertRecord(field);
		TcpEvent* tcpEvent = TcpEvent::Allocate();
		tcpEvent->IP = m_UdpRemoteIP;
		tcpEvent->Port = m_UdpRemotePort;
		tcpEvent->Length = field->ToStream(tcpEvent->Buff, BuffSize);
		m_UdpClient->ZipSendTo(tcpEvent);
		tcpEvent->Free();
	}


private:
	std::string GetNextOrderLocalID(const string& tradingDay);
	Order* GetOrder(const string& orderLocalID, const string& tradingDay, const string& orderSysID);
	Order* GetOrderFromOrderSysID(const string& tradingDay, const string& orderSysID);
	Order* GetOrderFromOrderLocalID(const string& orderLocalID);
	OrderCancel* GetOrderCancelFromOrderLocalID(const string& orderLocalID);
	bool CheckAndAddTrade(Trade* trade);

	void SendResponse(int sessionID, const string& sequenceNo, const string& errorID = "0", const string& errorMsg = "");

private:
	TcpBase* m_Tcp;
	UdpClient* m_UdpClient;
	sqlite3* m_ItsMdb;
	sqlite3* m_Mdb;

	MdbSubscriber* m_MdbSubscriber;
	std::set<int> m_SessionIDs;
	
	std::list<TcpEvent*> m_RecvDatas;
	std::vector<std::string> m_ItsItems;
	std::set<ItsInsertOrderKey*> m_InsertOrderKeys;

	std::set<OrderSequence*> m_OrderSequences;
	std::set<Order*> m_Orders;
	std::set<OrderCancel*> m_OrderCancels;
	std::set<Trade*> m_Trades;

	std::string m_UdpRemoteIP;
	std::string m_UdpRemotePort;

	std::string m_ChannelID;
	char* m_LogBuff;
	char m_OrderLocalIDBuff[32];
};

