#pragma once
#include "SocketInit.h"
#include <string>


int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo);
int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags = NI_NUMERICHOST);

bool SetSockUnblock(SOCKET socketID, unsigned long unblock = 1);
bool SetSockReuse(SOCKET socketID, int resue = 1);
bool SetSockNodelay(SOCKET socketID, int nodelay = 1);
bool SetSockIPV6Only(SOCKET socketID, int ipv6Only = 0);
bool Bind(SOCKET socketID, addrinfo* bindAddressInfo);
bool Listen(SOCKET socketID, int backLog = 5);