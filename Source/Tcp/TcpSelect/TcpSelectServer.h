#pragma once
#include "TcpSelectBase.h"


class TcpSelectServer : public TcpSelectBase
{
public:
	TcpSelectServer();
	virtual bool Init() override;

protected:
	virtual void PrepareFds() override;
};