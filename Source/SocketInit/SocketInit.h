#pragma once
#ifdef WINDOWS
#include <Ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#endif // WINDOWS
#ifdef LINUX
#include <arpa/inet.h>
#include <netdb.h>
#endif // LINUX


#ifdef LINUX
typedef unsigned long long SOCKET;
#endif // LINUX

class SocketInit
{
public:
	SocketInit();
	virtual ~SocketInit();
};

