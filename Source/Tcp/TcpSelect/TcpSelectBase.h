#pragma once
#include <list>
#include <set>
#include <map>
#include "ConnectData.h"
#include "TcpBase.h"



class TcpSelectBase : public TcpBase
{
public:
	TcpSelectBase(const char* name);

protected:
	virtual void Run() override;
	virtual void HandleEvent();
	virtual void DoConnect(const std::string& ip, const std::string& port) {}
	virtual void DoDisConnect(int sessionID);
	virtual void PrepareFds();
	virtual void CheckConnect() {}
	virtual void DoAccept() {}
	virtual void DoSend();
	virtual void DoRecv();
	virtual void HandleOtherTask() {}


	virtual void AddConnect(ConnectData* connectData) override;
	virtual void RemoveConnect(int sessionID) override;
	

	TcpEvent* GetSendEvent(int sessionID);
	void PushSendEvent(TcpEvent* tcpEvent);
	SOCKET PrepareSocket(int family);

protected:
	fd_set m_RecvFds;
	fd_set m_SendFds;
	
	std::map<int, std::list<TcpEvent*>> m_SendEvents;
};
