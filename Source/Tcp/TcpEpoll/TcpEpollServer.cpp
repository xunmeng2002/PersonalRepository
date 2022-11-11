#include "TcpEpollServer.h"
#include "Logger.h"
#include "Event.h"
#include "TcpUtility.h"
#include <string.h>


TcpEpollServer::TcpEpollServer()
{
}
TcpEpollServer::~TcpEpollServer()
{

}
bool TcpEpollServer::Init()
{
	if (!TcpEpollBase::Init())
	{
		return false;
	}
	m_ListenSocket = PrepareSocket(m_BindAddressInfo->ai_family);
	if (m_ListenSocket == INVALID_SOCKET)
	{
		return false;
	}
	if (!Bind(m_ListenSocket, m_BindAddressInfo))
	{
		return false;
	}
	if (!Listen(m_ListenSocket))
	{
		return false;
	}
	ConnectData* connectData = ConnectData::Allocate(0, m_ListenSocket, m_BindIP, m_BindPort);
	AddEpollEvent(connectData);
	return true;
}
void TcpEpollServer::DoAccept()
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

