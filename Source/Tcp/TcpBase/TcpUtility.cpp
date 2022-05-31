#include "TcpUtility.h"
#include "Platform.h"
#include "Logger.h"
#include <string.h>


int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo)
{
	struct addrinfo hints;
	::memset(&hints, 0, sizeof(hints));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	auto ret = getaddrinfo(ip, port, &hints, &addrInfo);
	WRITE_LOG(LogLevel::Info, "GetAddrinfo: IP[%s] Port[%s] GetAddrinfo ret[%d]", ip, port, ret);
	return ret;
}
int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags)
{
	char ipBuff[128];
	char portBuff[32];
	auto ret = getnameinfo(sockAddr, len, ipBuff, 128, portBuff, 32, NI_NUMERICHOST);
	ip = ipBuff;
	port = portBuff;
	return ret;
}

bool SetSockUnblock(SOCKET socketID, unsigned long unblock)
{
#ifdef  WINDOWS
	if (::ioctlsocket(socketID, FIONBIO, &unblock) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "ioctlsocket FIONBIO[%d] Failed. ErrorID:[%d]", unblock, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Info, "ioctlsocket FIONBIO[%d] Success.", unblock);
#endif //  WINDOWS
#ifdef LINUX
	if (ioctl(socketID, FIONBIO, &unblock) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "ioctl FIONBIO[%d] Failed. ErrorID:[%d]", unblock, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Info, "ioctl FIONBIO[%d] Success.", unblock);
#endif // LINUX
	return true;
}
bool SetSockReuse(SOCKET socketID, int resue)
{
	if (::setsockopt(socketID, SOL_SOCKET, SO_REUSEADDR, (char*)&resue, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt SO_REUSEADDR[%d] Failed. ErrorID:[%d]", resue, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Error, "setsockopt SO_REUSEADDR[%d] Success.", resue);
	return true;
}
bool SetSockNodelay(SOCKET socketID, int nodelay)
{
	if (::setsockopt(socketID, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt TCP_NODELAY[%d] Failed. ErrorID:[%d]", nodelay, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Error, "setsockopt TCP_NODELAY[%d] Success.", nodelay);
	return true;
}
bool SetSockIPV6Only(SOCKET socketID, int ipv6Only)
{
	if (::setsockopt(socketID, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&ipv6Only, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt IPV6_V6ONLY[%d] Failed. ErrorID:[%d]", ipv6Only, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Error, "setsockopt IPV6_V6ONLY[%d] Success.", ipv6Only);
	return true;
}
bool Bind(SOCKET socketID, addrinfo* bindAddressInfo)
{
	if (::bind(socketID, bindAddressInfo->ai_addr, int(bindAddressInfo->ai_addrlen)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "Bind Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}
bool Listen(SOCKET socketID, int backLog)
{
	if (listen(socketID, backLog) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "Listen Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}