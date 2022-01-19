#pragma once

#include "TcpIOCP.h"
#include "TcpServerBase.h"


class TcpIOCPServer : public TcpIOCP, public TcpServerBase
{
public:
	TcpIOCPServer();
	~TcpIOCPServer();
	bool Init();

protected:
	virtual void ThreadInit();

	virtual bool PostAccept();
	virtual void AcceptComplete(OverlappedData* overlappedData, int len);
};

