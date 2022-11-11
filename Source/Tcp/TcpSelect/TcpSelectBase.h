#pragma once
#include <list>
#include <map>
#include "ConnectData.h"
#include "TcpBase.h"



class TcpSelectBase : public TcpBase
{
public:
	TcpSelectBase();
	virtual void SetSocketTimeOut(int milliSeconds) override;
	virtual void HandleTcpEvent() override;
protected:
	virtual void PrepareFds();

protected:
	fd_set m_RecvFds;
	uint64_t m_MaxID;
	timeval m_SelectSocketTimeOut;
};
