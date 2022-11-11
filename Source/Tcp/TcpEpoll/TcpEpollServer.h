#pragma once
#include "TcpEpollBase.h"


class TcpEpollServer : public TcpEpollBase
{
public:
	TcpEpollServer();
	~TcpEpollServer();

	virtual bool Init() override;

protected:
	virtual void DoAccept() override;
};
