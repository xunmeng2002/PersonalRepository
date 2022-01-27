#pragma once
#include <set>
#include <vector>
#include <list>
#include <string>
#include "TcpSelectServer.h"
#include "ItsInterface.h"
#include "ItsMdb.h"
#include "UdpClient.h"

struct ItsInsertOrderKey
{
	std::string TradingDay;
	std::string RequestID;
};

struct sqlite3;
class ItsEngine : public TcpSelectServer, public TcpSubscriber, public ItsPublisher, public ItsMdbCallback
{
public:
	ItsEngine(UdpClient* udpClient);
	~ItsEngine();
	void RegisterSubscriber(ItsSubscriber* itsSubscriber);
	void SetUdpRemoteAddress(const char* ip, const char* port);
	bool Init(const char* dbName = "");

	virtual void OnRtnOrder(ItsOrder* field) override;
	virtual void OnRtnTrade(ItsTrade* field) override;
	virtual void OnErrRtnOrderCancel(ItsErrRtnOrderCancel* field) override;
	virtual void OnRspOrder(int sessionID, ItsRspOrder* field) override;

	virtual void OnConnect(int sessionID, const char* ip, const char* port) override;
	virtual void OnDisConnect(int sessionID, const char* ip, const char* port) override;
	virtual void OnRecv(TcpEvent* tcpEvent) override;

	virtual void HandleOtherTask() override;

protected:
	void HandleRecvData();
	void HandleInsertOrder(int sessionID, ItsInsertOrder* itsInsertOrder);
	void HandleCancelOrder(int sessionID, ItsInsertOrderCancel* itsInsertOrderCancel);

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
	sqlite3* m_Mdb;
	ItsSubscriber* m_ItsSubscriber;
	UdpClient* m_UdpClient;
	std::string m_UdpRemoteIP;
	std::string m_UdpRemotePort;
	std::set<int> m_SessionIDs;
	
	std::list<TcpEvent*> m_RecvDatas;
	std::vector<std::string> m_ItsItems;
	std::set<ItsInsertOrderKey*> m_InsertOrderKeys;
};

