#include "TcpSelectServer.h"
#include "Logger.h"
#include "Event.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectServer::TcpSelectServer()
{
}
bool TcpSelectServer::Init()
{
	if (!TcpSelectBase::Init())
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

