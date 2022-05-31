#pragma once
#include "UdpBase.h"



class UdpServer : public UdpBase
{
public:
	void SetBindAddressInfo(const char* ip, const char* port);
	virtual bool Init(bool setBroadCast);
	bool ZipRecvFrom(TcpEvent* tcpEvent);
	int RecvFrom(TcpEvent* tcpEvent);

protected:
	bool Bind();

protected:
	SOCKET  m_Socket;

	addrinfo* m_BindAddressInfo;
	std::string m_BindIP;
	std::string m_BindPort;

	sockaddr_storage m_RemoteAddress;
#ifdef WINDOWS
	int m_RemoteAddressLen;
#endif
#ifdef LINUX
	unsigned int m_RemoteAddressLen;
#endif
};

