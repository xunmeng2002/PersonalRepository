#include "UdpClient.h"
#include "Logger.h"
#include "zlib.h"


bool UdpClient::SetRemoteAddress(const char* ip, const char* port)
{
	m_RemoteIP = ip;
	m_RemotePort = port;
	if (!GetAddrinfo(ip, port, m_RemoteAddressInfo))
	{
		return false;
	}
	return true;
}
bool UdpClient::Init(bool setBroadCast)
{
	m_SocketV4 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	m_SocketV6 = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
	if (setBroadCast)
	{
		if (!SetBroadcast(m_SocketV4, setBroadCast) || !SetBroadcast(m_SocketV6, setBroadCast))
		{
			return false;
		}
	}
	return true;
}
bool UdpClient::ZipSendTo(TcpEvent* tcpEvent)
{
	WRITE_LOG(LogLevel::Info, "UdpClient ZipSendTo:<%s|%s>, Len:[%d], Buff:[%s]", tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->Length, tcpEvent->ReadPos);
	TcpEvent* tcpEvent2 = TcpEvent::Allocate();
	unsigned long destLen = BuffSize;
	auto ret = compress2((unsigned char*)tcpEvent2->Buff, &destLen, (unsigned char*)tcpEvent->Buff, tcpEvent->Length, Z_BEST_SPEED);
	auto result = true;
	if (ret != Z_OK)
	{
		WRITE_LOG(LogLevel::Error, "compress Failed. ret:[%d]", ret);
		result = false;
	}
	else
	{
		tcpEvent2->IP = tcpEvent->IP;
		tcpEvent2->Port = tcpEvent->Port;
		tcpEvent2->Length = destLen;
		result = SendTo(tcpEvent2) > 0;
	}
	tcpEvent2->Free();
	return result;
}
int UdpClient::SendTo(TcpEvent* tcpEvent)
{
	if (!tcpEvent->IP.empty() && !GetAddrinfo(tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), m_RemoteAddressInfo))
	{
		return 0;
	}
	int sendLen = 0;
	if (m_RemoteAddressInfo->ai_family == AF_INET)
	{
		sendLen = ::sendto(m_SocketV4, tcpEvent->ReadPos, tcpEvent->Length, 0, m_RemoteAddressInfo->ai_addr, m_RemoteAddressInfo->ai_addrlen);
	}
	else
	{
		sendLen = ::sendto(m_SocketV6, tcpEvent->ReadPos, tcpEvent->Length, 0, m_RemoteAddressInfo->ai_addr, m_RemoteAddressInfo->ai_addrlen);
	}
	if (sendLen <= 0)
	{
		WRITE_LOG(LogLevel::Info, "UdpClient SendTo:<%s|%s> Failed. Len:[%d], SendLen:[%d], ErrorID:[%d]", tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->Length, sendLen, GetLastError());
	}
	else
	{
		WRITE_LOG(LogLevel::Info, "UdpClient SendTo:<%s|%s>, Len:[%d], SendLen:[%d]", tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->Length, sendLen);
	}
	return sendLen;
}