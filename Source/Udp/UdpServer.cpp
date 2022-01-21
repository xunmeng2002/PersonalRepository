#include "UdpServer.h"
#include "Logger.h"
#include "zlib.h"


void UdpServer::SetBindAddressInfo(const char* ip, const char* port)
{
	m_BindIP = ip;
	m_BindPort = port;
	GetAddrinfo(ip, port, m_BindAddressInfo);
}
bool UdpServer::Init(bool setBroadCast)
{
	m_Socket = socket(m_BindAddressInfo->ai_family, m_BindAddressInfo->ai_socktype, m_BindAddressInfo->ai_protocol);
	if (m_Socket == INVALID_SOCKET)
	{
		WRITE_LOG(LogLevel::Error, "Create Socket Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	if (setBroadCast && !SetBroadcast(m_Socket, setBroadCast))
	{
		closesocket(m_Socket);
		return false;
	}
	if (!SetSockIPV6Only(m_Socket))
	{
		closesocket(m_Socket);
		return false;
	}
	if (!Bind())
	{
		closesocket(m_Socket);
		return false;
	}
	
	WRITE_LOG(LogLevel::Info, "UdpServer Init Successed.");
	return true;
}
bool UdpServer::ZipRecvFrom(TcpEvent* tcpEvent)
{
	TcpEvent* tcpEvent2 = TcpEvent::Allocate();
	auto result = true;
	int len = RecvFrom(tcpEvent2);
	if (len <= 0)
	{
		tcpEvent2->Free();
		return false;
	}
	unsigned long sourceLen = len;
	unsigned long destLen = BuffSize - 1;
	auto ret = uncompress2((unsigned char*)tcpEvent->Buff, &destLen, (const unsigned char*)tcpEvent2->Buff, &sourceLen);
	if (ret != Z_OK)
	{
		WRITE_LOG(LogLevel::Error, "compress Failed. ret:[%d]", ret);
		result = false;
	}
	else
	{
		tcpEvent->Length += destLen;
		tcpEvent->Buff[tcpEvent->Length] = '\0';
		tcpEvent->IP = tcpEvent2->IP;
		tcpEvent->Port = tcpEvent2->Port;
		WRITE_LOG(LogLevel::Info, "UdpBase ZipRecvFrom<%s|%s>: Len:[%d], Buff:[%s]", tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->Length, tcpEvent->ReadPos);
	}
	tcpEvent2->Free();
	return ret;
}
int UdpServer::RecvFrom(TcpEvent* tcpEvent)
{
	memset(tcpEvent->Buff, 0, BuffSize);
	m_RemoteAddressLen = sizeof(sockaddr_storage);
	tcpEvent->Length = ::recvfrom(m_Socket, tcpEvent->Buff, BuffSize - 1, 0, (sockaddr*)&m_RemoteAddress, &m_RemoteAddressLen);
	if (tcpEvent->Length <= 0)
	{
		WRITE_LOG(LogLevel::Warning, "recvfrom Failed. recvLen:[%d], ErrorID:[%d]", tcpEvent->Length, GetLastError());
	}
	else
	{
		GetNameinfo((sockaddr*)&m_RemoteAddress, m_RemoteAddressLen, tcpEvent->IP, tcpEvent->Port);
		WRITE_LOG(LogLevel::Info, "UdpServer RecvFrom:<%s|%s>, recvLen:[%d], Buff:[%s]", tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->Length, tcpEvent->Buff);
	}
	return tcpEvent->Length;
}

bool UdpServer::Bind()
{
	if (::bind(m_Socket, m_BindAddressInfo->ai_addr, m_BindAddressInfo->ai_addrlen) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "Bind Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}