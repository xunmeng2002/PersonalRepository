#pragma once
#include "TcpSelectBase.h"


class TcpSelectServer : public TcpSelectBase
{
public:
	TcpSelectServer();
	void SetBindAddressInfo(const char* ip, const char* port);
	virtual bool Init() override;


protected:
	virtual void PrepareFds() override;
	virtual void DoAccept() override;


private:
	SOCKET m_ListenSocket;

	addrinfo* m_BindAddressInfo;
	std::string m_BindIP;
	std::string m_BindPort;

	sockaddr_storage m_RemoteAddress;
	int m_RemoteAddressLen;
};