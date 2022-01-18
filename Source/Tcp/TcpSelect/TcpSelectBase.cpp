#include "TcpSelectBase.h"
#include "Logger.h"
#include "Event.h"


TcpSelectBase::TcpSelectBase(const char* name)
	:TcpBase(name)
{
	FD_ZERO(&m_RecvFds);
	FD_ZERO(&m_SendFds);

	m_SocketTimeOut.tv_sec = 5;
	m_SocketTimeOut.tv_usec = 0;
}

void TcpSelectBase::DisConnect(int sessionID)
{
	WRITE_LOG(LogLevel::Info, "DisConnect SessionID:[%d]", sessionID);
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	tcpEvent->EventID = EventDisConnect;
	tcpEvent->SessionID = sessionID;
	OnEvent(tcpEvent);
}
void TcpSelectBase::Send(int sessionID, const char* data, int length)
{
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	tcpEvent->EventID = EventSend;
	tcpEvent->SessionID = sessionID;
	memcpy(tcpEvent->Buff, data, length);
	tcpEvent->Length = length;

	OnEvent(tcpEvent);
}
void TcpSelectBase::Send(TcpEvent* tcpEvent)
{
	OnEvent(tcpEvent);
}

void TcpSelectBase::Run()
{
	HandleEvent();
	CheckConnect();
	PrepareFds();
	::select(0, &m_RecvFds, &m_SendFds, nullptr, &m_SocketTimeOut);
	DoAccept();
	DoRecv();
	DoSend();
	HandleOtherTask();
}
void TcpSelectBase::HandleEvent()
{
	TcpEvent* tcpEvent = nullptr;
	while (tcpEvent = (TcpEvent*)GetEvent())
	{
		bool shouldFree = true;
		switch (tcpEvent->EventID)
		{
		case EventConnect:
		{
			DoConnect(tcpEvent->IP, tcpEvent->Port);
			break;
		}
		case EventDisConnect:
		{
			DoDisConnect(tcpEvent->SessionID);
			break;
		}
		case EventSend:
		{
			PushSendEvent(tcpEvent);
			shouldFree = false;
			break;
		}
		default:
			break;
		}
		if (shouldFree)
		{
			tcpEvent->Free();
		}
	}
}
void TcpSelectBase::DoDisConnect(int sessionID)
{
	RemoveConnect(sessionID);
}
void TcpSelectBase::PrepareFds()
{
	FD_ZERO(&m_RecvFds);
	FD_ZERO(&m_SendFds);
	for (auto& it : m_ConnectDatas)
	{
		FD_SET(it.second->SocketID, &m_RecvFds);
		if (!m_SendEvents[it.first].empty())
			FD_SET(it.second->SocketID, &m_SendFds);
	}
}
void TcpSelectBase::DoSend()
{
	for (auto& it : m_ConnectDatas)
	{
		auto connectData = it.second;
		if (FD_ISSET(connectData->SocketID, &m_SendFds))
		{
			while (!m_SendEvents[it.first].empty())
			{
				auto tcpEvent = m_SendEvents[it.first].front();
				int len = send(connectData->SocketID, tcpEvent->ReadPos, tcpEvent->Length, 0);
				if (len <= 0)
				{
					WRITE_LOG(LogLevel::Info, "DisConnect For Send. SessionID[%d], Len:[%d]", connectData->SessionID, len);
					DisConnect(connectData->SessionID);
					break;
				}
				else if (len < tcpEvent->Length)
				{
					WRITE_LOG(LogLevel::Info, "OnSend, Send Less than expect.SessionID[%d], Len[%d], Expect Len[%d], [%s]", connectData->SessionID, len, tcpEvent->Length, tcpEvent->ReadPos);
					tcpEvent->ReadPos += len;
					tcpEvent->Length -= len;
					break;
				}
				else
				{
					WRITE_LOG(LogLevel::Debug, "OnSend: SessionID[%d], Len[%d], [%s]", connectData->SessionID, tcpEvent->Length, tcpEvent->ReadPos);
					m_SendEvents[it.first].pop_front();
					tcpEvent->Free();
				}
			}
		}
	}
}
void TcpSelectBase::DoRecv()
{
	for (auto& it : m_ConnectDatas)
	{
		auto connectData = it.second;
		auto socketID = connectData->SocketID;
		int sessionID = connectData->SessionID;
		if (FD_ISSET(socketID, &m_RecvFds))
		{
			TcpEvent* tcpEvent = TcpEvent::Allocate();
			int len = recv(socketID, tcpEvent->Buff, BuffSize - 1, 0);
			if (len <= 0)
			{
				WRITE_LOG(LogLevel::Info, "OnRecv: SessionID[%d], len[%d] DisConnect", sessionID, len);
				tcpEvent->Free();
				DisConnect(sessionID);
			}
			else
			{
				tcpEvent->Buff[len] = '\0';
				WRITE_LOG(LogLevel::Debug, "OnRecv: SessionID[%d], len[%d], [%s]", sessionID, len, tcpEvent->Buff);
				tcpEvent->EventID = EventRecv;
				tcpEvent->SessionID = sessionID;
				tcpEvent->IP = it.second->RemoteIP;
				tcpEvent->Port = it.second->RemotePort;
				tcpEvent->Length = len;

				if (m_Subscriber)
				{
					m_Subscriber->OnRecv(tcpEvent);
				}
			}
		}
	}
}

void TcpSelectBase::AddConnect(ConnectData* connectData)
{
	TcpBase::AddConnect(connectData);
	m_SendEvents.insert(std::make_pair(connectData->SessionID, std::list<TcpEvent*>()));
}
void TcpSelectBase::RemoveConnect(int sessionID)
{
	for (auto tcpEvent : m_SendEvents[sessionID])
	{
		tcpEvent->Free();
	}
	m_SendEvents.erase(sessionID);
	TcpBase::RemoveConnect(sessionID);
}


TcpEvent* TcpSelectBase::GetSendEvent(int sessionID)
{
	if (m_SendEvents.find(sessionID) == m_SendEvents.end())
	{
		return nullptr;
	}
	if (m_SendEvents[sessionID].empty())
	{
		return nullptr;
	}
	auto tcpEvent = m_SendEvents[sessionID].front();
	m_SendEvents[sessionID].pop_front();
	return tcpEvent;
}
void TcpSelectBase::PushSendEvent(TcpEvent* tcpEvent)
{
	m_SendEvents[tcpEvent->SessionID].push_back(tcpEvent);
}