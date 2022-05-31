#include "UdpBase.h"
#include "Platform.h"
#include "Logger.h"
#include "zlib.h"
#include <stdio.h>
#include <iostream>
#include <string.h>


bool UdpBase::GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo)
{
	struct addrinfo hints;
	::memset(&hints, 0, sizeof(hints));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	auto ret = getaddrinfo(ip, port, &hints, &addrInfo);
	if (ret != 0)
	{
		WRITE_LOG(LogLevel::Info, "GetAddrinfo Failed. IP[%s] Port[%s] ret[%d]", ip, port, ret);
	}
	else
	{
		WRITE_LOG(LogLevel::Info, "GetAddrinfo Success. IP[%s] Port[%s] ret[%d]", ip, port, ret);
	}
	return ret == 0;
}
bool UdpBase::GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags)
{
	char ipBuff[128];
	char portBuff[32];
	auto ret = getnameinfo(sockAddr, len, ipBuff, 128, portBuff, 32, NI_NUMERICHOST);
	ip = ipBuff;
	port = portBuff;
	if (ret != 0)
	{
		WRITE_LOG(LogLevel::Info, "GetNameinfo Failed. IP[%s] Port[%s] ret[%d]", ip.c_str(), port.c_str(), ret);
	}
	else
	{
		WRITE_LOG(LogLevel::Info, "GetNameinfo Success. IP[%s] Port[%s] ret[%d]", ip.c_str(), port.c_str(), ret);
	}
	return ret == 0;
}

bool UdpBase::SetBroadcast(SOCKET socket, int broadcast)
{
	if (::setsockopt(socket, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt SO_BROADCAST[%d] Failed.ErrorID:[%d]", broadcast, GetLastError());
		return false;
	}
	return true;
}
bool UdpBase::SetSockIPV6Only(SOCKET socketID, int ipv6Only)
{
	if (::setsockopt(socketID, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&ipv6Only, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt IPV6_V6ONLY[%d] Failed. ErrorID:[%d]", ipv6Only, GetLastError());
		return false;
	}
	return true;
}