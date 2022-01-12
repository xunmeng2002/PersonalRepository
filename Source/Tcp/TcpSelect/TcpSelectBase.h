#pragma once
#include <list>
#include <set>
#include <map>
#include "ThreadBase.h"
#include "SocketInit.h"
#include "ConnectData.h"
#include "TcpInterface.h"



class TcpSelectBase : public ThreadBase, public TcpPublisher
{
public:
	TcpSelectBase(const char* name);

	void Subscriber(TcpSubscriber* subscriber);
	void UnSubscriber(TcpSubscriber* subscriber);
	void SetTcpInfo(long timeOut = 1000000, int af = AF_INET, int type = SOCK_STREAM, int protocol = IPPROTO_TCP);
	virtual bool Init() = 0;
	virtual void Connect(const char* ip, int port) {}
	virtual void DisConnect(int sessionID) override;
	virtual void Send(int sessionID, const char* data, int length) override;
	virtual void Send(TcpEvent* tcpEvent) override;

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


	void AddConnect(ConnectData* connectData);
	void RemoveConnect(ConnectData* connectData);
	ConnectData* GetConnect(int sessionID);
	int SetSockReuse(SOCKET socketID);
	int SetSockUnblock(SOCKET socketID);
	int SetSockNodelay(SOCKET socketID);
	int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo);
	int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags = NI_NUMERICHOST);

	TcpEvent* GetSendEvent(int sessionID);
	void PushSendEvent(TcpEvent* tcpEvent);

protected:
	std::set<TcpSubscriber*> m_Subscribers;

	int m_AF;
	int m_Type;
	int m_Protocol;

	int m_MaxSessionID;

	fd_set m_RecvFds;
	fd_set m_SendFds;
	timeval m_ConnectTimeOut;
	timeval m_TimeOut;

	std::map<int, ConnectData*> m_ConnectDatas;
	std::map<int, std::list<TcpEvent*>> m_SendEvents;
};
