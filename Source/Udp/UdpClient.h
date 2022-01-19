#pragma once
#include "UdpBase.h"


class UdpClient : public UdpBase
{
public:
	virtual bool Init(bool setBroadCast);
	bool ZipSendTo(TcpEvent* tcpEvent);
	int SendTo(TcpEvent* tcpEvent);


protected:
	SOCKET m_SocketV4;
	SOCKET m_SocketV6;
	addrinfo* m_RemoteAddressInfo;
	std::string m_RemoteIP;
	std::string m_RemotePort;
};

