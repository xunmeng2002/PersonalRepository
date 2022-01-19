#include "TcpServerBase.h"
#include "TcpBase.h"
#include "Logger.h"


TcpServerBase::TcpServerBase()
	:m_BindAddressInfo(nullptr), m_BindIP(""), m_BindPort(""), m_ListenSocket(INVALID_SOCKET)
{
}
TcpServerBase::~TcpServerBase()
{
	freeaddrinfo(m_BindAddressInfo);
	closesocket(m_ListenSocket);
}
void TcpServerBase::SetBindAddressInfo(const char* port, const char* ip)
{
	m_BindIP = ip;
	m_BindPort = port;
	TcpBase::GetAddrinfo(ip, port, m_BindAddressInfo);
}
bool TcpServerBase::Bind()
{
	if (::bind(m_ListenSocket, m_BindAddressInfo->ai_addr, m_BindAddressInfo->ai_addrlen) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "Bind Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}
bool TcpServerBase::Listen(int backLog)
{
	if (listen(m_ListenSocket, backLog) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "Listen Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}
