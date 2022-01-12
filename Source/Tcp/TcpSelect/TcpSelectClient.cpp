#include "TcpSelectClient.h"
#include "Logger.h"


TcpSelectClient::TcpSelectClient()
	:TcpSelectBase("TcpSelectClient")
{
	m_ConnectAddressInfo = nullptr;
	FD_ZERO(&m_ConnectFds);
}

bool TcpSelectClient::Init()
{
	return true;
}
void TcpSelectClient::Connect(const char* ip, int port)
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
	WRITE_LOG(LogLevel::Info, "DoConnect: GetAddrinfo ret[%d]", ret);

	SOCKET socketID = socket(m_AF, m_Type, 0);
	SetSockReuse(socketID);
	SetSockUnblock(socketID);
	SetSockNodelay(socketID);

	ret = connect(socketID, m_ConnectAddressInfo->ai_addr, m_ConnectAddressInfo->ai_addrlen);
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
	auto ret = select(0, NULL, &m_ConnectFds, NULL, &m_ConnectTimeOut);
	WRITE_LOG(LogLevel::Info, "Connect Select: ret[%d]\n", ret);
	while (!m_ConnectingSocket.empty())
	{
		auto connectData = m_ConnectingSocket.front();
		m_ConnectingSocket.pop_front();
		if (ret <= 0)
		{
			RemoveConnect(connectData);
		}
		else if (!FD_ISSET(connectData->SocketID, &m_ConnectFds))
		{
			RemoveConnect(connectData);
		}
		else
		{
			AddConnect(connectData);
		}
	}
}
