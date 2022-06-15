#pragma once
#include "TcpSelectBase.h"
#include <list>


class TcpSelectClient : public TcpSelectBase
{
public:
	TcpSelectClient();

	void SetConnectTimeOut(int milliSeconds);
	virtual void Connect(const char* ip, const char* port) override;

protected:
	virtual void CheckConnect() override;

private:
	fd_set m_ConnectFds;
	std::list<ConnectData*> m_ConnectingSocket;
	addrinfo* m_ConnectAddressInfo;

	timeval m_ConnectTimeOut;
};