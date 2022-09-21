#pragma once
#include "ThreadBase.h"
#include "TcpBase.h"


class TcpServerSubscriberImpl : public ThreadBase, public TcpSubscriber
{
public:
	TcpServerSubscriberImpl(TcpBase* tcp);
	bool Init();
	virtual void HandleEvent() override;

	virtual void OnConnect(int sessionID, const char* ip, const char* port);
	virtual void OnDisConnect(int sessionID, const char* ip, const char* port);
	virtual void OnRecv(TcpEvent* tcpEvent);

private:
	TcpBase* m_Tcp;
};