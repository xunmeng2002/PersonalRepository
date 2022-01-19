#pragma once
#include "SocketInit.h"
#include "Event.h"

class UdpBase
{
protected:
	bool GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo);
	bool GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags = NI_NUMERICHOST);	
	bool SetBroadcast(SOCKET socket, int broadcast);
	bool SetSockIPV6Only(SOCKET socketID, int ipv6Only = 0);
};

