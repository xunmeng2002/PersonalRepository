#include "TcpSelectClient.h"
#include "TcpUtility.h"
#include "Logger.h"




void func()
{
//	auto ret = GetAddrinfo(ip, port, m_ConnectAddressInfo);
//	SOCKET socketID = socket(m_ConnectAddressInfo->ai_family, m_ConnectAddressInfo->ai_socktype, m_ConnectAddressInfo->ai_protocol);
//	if (!InitSocket(socketID))
//	{
//		return false;
//	}
//	ret = connect(socketID, m_ConnectAddressInfo->ai_addr, int(m_ConnectAddressInfo->ai_addrlen));
//	WRITE_LOG(LogLevel::Info, "Connect Server:IP:[%s] Port[%s] ret[%d]", ip, port, ret);
//
//#ifdef WINDOWS
//	if (ret == SOCKET_ERROR && WSAGetLastError() != WSAEWOULDBLOCK)
//	{
//		closesocket(socketID);
//		return false;
//	}
//#else
//	if (ret == -1 && errno != EINTR && errno != EINPROGRESS)
//	{
//		closesocket(socketID);
//		return false;
//	}
//#endif
//	FD_ZERO(&m_ConnectFds);
//	FD_SET(socketID, &m_ConnectFds);
//	ret = select(socketID + 1, nullptr, &m_ConnectFds, nullptr, &m_ConnectTimeOut);
//	WRITE_LOG(LogLevel::Info, "Connect Select: ret[%d]\n", ret);
//	bool connected = false;
//	if (ret <= 0 || !FD_ISSET(socketID, &m_ConnectFds))
//	{
//		return  false;
//	}
//#ifdef LINUX
//	int err;
//	socklen_t len = static_cast<socklen_t>(sizeof err);
//	if (::getsockopt(socketID, SOL_SOCKET, SO_ERROR, &err, &len) < 0)
//	{
//		return false;
//	}
//	else if (err != 0)
//	{
//		return false;
//		WRITE_LOG(LogLevel::Info, "Connect Failed: errno[%d]\n", err);
//	}
//#endif
//	int sessionID = ++m_MaxSessionID;
//	ConnectData* connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
//	AddConnect(connectData);
//	return true;
}