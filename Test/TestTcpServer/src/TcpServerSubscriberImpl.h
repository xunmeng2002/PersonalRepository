#pragma once
#include "TcpInterface.h"

class TcpServerSubscriberImpl : public TcpSubscriber
{
public:
	TcpServerSubscriberImpl(TcpPublisher* tcpPublisher);
	virtual void OnConnect(int sessionID, const char* ip, const char* port);
	virtual void OnDisConnect(int sessionID, const char* ip, const char* port);
	virtual void OnRecv(TcpEvent* tcpEvent);

private:
	TcpPublisher* m_TcpPublisher;
};