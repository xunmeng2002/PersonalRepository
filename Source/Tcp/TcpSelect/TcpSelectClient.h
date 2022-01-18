#pragma once
#include "TcpSelectBase.h"
#include <list>


class TcpSelectClient : public TcpSelectBase
{
public:
	TcpSelectClient();

	virtual void Connect(const char* ip, const char* port) override;

protected:
	virtual void DoConnect(const std::string& ip, const std::string& port) override;
	void CheckConnect();

private:
	fd_set m_ConnectFds;
	std::list<ConnectData*> m_ConnectingSocket;
	addrinfo* m_ConnectAddressInfo;
};