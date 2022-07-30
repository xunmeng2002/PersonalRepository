#include "TcpSelectServer.h"
#include "Logger.h"
#include "Event.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectServer::TcpSelectServer()
{
	m_ListenSocket = INVALID_SOCKET;
	::memset(&m_RemoteAddress, 0, sizeof(m_RemoteAddress));
	m_RemoteAddressLen = sizeof(m_RemoteAddress);
}
void TcpSelectServer::SetBindAddressInfo(const char* ip, const char* port)
{
	m_BindIP = ip;
	m_BindPort = port;
	GetAddrinfo(ip, port, m_BindAddressInfo);
}
bool TcpSelectServer::Init()
{
	m_ListenSocket = PrepareSocket(m_BindAddressInfo->ai_family);
	if (m_ListenSocket == INVALID_SOCKET)
	{
		return false;
	}
	if (!Bind(m_ListenSocket, m_BindAddressInfo))
	{
		return false;
	}
	return Listen(m_ListenSocket);
}


void TcpSelectServer::PrepareFds()
{
	TcpSelectBase::PrepareFds();
	FD_SET(m_ListenSocket, &m_RecvFds);
	if (m_ListenSocket > m_MaxID)
	{
		m_MaxID = m_ListenSocket;
	}
}
void TcpSelectServer::DoAccept()
{
	if (FD_ISSET(m_ListenSocket, &m_RecvFds))
	{
		for (int i = 0; i < 5; i++)
		{
			SOCKET socketID = accept(m_ListenSocket, (sockaddr*)&m_RemoteAddress, &m_RemoteAddressLen);
			if (socketID == INVALID_SOCKET)
			{
				break;
			}
			SetSockNodelay(socketID);

			auto sessionID = ++m_MaxSessionID;
			std::string ip, port;
			auto ret = GetNameinfo((sockaddr*)&m_RemoteAddress, m_RemoteAddressLen, ip, port);
			WRITE_LOG(LogLevel::Info, "accept: SessionID[%d], SocketID[%lld], RemoteIP[%s], RemotePort[%s]", sessionID, socketID, ip.c_str(), port.c_str());

			auto connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
			AddConnect(connectData);
		}
	}
}
