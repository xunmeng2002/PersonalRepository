#include "TcpSelectServer.h"
#include "Logger.h"
#include "Event.h"


TcpSelectServer::TcpSelectServer()
	:TcpSelectBase("TcpSelectServer")
{
	m_ListenSocket = INVALID_SOCKET;
	memset(&m_RemoteAddress, 0, sizeof(m_RemoteAddress));
	m_RemoteAddressLen = sizeof(m_RemoteAddress);
}
bool TcpSelectServer::Init(int family)
{
	if (family == AF_INET)
	{
		m_ListenSocket = ::socket(m_BindAddressInfoV4->ai_family, m_BindAddressInfoV4->ai_socktype, m_BindAddressInfoV4->ai_protocol);
	}
	else
	{
		m_ListenSocket = ::socket(m_BindAddressInfoV6->ai_family, m_BindAddressInfoV6->ai_socktype, m_BindAddressInfoV6->ai_protocol);
	}
	
	WRITE_LOG(LogLevel::Info, "create socket: m_ListenSocket[%lld].\n", m_ListenSocket);
	if (m_ListenSocket == INVALID_SOCKET)
	{
		return false;
	}
	if (!InitSocket(m_ListenSocket))
	{
		return false;
	}
	if (Bind(family) == SOCKET_ERROR || Listen() == SOCKET_ERROR)
	{
		closesocket(m_ListenSocket);
		return false;
	}
	return true;
}
int TcpSelectServer::Bind(int family)
{
	auto ret = 0;
	if (family == AF_INET)
	{
		ret = ::bind(m_ListenSocket, m_BindAddressInfoV4->ai_addr, m_BindAddressInfoV4->ai_addrlen);
		WRITE_LOG(LogLevel::Info, "bind: IP:[%s] Port[%s], ret[%d].\n", m_IPV4.c_str(), m_Port.c_str(), ret);
	}
	else
	{
		ret = ::bind(m_ListenSocket, m_BindAddressInfoV6->ai_addr, m_BindAddressInfoV6->ai_addrlen);
		WRITE_LOG(LogLevel::Info, "bind: IP:[%s] Port[%s], ret[%d].\n", m_IPV6.c_str(), m_Port.c_str(), ret);
	}
	return ret;
}
int TcpSelectServer::Listen()
{
	auto ret = ::listen(m_ListenSocket, 5);
	WRITE_LOG(LogLevel::Info, "listen: ret[%d].\n", ret)
	return ret;
}
void TcpSelectServer::PrepareFds()
{
	TcpSelectBase::PrepareFds();
	FD_SET(m_ListenSocket, &m_RecvFds);
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
