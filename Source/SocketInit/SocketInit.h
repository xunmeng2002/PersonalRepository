#pragma once
#ifdef WINDOWS
#include <Ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#endif // WINDOWS
#ifdef LINUX
#include <arpa/inet.h>
#include <netdb.h>
#include<unistd.h>
#include <netinet/tcp.h>
#include <sys/ioctl.h>

typedef unsigned long long SOCKET;
#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)

#define closesocket close
#endif // LINUX

class SocketInit
{
public:
	SocketInit();
	virtual ~SocketInit();
};

