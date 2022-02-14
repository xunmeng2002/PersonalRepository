#include "TcpSelectClient.h"
#include "Logger.h"


TcpSelectClient::TcpSelectClient()
	:TcpSelectBase("TcpSelectClient")
{
	m_ConnectAddressInfo = nullptr;
	FD_ZERO(&m_ConnectFds);
}

void TcpSelectClient::Connect(const char* ip, const char* port)
{
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	tcpEvent->EventID = EventConnect;
	tcpEvent->IP = ip;
	tcpEvent->Port = port;
	OnEvent(tcpEvent);
}

void TcpSelectClient::DoConnect(const std::string& ip, const std::string& port)
{
	auto ret = GetAddrinfo(ip.c_str(), port.c_str(), m_ConnectAddressInfo);

	SOCKET socketID = socket(m_ConnectAddressInfo->ai_family, m_ConnectAddressInfo->ai_socktype, m_ConnectAddressInfo->ai_protocol);
	if (!InitSocket(socketID))
	{
		return;
	}

	ret = connect(socketID, m_ConnectAddressInfo->ai_addr, int(m_ConnectAddressInfo->ai_addrlen));
	WRITE_LOG(LogLevel::Info, "Connect Server:IP:[%s] Port[%s] ret[%d]", ip.c_str(), port.c_str(), ret);

	int sessionID = ++m_MaxSessionID;
	ConnectData* connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
	m_ConnectingSocket.push_back(connectData);
}
void TcpSelectClient::CheckConnect()
{
	if (m_ConnectingSocket.size() == 0)
		return;
	FD_ZERO(&m_ConnectFds);
	for (auto& connectData : m_ConnectingSocket)
	{
		FD_SET(connectData->SocketID, &m_ConnectFds);
	}
	auto ret = select(0, NULL, &m_ConnectFds, NULL, &m_SocketTimeOut);
	WRITE_LOG(LogLevel::Info, "Connect Select: ret[%d]\n", ret);
	while (!m_ConnectingSocket.empty())
	{
		auto connectData = m_ConnectingSocket.front();
		m_ConnectingSocket.pop_front();
		if (ret <= 0)
		{
			NotifyDisConnect(connectData);
		}
		else if (!FD_ISSET(connectData->SocketID, &m_ConnectFds))
		{
			NotifyDisConnect(connectData);
		}
		else
		{
			AddConnect(connectData);
		}
	}
}
