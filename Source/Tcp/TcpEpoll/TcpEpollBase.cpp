#include "TcpEpollBase.h"
#include "Logger.h"
#include "Event.h"
#include "TcpUtility.h"
#include <string.h>

TcpEpollBase::TcpEpollBase()
{
	m_EpollFd = epoll_create(5);
}
TcpEpollBase::~TcpEpollBase()
{
	close(m_EpollFd);
}

bool TcpEpollBase::Init()
{
	return true;
}
void TcpEpollBase::HandleTcpEvent()
{
	DoDisConnect();
	int eventNum = sizeof(m_EpollEvents)/ sizeof(epoll_event);
	int number = epoll_wait(m_EpollFd, m_EpollEvents, eventNum, m_SocketTimeOut);
	if (number < 0 && errno != EINTR)
	{
		WRITE_LOG(LogLevel::Info, "epoll wait failed. number:[%d], errno:[%d]\n", number, errno);
		return;
	}
	for (int i = 0; i < number; i++)
	{
		auto epollEvent = m_EpollEvents[i];
		auto connectData = (ConnectData*)m_EpollEvents[i].data.ptr;
		if (connectData->SocketID == m_ListenSocket)
		{
			DoAccept();
		}
		else if (epollEvent.events & EPOLLIN)
		{
			DoRecv(connectData);
		}
	}
}

void TcpEpollBase::AddConnect(ConnectData* connectData)
{
	TcpBase::AddConnect(connectData);
	AddEpollEvent(connectData);
	m_SendEvents.insert(std::make_pair(connectData->SessionID, std::list<TcpEvent*>()));
}
void TcpEpollBase::RemoveConnect(ConnectData* connectData)
{
	for (auto tcpEvent : m_SendEvents[connectData->SessionID])
	{
		tcpEvent->Free();
	}
	m_SendEvents.erase(connectData->SessionID);
	RemoveEpollEvent(connectData);
	TcpBase::RemoveConnect(connectData);
}
void TcpEpollBase::AddEpollEvent(ConnectData* connectData)
{
	epoll_event epollEvent;
	epollEvent.data.ptr = connectData;
	epollEvent.events = EPOLLIN | EPOLLET;
	epoll_ctl(m_EpollFd, EPOLL_CTL_ADD, connectData->SocketID, &epollEvent);
}
void TcpEpollBase::RemoveEpollEvent(ConnectData* connectData)
{
	epoll_ctl(m_EpollFd, EPOLL_CTL_DEL, connectData->SocketID, NULL);
}


