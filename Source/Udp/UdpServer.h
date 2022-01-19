#pragma once
#include "UdpBase.h"



class UdpServer : public UdpBase
{
public:
	void SetBindAddressInfo(const char* port, const char* ip);
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
	int m_RemoteAddressLen;
};

