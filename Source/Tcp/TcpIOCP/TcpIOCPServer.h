#pragma once

#include "TcpIOCP.h"


class TcpIOCPServer : public TcpIOCP
{
public:
	TcpIOCPServer();
	~TcpIOCPServer();
	virtual bool Init(int family) override;

protected:
	virtual void ThreadInit();

	virtual bool PostAccept();
	virtual void AcceptComplete(OverlappedData* overlappedData, int len);

	bool Listen(int backLog = 5);

private:
	SOCKET m_ListenSocket;
};

