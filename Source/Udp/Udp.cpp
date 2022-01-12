#include "Udp.h"
#include "Logger.h"
#include "zlib.h"
#include <stdio.h>
#include <iostream>

Udp Udp::m_Instance;

Udp::Udp()
	:m_AF(AF_INET), m_Type(SOCK_DGRAM), m_Protocol(IPPROTO_UDP)
{
	m_Socket = INVALID_SOCKET;
	m_BindAddressInfo = nullptr;
	memset(&m_RemoteAddress, 0, sizeof(m_RemoteAddress));
	m_RemoteAddressLen = sizeof(m_RemoteAddress);
}
Udp::~Udp()
{
	closesocket(m_Socket);
}
Udp& Udp::GetInstance()
{
	return m_Instance;
}
void Udp::SetBindAddressInfo(const char* ip, const char* port)
{
	m_IP = ip;
	m_Port = port;
	auto ret = GetAddrinfo(ip, port, m_BindAddressInfo);
	WRITE_LOG(LogLevel::Info, "Udp SetBindAddressInfo: GetAddrinfo ret[%d]", ret);
}
void Udp::SetRemoteAddressInfo(const char* ip, const char* port)
{
	m_IP = ip;
	m_Port = port;
	auto ret = GetAddrinfo(ip, port, m_RemoteAddressInfo);
	WRITE_LOG(LogLevel::Info, "Udp SetRemoteAddressInfo GetAddrinfo ret[%d]", ret);
}
bool Udp::Init(bool setBroadCast)
{
	m_Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (m_Socket == INVALID_SOCKET)
	{
		WRITE_LOG(LogLevel::Error, "Create Udp Socket Failed.");
		Close();
		return false;
	}
	if (setBroadCast)
	{
		BOOL bBroadcast = TRUE;
		if (::setsockopt(m_Socket, SOL_SOCKET, SO_BROADCAST, (char*)&bBroadcast, sizeof(BOOL)) == SOCKET_ERROR)
		{
			WRITE_LOG(LogLevel::Error, "setsockopt SO_BROADCAST Failed.");
			Close();
			return false;
		}
	}
	auto ret = bind(m_Socket, m_BindAddressInfo->ai_addr, m_BindAddressInfo->ai_addrlen);
	if (ret == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "bind Failed. ret[%d]", ret);
		Close();
		return false;
	}
	WRITE_LOG(LogLevel::Info, "Udp Init Successed.");
	return true;
}
void Udp::Close()
{
	closesocket(m_Socket);
	m_Socket = INVALID_SOCKET;
}

int Udp::SendTo(TcpEvent* tcpEvent)
{
	auto sendLen = ::sendto(m_Socket, tcpEvent->ReadPos, tcpEvent->Length, 0, m_RemoteAddressInfo->ai_addr, m_RemoteAddressInfo->ai_addrlen);
	WRITE_LOG(LogLevel::Info, "Udp SendTo:[%s:%s], Len:[%d], Ret:[%d]", m_IP.c_str(), m_Port.c_str(), tcpEvent->Length, sendLen);
	return sendLen;
}
int Udp::RecvFrom(TcpEvent* tcpEvent)
{
	int recvLen = ::recvfrom(m_Socket, tcpEvent->Buff, BuffSize - 1, 0, (sockaddr*)&m_RemoteAddress, &m_RemoteAddressLen);
	std::string ip, port;
	auto ret = GetNameinfo((sockaddr*)&m_RemoteAddress, m_RemoteAddressLen, ip, port);
	WRITE_LOG(LogLevel::Info, "Udp RecvFrom GetNameinfo ret[%d] RecvFrom:[%s:%s], recvLen:[%d]", ret, ip.c_str(), port.c_str(), recvLen);
	tcpEvent->Length = recvLen;
	return recvLen;
}
bool Udp::ZipSendTo(TcpEvent* tcpEvent)
{
	WRITE_LOG(LogLevel::Info, "Udp ZipSendTo: Len:[%d], Buff:[%s]", tcpEvent->Length, tcpEvent->ReadPos);
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
		tcpEvent2->Length = destLen;
		result = SendTo(tcpEvent2) > 0;
	}
	tcpEvent2->Free();
	return result;
}
bool Udp::ZipRecvFrom(TcpEvent* tcpEvent)
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
		WRITE_LOG(LogLevel::Info, "Udp ZipRecvFrom: Len:[%d], Buff:[%s]", tcpEvent->Length, tcpEvent->ReadPos);
	}
	tcpEvent2->Free();
	return ret;
}

int Udp::GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo)
{
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = m_AF;
	hints.ai_socktype = m_Type;
	hints.ai_protocol = m_Protocol;
	return getaddrinfo(ip, port, &hints, &addrInfo);
}
int Udp::GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags)
{
	char ipBuff[128];
	char portBuff[32];
	auto ret = getnameinfo(sockAddr, len, ipBuff, 128, portBuff, 32, NI_NUMERICHOST);
	ip = ipBuff;
	port = portBuff;
	return ret;
}