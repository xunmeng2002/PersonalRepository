#include "TcpBase.h"
#include "Logger.h"


TcpBase::TcpBase(const char* name)
	:ThreadBase(name), m_Subscriber(nullptr), m_MaxSessionID(0)
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
void TcpBase::SetSocketTimeOut(int milliSeconds)
{
	m_SocketTimeOut.tv_sec = milliSeconds / 1000;
	m_SocketTimeOut.tv_usec = (milliSeconds % 1000) * 1000;
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

void TcpBase::DisConnect(int sessionID)
{
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	tcpEvent->EventID = EventDisConnect;
	tcpEvent->SessionID = sessionID;
	OnEvent(tcpEvent);
}
void TcpBase::Send(int sessionID, const char* data, int len)
{
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	tcpEvent->EventID = EventSend;
	tcpEvent->SessionID = sessionID;
	memcpy(tcpEvent->Buff, data, len);
	tcpEvent->Length = len;
	tcpEvent->Buff[len] = '\0';
	OnEvent(tcpEvent);
}
void TcpBase::Send(TcpEvent* tcpEvent)
{
	OnEvent(tcpEvent);
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
	if (!SetSockUnblock(socketID) || !SetSockReuse(socketID)|| !SetSockNodelay(socketID) || !SetSockIPV6Only(socketID))
	{
		WRITE_LOG(LogLevel::Warning, "InitSocket Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}

bool TcpBase::SetSockUnblock(SOCKET socketID, unsigned long unblock)
{
	if (::ioctlsocket(socketID, FIONBIO, &unblock) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "ioctlsocket FIONBIO[%d] Failed. ErrorID:[%d]", unblock, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Info, "ioctlsocket FIONBIO[%d] Success.", unblock);
	return true;
}
bool TcpBase::SetSockReuse(SOCKET socketID, int resue)
{
	if (::setsockopt(socketID, SOL_SOCKET, SO_REUSEADDR, (char*)&resue, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt SO_REUSEADDR[%d] Failed. ErrorID:[%d]", resue, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Error, "setsockopt SO_REUSEADDR[%d] Success.", resue);
	return true;
}
bool TcpBase::SetSockNodelay(SOCKET socketID, int nodelay)
{
	if (::setsockopt(socketID, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt TCP_NODELAY[%d] Failed. ErrorID:[%d]", nodelay, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Error, "setsockopt TCP_NODELAY[%d] Success.", nodelay);
	return true;
}
bool TcpBase::SetSockIPV6Only(SOCKET socketID, int ipv6Only)
{
	if (::setsockopt(socketID, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&ipv6Only, sizeof(int)) == SOCKET_ERROR)
	{
		WRITE_LOG(LogLevel::Error, "setsockopt IPV6_V6ONLY[%d] Failed. ErrorID:[%d]", ipv6Only, GetLastError());
		return false;
	}
	WRITE_LOG(LogLevel::Error, "setsockopt IPV6_V6ONLY[%d] Success.", ipv6Only);
	return true;
}