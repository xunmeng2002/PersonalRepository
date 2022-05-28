#pragma once
#include <list>
#include <set>
#include <map>
#include "ConnectData.h"
#include "TcpBase.h"



class TcpSelectBase : public TcpBase
{
public:
	TcpSelectBase();

	virtual void Connect(const char* ip, const char* port) {}
	virtual void DisConnect(int sessionID) override;
	virtual void Send(int sessionID, const char* data, int len) override;
	virtual void Send(TcpEvent* tcpEvent) override;
	virtual void HandleTcpEvent() override;
protected:
	virtual void PrepareFds();
	virtual void CheckConnect() {}
	virtual void DoDisConnect();
	virtual void DoAccept() {}
	virtual void DoSend();
	virtual void DoRecv();


	virtual void AddConnect(ConnectData* connectData) override;
	virtual void RemoveConnect(int sessionID) override;
	

	TcpEvent* GetSendEvent(int sessionID);
	SOCKET PrepareSocket(int family);

protected:
	fd_set m_RecvFds;
	fd_set m_SendFds;
	
	std::map<int, std::list<TcpEvent*>> m_SendEvents;
	std::list<int> m_DisConnectSessions;
};
