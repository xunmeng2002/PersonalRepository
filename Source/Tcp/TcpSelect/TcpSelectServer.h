#pragma once
#include "TcpSelectBase.h"
#include "TcpServerBase.h"


class TcpSelectServer : public TcpSelectBase, public TcpServerBase
{
public:
	TcpSelectServer();
	bool Init();


protected:
	virtual void PrepareFds() override;
	virtual void DoAccept() override;


private:
	sockaddr_storage m_RemoteAddress;
	int m_RemoteAddressLen;
};