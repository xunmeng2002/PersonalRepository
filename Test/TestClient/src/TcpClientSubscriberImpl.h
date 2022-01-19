#pragma once
#include "TcpInterface.h"
#include <map>


class TcpClientSubscriberImpl : public TcpSubscriber
{
public:
	TcpClientSubscriberImpl(TcpPublisher* tcpPublisher);
	virtual void OnConnect(int sessionID, const char* ip, const char* port);
	virtual void OnDisConnect(int sessionID, const char* ip, const char* port);
	virtual void OnRecv(TcpEvent* tcpEvent);

	void Send(int sessionID, const char* ip, const char* port);
private:
	TcpPublisher* m_TcpPublisher;
	std::map<int, int> m_MessageCounts;
};
