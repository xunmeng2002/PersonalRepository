#pragma once
#include "TcpBase.h"
#include "ConnectData.h"
#include <list>
#include <map>
#include <sys/epoll.h>


class TcpEpollBase : public TcpBase
{
public:
	TcpEpollBase();
	~TcpEpollBase();

	virtual bool Init() override;
	virtual void HandleTcpEvent() override;
protected:
	virtual void CheckConnect() {}
	virtual void DoAccept() {}

	virtual void AddConnect(ConnectData* connectData) override;
	virtual void RemoveConnect(ConnectData* connectData) override;
	void AddEpollEvent(ConnectData* connectData);
	void RemoveEpollEvent(ConnectData* connectData);

protected:
	int m_EpollFd;
	epoll_event m_EpollEvents[1024];
	std::map<int, std::list<TcpEvent*>> m_SendEvents;
};

