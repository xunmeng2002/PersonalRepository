#include "TcpSelectClient.h"
#include "TcpUtility.h"
#include "Logger.h"


TcpSelectClient::TcpSelectClient()
{
	m_ConnectAddressInfo = nullptr;
	FD_ZERO(&m_ConnectFds);

	m_ConnectTimeOut.tv_sec = 0;
	m_ConnectTimeOut.tv_usec = 0;
}

void TcpSelectClient::SetConnectTimeOut(int milliSeconds)
{
	m_ConnectTimeOut.tv_sec = milliSeconds / 1000;
	m_ConnectTimeOut.tv_usec = (milliSeconds % 1000) * 1000;
}
void TcpSelectClient::Connect(const char* ip, const char* port)
{
	auto ret = GetAddrinfo(ip, port, m_ConnectAddressInfo);
	SOCKET socketID = socket(m_ConnectAddressInfo->ai_family, m_ConnectAddressInfo->ai_socktype, m_ConnectAddressInfo->ai_protocol);
	if (!InitSocket(socketID))
	{
		return;
	}
	ret = connect(socketID, m_ConnectAddressInfo->ai_addr, int(m_ConnectAddressInfo->ai_addrlen));
	WRITE_LOG(LogLevel::Info, "Connect Server:IP:[%s] Port[%s] ret[%d]", ip, port, ret);

	int sessionID = ++m_MaxSessionID;
	ConnectData* connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
	m_ConnectingSocket.push_back(connectData);
}

void TcpSelectClient::CheckConnect()
{
	if (m_ConnectingSocket.size() == 0)
		return;
	FD_ZERO(&m_ConnectFds);
	uint64_t maxID = 0;
	for (auto& connectData : m_ConnectingSocket)
	{
		FD_SET(connectData->SocketID, &m_ConnectFds);
		if (connectData->SocketID > maxID)
		{
			maxID = connectData->SocketID;
		}
	}
	auto ret = select(maxID + 1, NULL, &m_ConnectFds, NULL, &m_ConnectTimeOut);
	WRITE_LOG(LogLevel::Info, "Connect Select: ret[%d]\n", ret);
	while (!m_ConnectingSocket.empty())
	{
		auto connectData = m_ConnectingSocket.front();
		m_ConnectingSocket.pop_front();
		if (ret <= 0 || !FD_ISSET(connectData->SocketID, &m_ConnectFds))
		{
			if (m_Subscriber)
			{
				m_Subscriber->OnDisConnect(connectData->SessionID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
			}
		}
		else
		{
			AddConnect(connectData);
		}
	}
}
