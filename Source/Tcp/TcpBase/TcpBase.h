#pragma once
#include "SocketInit.h"
#include "ConnectData.h"
#include "Event.h"
#include <list>
#include <map>
#include <mutex>

class TcpSubscriber
{
public:
	virtual void OnConnect(int sessionID, const char* ip, const char* port) {}
	virtual void OnDisConnect(int sessionID, const char* ip, const char* port) {}
	virtual void OnRecv(TcpEvent* tcpEvent) {}
};


class TcpBase
{
public:
	TcpBase();
	~TcpBase();
	void Subscriber(TcpSubscriber* subscriber);
	void UnSubscriber();
	virtual void SetSocketTimeOut(int milliSeconds);
	void SetBindAddressInfo(const char* ip, const char* port);
	virtual bool Init() { return true; }

	virtual bool Connect(const char* ip, const char* port);
	virtual void DisConnect(int sessionID);
	virtual bool Send(int sessionID, const char* data, int len);
	virtual bool Send(TcpEvent* tcpEvent);
	virtual void HandleTcpEvent() = 0;
protected:
	virtual void DoDisConnect();
	virtual void DoAccept();
	virtual void DoRecv(ConnectData* connectData);
	virtual void AddConnect(ConnectData* connectData);
	virtual void RemoveConnect(ConnectData* connectData);
	virtual ConnectData* GetConnect(int sessionID);

	bool InitSocket(SOCKET socketID);
	SOCKET PrepareSocket(int family);

protected:
	TcpSubscriber* m_Subscriber;
	int m_MaxSessionID;
	int m_SocketTimeOut;

	std::map<int, ConnectData*> m_ConnectDatas;
	std::mutex m_ConnectDataMutex;
	std::list<int> m_DisConnectSessions;
	std::mutex m_DisConnectSessionMutex;

	SOCKET m_ListenSocket;
	addrinfo* m_ConnectAddressInfo;
	addrinfo* m_BindAddressInfo;
	std::string m_BindIP;
	std::string m_BindPort;
	sockaddr_storage m_RemoteAddress;
#ifdef WINDOWS
	int m_RemoteAddressLen;
#endif
#ifdef LINUX
	unsigned int m_RemoteAddressLen;
#endif
};


