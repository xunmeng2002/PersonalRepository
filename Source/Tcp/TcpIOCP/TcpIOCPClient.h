#pragma once

#include "TcpIOCP.h"


class TcpIOCPClient :public TcpIOCP
{
public:
	TcpIOCPClient();
	~TcpIOCPClient();

	virtual void Connect(const char* ip, const char* port) override;

protected:
	virtual bool PostConnect(const char* ip, const char* port) override;
};