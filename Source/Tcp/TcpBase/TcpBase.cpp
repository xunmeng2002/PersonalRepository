#include "TcpBase.h"
#include "Logger.h"


TcpBase::TcpBase(const char* name)
	:ThreadBase(name), m_Family(AF_INET6), m_BindAddressInfoV4(nullptr), m_BindAddressInfoV6(nullptr), m_Subscriber(nullptr), m_MaxSessionID(0)
{
	m_SocketTimeOut.tv_sec = 1;
	m_SocketTimeOut.tv_usec = 0;
}
void TcpBase::Subscriber(TcpSubscriber* subscriber)
{
	m_Subscriber = subscriber;
}
void TcpBase::UnSubscriber(TcpSubscriber* subscriber)
{
	m_Subscriber = nullptr;
}
void TcpBase::SetBindAddressInfo(const char* port, const char* ipV4, const char* ipV6)
{
	m_IPV4 = ipV4;
	m_IPV6 = ipV6;
	m_Port = port;
	GetAddrinfo(ipV4, port, m_BindAddressInfoV4);
	GetAddrinfo(ipV6, port, m_BindAddressInfoV6);
}
void TcpBase::SetSocketTimeOut(int milliSeconds)
{
	m_SocketTimeOut.tv_sec = milliSeconds / 1000;
	m_SocketTimeOut.tv_usec = (milliSeconds % 1000) * 1000;
}
bool TcpBase::Init(int family)
{
	m_Family = family;
	return true;
}
void TcpBase::ThreadExit()
{
	ThreadBase::ThreadExit();
	for (auto& it : m_ConnectDatas)
	{
		NotifyDisConnect(it.second);
	}
	m_ConnectDatas.clear();
}

int TcpBase::GetAddrinfo(const char* ip, const char* port, addrinfo*& addrInfo)
{
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	auto ret = getaddrinfo(ip, port, &hints, &addrInfo);
	WRITE_LOG(LogLevel::Info, "GetAddrinfo: IP[%s] Port[%s] GetAddrinfo ret[%d]", ip, port, ret);
	return ret;
}
int TcpBase::GetNameinfo(const sockaddr* sockAddr, int len, std::string& ip, std::string& port, int flags)
{
	char ipBuff[128];
	char portBuff[32];
	auto ret = getnameinfo(sockAddr, len, ipBuff, 128, portBuff, 32, NI_NUMERICHOST);
	ip = ipBuff;
	port = portBuff;
	return ret;
}


void TcpBase::AddConnect(ConnectData* connectData)
{
	WRITE_LOG(LogLevel::Info, "New Connection. SessionID[%d], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	if (m_Subscriber)
	{
		m_Subscriber->OnConnect(connectData->SessionID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	}
	m_ConnectDatas.insert(std::make_pair(connectData->SessionID, connectData));
}
void TcpBase::RemoveConnect(int sessionID)
{
	if (m_ConnectDatas.find(sessionID) == m_ConnectDatas.end())
	{
		WRITE_LOG(LogLevel::Warning, "Connect not Exist For SessionID:[%d]", sessionID);
		return;
	}
	NotifyDisConnect(m_ConnectDatas[sessionID]);
	m_ConnectDatas.erase(sessionID);
}
ConnectData* TcpBase::GetConnect(int sessionID)
{
	if (m_ConnectDatas.find(sessionID) == m_ConnectDatas.end())
	{
		return nullptr;
	}
	return m_ConnectDatas[sessionID];
}
void TcpBase::NotifyDisConnect(ConnectData* connectData)
{
	WRITE_LOG(LogLevel::Info, "DisConnection. SessionID[%d], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	if (m_Subscriber)
	{
		m_Subscriber->OnDisConnect(connectData->SessionID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	}
	connectData->Free();
}


bool TcpBase::InitSocket(SOCKET socketID)
{
	if (SetSockReuse(socketID) == SOCKET_ERROR || SetSockUnblock(socketID) == SOCKET_ERROR || SetSockNodelay(socketID) == SOCKET_ERROR || SetSockIPV6Only(socketID) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Warning, "InitSocket Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}
int TcpBase::SetSockReuse(SOCKET socketID, int resue)
{
	int ret = setsockopt(socketID, SOL_SOCKET, SO_REUSEADDR, (char*)&resue, sizeof(int));
	WRITE_LOG(LogLevel::Info, "SetSockReuse: ret[%d]", ret);
	return ret;
}
int TcpBase::SetSockUnblock(SOCKET socketID, unsigned long unblock)
{
	auto ret = ::ioctlsocket(socketID, FIONBIO, &unblock);
	WRITE_LOG(LogLevel::Info, "SetSockUnblock: ret[%d]", ret);
	return ret;
}
int TcpBase::SetSockNodelay(SOCKET socketID, int nodelay)
{
	auto ret = ::setsockopt(socketID, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(int));
	WRITE_LOG(LogLevel::Info, "SetSockNodelay: ret[%d]", ret);
	return ret;
}
int TcpBase::SetSockIPV6Only(SOCKET socketID, int ipv6Only)
{
	auto ret = ::setsockopt(socketID, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&ipv6Only, sizeof(int));
	WRITE_LOG(LogLevel::Info, "SetSockIPV6Only: ret[%d]", ret);
	return ret;
}