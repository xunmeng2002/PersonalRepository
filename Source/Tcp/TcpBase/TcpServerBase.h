#pragma once
#include "SocketInit.h"
#include <string>

class TcpServerBase
{
public:
	TcpServerBase();
	~TcpServerBase();
	void SetBindAddressInfo(const char* ip, const char* port);

protected:
	virtual bool Bind();
	virtual bool Listen(int backLog = 5);

protected:
	addrinfo* m_BindAddressInfo;
	std::string m_BindIP;
	std::string m_BindPort;

	SOCKET m_ListenSocket;
};


