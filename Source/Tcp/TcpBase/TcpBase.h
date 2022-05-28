#pragma once
#include "SocketInit.h"
#include "ConnectData.h"
#include "Event.h"
#include <map>

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
	void Subscriber(TcpSubscriber* subscriber);
	void UnSubscriber();
	virtual void SetSocketTimeOut(int milliSeconds);
	virtual bool Init() { return true; }


	virtual void Connect(const char* ip, const char* port) = 0;
	virtual void DisConnect(int sessionID) = 0;
	virtual void Send(int sessionID, const char* data, int len) = 0;
	virtual void Send(TcpEvent* tcpEvent) = 0;
	virtual void HandleTcpEvent() = 0;
protected:
	virtual void AddConnect(ConnectData* connectData);
	virtual void RemoveConnect(int sessionID);
	virtual ConnectData* GetConnect(int sessionID);

	bool InitSocket(SOCKET socketID);

protected:
	TcpSubscriber* m_Subscriber;
	int m_MaxSessionID;
	timeval m_SocketTimeOut;

	std::map<int, ConnectData*> m_ConnectDatas;
};


