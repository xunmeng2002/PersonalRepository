#include "TcpSelectServer.h"
#include "Logger.h"
#include "Event.h"


TcpSelectServer::TcpSelectServer()
	:TcpSelectBase("TcpSelectServer")
{
	m_ListenSocket = INVALID_SOCKET;
	m_BindAddressInfo = nullptr;
	memset(&m_RemoteAddress, 0, sizeof(m_RemoteAddress));
	m_RemoteAddressLen = sizeof(m_RemoteAddress);
	m_Backlog = 5;
}
int TcpSelectServer::SetBindAddressInfo(const char* ip, const char* port, int backLog)
{
	m_IP = ip;
	m_Port = port;
	m_Backlog = backLog;
	auto ret = GetAddrinfo(ip, port, m_BindAddressInfo);
	WRITE_LOG(LogLevel::Info, "TcpSelectServer SetBindAddressInfo: IP[%s] Port[%s] GetAddrinfo ret[%d]", ip, port, ret);
	return ret;
}
bool TcpSelectServer::Init()
{
	m_ListenSocket = ::socket(m_AF, m_Type, m_Protocol);
	WRITE_LOG(LogLevel::Info, "create socket: m_ListenSocket[%lld].\n", m_ListenSocket);
	if (m_ListenSocket == INVALID_SOCKET)
	{
		return false;
	}
	if (SetSockReuse(m_ListenSocket) == SOCKET_ERROR || SetSockUnblock(m_ListenSocket) == SOCKET_ERROR || SetSockNodelay(m_ListenSocket) == SOCKET_ERROR)
	{
		closesocket(m_ListenSocket);
		return false;
	}
	if (Bind() == SOCKET_ERROR || Listen() == SOCKET_ERROR)
	{
		closesocket(m_ListenSocket);
		return false;
	}
	return true;
}
int TcpSelectServer::Bind()
{
	auto ret = ::bind(m_ListenSocket, m_BindAddressInfo->ai_addr, m_BindAddressInfo->ai_addrlen);
	WRITE_LOG(LogLevel::Info, "bind: IP:[%s] Port[%s], ret[%d].\n", m_IP.c_str(), m_Port.c_str(), ret);
	return ret;
}
int TcpSelectServer::Listen()
{
	auto ret = ::listen(m_ListenSocket, m_Backlog);
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
		for (int i = 0; i < m_Backlog; i++)
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
			WRITE_LOG(LogLevel::Info, "accept: SessionID[%d], SocketID[%lld], RemoteIP[%s], RemotePort[%d]", sessionID, socketID, ip.c_str(), port.c_str());

			auto connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
			AddConnect(connectData);
		}
	}
}
