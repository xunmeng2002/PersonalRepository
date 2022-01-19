#pragma once
#include "SocketInit.h"
#include "ThreadBase.h"
#include "TcpInterface.h"
#include "ConnectData.h"
#include <map>


class TcpBase : public ThreadBase, public TcpPublisher
{
public:
	TcpBase(const char* name);
	void Subscriber(TcpSubscriber* subscriber);
	void UnSubscriber(TcpSubscriber* subscriber);
	virtual void SetSocketTimeOut(int milliSeconds);
	virtual void ThreadExit() override;

	virtual void DisConnect(int sessionID) override;
	virtual void Send(int sessionID, const char* data, int len) override;
	virtual void Send(TcpEvent* tcpEvent) override;


	static int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo);
	static int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags = NI_NUMERICHOST);

protected:
	virtual void AddConnect(ConnectData* connectData);
	virtual void RemoveConnect(int sessionID);
	virtual ConnectData* GetConnect(int sessionID);
	void NotifyDisConnect(ConnectData* connectData);

	bool InitSocket(SOCKET socketID);
	bool SetSockUnblock(SOCKET socketID, unsigned long unblock = 1);
	bool SetSockReuse(SOCKET socketID, int resue = 1);
	bool SetSockNodelay(SOCKET socketID, int nodelay = 1);
	bool SetSockIPV6Only(SOCKET socketID, int ipv6Only = 0);

protected:
	TcpSubscriber* m_Subscriber;
	int m_MaxSessionID;
	timeval m_SocketTimeOut;

	std::map<int, ConnectData*> m_ConnectDatas;
};


