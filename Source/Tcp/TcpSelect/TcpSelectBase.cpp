#include "TcpSelectBase.h"
#include "Logger.h"
#include "Event.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectBase::TcpSelectBase()
{
	FD_ZERO(&m_RecvFds);
	FD_ZERO(&m_SendFds);
	m_MaxID = 0;

	m_SocketTimeOut.tv_sec = 5;
	m_SocketTimeOut.tv_usec = 0;
}


void TcpSelectBase::DisConnect(int sessionID)
{
	m_DisConnectSessions.push_back(sessionID);
}
void TcpSelectBase::Send(int sessionID, const char* data, int len)
{
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	tcpEvent->EventID = EventSend;
	tcpEvent->SessionID = sessionID;
	::memcpy(tcpEvent->Buff, data, len);
	tcpEvent->Length = len;
	tcpEvent->Buff[len] = '\0';
	Send(tcpEvent);
}
void TcpSelectBase::Send(TcpEvent* tcpEvent)
{
	m_SendEvents[tcpEvent->SessionID].push_back(tcpEvent);
}
void TcpSelectBase::HandleTcpEvent()
{
	CheckConnect();
	DoDisConnect();
	PrepareFds();
	::select(m_MaxID + 1, &m_RecvFds, &m_SendFds, nullptr, &m_SocketTimeOut);
	DoAccept();
	DoRecv();
	DoSend();
}

void TcpSelectBase::PrepareFds()
{
	FD_ZERO(&m_RecvFds);
	FD_ZERO(&m_SendFds);
	m_MaxID = 0;
	for (auto& it : m_ConnectDatas)
	{
		FD_SET(it.second->SocketID, &m_RecvFds);
		if (!m_SendEvents[it.first].empty())
			FD_SET(it.second->SocketID, &m_SendFds);
		if (it.second->SocketID > m_MaxID)
		{
			m_MaxID = it.second->SocketID;
		}
	}
}
void TcpSelectBase::DoDisConnect()
{
	while (!m_DisConnectSessions.empty())
	{
		auto sessionID = m_DisConnectSessions.front();
		m_DisConnectSessions.pop_front();
		RemoveConnect(sessionID);
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
					WRITE_LOG(LogLevel::Info, "OnSend: SessionID[%d], Len[%d], [%s]", connectData->SessionID, tcpEvent->Length, tcpEvent->ReadPos);
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
SOCKET TcpSelectBase::PrepareSocket(int family)
{
	auto socketID = socket(family, SOCK_STREAM, IPPROTO_TCP);
	if (!InitSocket(socketID))
	{
		return INVALID_SOCKET;
	}
	return socketID;
}
