#pragma once
#include "ThreadBase.h"
#include "TcpBase.h"
#include <map>


class TcpClientSubscriberImpl : public ThreadBase, public TcpSubscriber
{
public:
	TcpClientSubscriberImpl(TcpBase* tcp);
	bool Init();
	virtual void HandleEvent() override;



	virtual void OnConnect(int sessionID, const char* ip, const char* port);
	virtual void OnDisConnect(int sessionID, const char* ip, const char* port);
	virtual void OnRecv(TcpEvent* tcpEvent);

	void Send(int sessionID, const char* ip, const char* port);
private:
	TcpBase* m_Tcp;
	std::map<int, int> m_MessageCounts;
};
