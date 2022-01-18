#pragma once
#include "TcpSelectBase.h"


class TcpSelectServer : public TcpSelectBase
{
public:
	TcpSelectServer();

	virtual bool Init(int family = AF_INET6) override;

protected:
	int Bind(int family);
	int Listen();
	virtual void PrepareFds() override;
	virtual void DoAccept() override;


private:
	SOCKET m_ListenSocket;
	sockaddr_storage m_RemoteAddress;
	int m_RemoteAddressLen;
};