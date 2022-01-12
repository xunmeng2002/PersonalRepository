#pragma once
#include "TcpSelectBase.h"


class TcpSelectServer : public TcpSelectBase
{
public:
	TcpSelectServer();

	int SetBindAddressInfo(const char* ip, const char* port, int backLog = 5);
	virtual bool Init() override;

protected:
	int Bind();
	int Listen();
	virtual void PrepareFds() override;
	virtual void DoAccept() override;


private:
	SOCKET m_ListenSocket;
	addrinfo* m_BindAddressInfo;
	sockaddr_storage m_RemoteAddress;
	int m_RemoteAddressLen;
	int m_Backlog;
	std::string m_IP;
	std::string m_Port;
};