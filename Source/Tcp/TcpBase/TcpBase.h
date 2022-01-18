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
	void SetBindAddressInfo(const char* port, const char* ipV4 = "0.0.0.0", const char* ipV6 = "::");
	virtual void SetSocketTimeOut(int milliSeconds);
	virtual bool Init(int family);
	virtual void ThreadExit() override;

	static int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo);
	static int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags = NI_NUMERICHOST);

protected:
	virtual void AddConnect(ConnectData* connectData);
	virtual void RemoveConnect(int sessionID);
	virtual ConnectData* GetConnect(int sessionID);
	void NotifyDisConnect(ConnectData* connectData);

	bool InitSocket(SOCKET socketID);
	int SetSockReuse(SOCKET socketID, int resue = 1);
	int SetSockUnblock(SOCKET socketID, unsigned long unblock = 1);
	int SetSockNodelay(SOCKET socketID, int nodelay = 1);
	int SetSockIPV6Only(SOCKET socketID, int ipv6Only = 0);

protected:
	int m_Family;
	addrinfo* m_BindAddressInfoV4;
	addrinfo* m_BindAddressInfoV6;
	std::string m_IPV4;
	std::string m_IPV6;
	std::string m_Port;
	TcpSubscriber* m_Subscriber;
	timeval m_SocketTimeOut;

	int m_MaxSessionID;
	std::map<int, ConnectData*> m_ConnectDatas;
};


