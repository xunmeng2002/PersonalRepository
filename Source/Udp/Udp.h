#pragma once
#include "SocketInit.h"
#include "Event.h"

class Udp
{
	Udp();
	~Udp();
public:
	static Udp& GetInstance();
	void SetBindAddressInfo(const char* ip = "127.0.0.1", const char* port = "");
	void SetRemoteAddressInfo(const char* ip, const char* port);
	bool Init(bool setBroadCast);
	void Close();
	int SendTo(TcpEvent* tcpEvent);
	int RecvFrom(TcpEvent* tcpEvent);
	bool ZipSendTo(TcpEvent* tcpEvent);
	bool ZipRecvFrom(TcpEvent* tcpEvent);

private:
	int GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo);
	int GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags = NI_NUMERICHOST);


private:
	static Udp m_Instance;
	int m_AF;
	int m_Type;
	int m_Protocol;

	SOCKET  m_Socket;

	addrinfo* m_RemoteAddressInfo;
	addrinfo* m_BindAddressInfo;
	sockaddr_storage m_RemoteAddress;
	int m_RemoteAddressLen;
	std::string m_IP;
	std::string m_Port;
};

