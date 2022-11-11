#include "TcpBase.h"
#include "Platform.h"
#include "Logger.h"
#include "TcpUtility.h"


TcpBase::TcpBase()
	:m_Subscriber(nullptr), m_MaxSessionID(0), m_SocketTimeOut(1000), m_ListenSocket(INVALID_SOCKET), m_RemoteAddressLen(sizeof(m_RemoteAddress))
{
	m_SocketTimeOut = 0;
}
TcpBase::~TcpBase()
{
	WRITE_LOG(LogLevel::Info, "~TcpBase() Clear All Connect");
	if (m_Subscriber)
	{
		for (auto& it : m_ConnectDatas)
		{
			m_Subscriber->OnDisConnect(it.second->SessionID, it.second->RemoteIP.c_str(), it.second->RemotePort.c_str());
			it.second->Free();
		}
	}
	m_ConnectDatas.clear();
	if (m_ListenSocket != INVALID_SOCKET)
	{
		closesocket(m_ListenSocket);
		m_ListenSocket = INVALID_SOCKET;
	}
}
void TcpBase::Subscriber(TcpSubscriber* subscriber)
{
	m_Subscriber = subscriber;
}
void TcpBase::UnSubscriber()
{
	m_Subscriber = nullptr;
}
void TcpBase::SetSocketTimeOut(int milliSeconds)
{
	m_SocketTimeOut = milliSeconds;
}
void TcpBase::SetBindAddressInfo(const char* ip, const char* port)
{
	m_BindIP = ip;
	m_BindPort = port;
	GetAddrinfo(ip, port, m_BindAddressInfo);
}
bool TcpBase::Connect(const char* ip, const char* port)
{
	auto ret = GetAddrinfo(ip, port, m_ConnectAddressInfo);
	SOCKET socketID = socket(m_ConnectAddressInfo->ai_family, m_ConnectAddressInfo->ai_socktype, m_ConnectAddressInfo->ai_protocol);
	ret = connect(socketID, m_ConnectAddressInfo->ai_addr, int(m_ConnectAddressInfo->ai_addrlen));
	WRITE_LOG(LogLevel::Info, "Connect Server:IP:[%s] Port[%s] ret[%d]", ip, port, ret);
	if (ret < 0)
	{
		WRITE_LOG(LogLevel::Info, "Connect Server Failed. IP:[%s] Port[%s] ret[%d] Errno[%d]", ip, port, ret, errno);
		return false;
	}
	WRITE_LOG(LogLevel::Info, "Connect Server Success. IP:[%s] Port[%s] ret[%d]", ip, port, ret);
	InitSocket(socketID);
	int sessionID = ++m_MaxSessionID;
	ConnectData* connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
	AddConnect(connectData);
	return true;
}
void TcpBase::DisConnect(int sessionID)
{
	std::lock_guard<std::mutex> guard(m_DisConnectSessionMutex);
	m_DisConnectSessions.push_back(sessionID);
}
bool TcpBase::Send(int sessionID, const char* data, int len)
{
	auto connectData = GetConnect(sessionID);
	if (!connectData)
	{
		return false;
	}
	int totalSendLen = 0;
	int sendLen = 0;
	while (totalSendLen < len)
	{
		sendLen = send(connectData->SocketID, data + totalSendLen, len - totalSendLen, 0);
		if (sendLen <= 0)
		{
			WRITE_LOG(LogLevel::Info, "DisConnect For Send. SessionID[%d], Len:[%d]", connectData->SessionID, len);
			DisConnect(connectData->SessionID);
			return false;
		}
		else
		{
			WRITE_LOG(LogLevel::Info, "OnSend: SessionID[%d], Len[%d], [%s]", connectData->SessionID, sendLen, data + totalSendLen);
			totalSendLen += sendLen;
		}
	}
	return true;
}
bool TcpBase::Send(TcpEvent* tcpEvent)
{
	auto connectData = GetConnect(tcpEvent->SessionID);
	if (!connectData)
	{
		return false;
	}
	int totalSendLen = 0;
	int sendLen = 0;
	while (totalSendLen < tcpEvent->Length)
	{
		sendLen = send(connectData->SocketID, tcpEvent->ReadPos + totalSendLen, tcpEvent->Length - totalSendLen, 0);
		if (sendLen <= 0)
		{
			WRITE_LOG(LogLevel::Info, "DisConnect For Send. SessionID[%d], Len:[%d]", tcpEvent->SessionID, tcpEvent->Length);
			DisConnect(tcpEvent->SessionID);
			return false;;
		}
		else
		{
			WRITE_LOG(LogLevel::Info, "OnSend: SessionID[%d], Len[%d], [%s]", tcpEvent->SessionID, sendLen, tcpEvent->ReadPos + totalSendLen);
			totalSendLen += sendLen;
		}
	}
	return true;
}

void TcpBase::DoDisConnect()
{
	std::lock_guard<std::mutex> guard(m_DisConnectSessionMutex);
	for (auto sessionID : m_DisConnectSessions)
	{
		RemoveConnect(GetConnect(sessionID));
	}
	m_DisConnectSessions.clear();
}
void TcpBase::DoAccept()
{
	for (int i = 0; i < 5; i++)
	{
		SOCKET socketID = accept(m_ListenSocket, (sockaddr*)&m_RemoteAddress, &m_RemoteAddressLen);
		if (socketID == INVALID_SOCKET)
		{
			break;
		}
		SetSockNodelay(socketID);

		auto sessionID = ++m_MaxSessionID;
		std::string ip, port;
		auto ret = GetNameinfo((sockaddr*)&m_RemoteAddress, m_RemoteAddressLen, ip, port);
		WRITE_LOG(LogLevel::Info, "accept: SessionID[%d], SocketID[%lld], RemoteIP[%s], RemotePort[%s]", sessionID, socketID, ip.c_str(), port.c_str());

		auto connectData = ConnectData::Allocate(sessionID, socketID, ip, port);
		AddConnect(connectData);
	}
}
void TcpBase::DoRecv(ConnectData* connectData)
{
	TcpEvent* tcpEvent = TcpEvent::Allocate();
	int len = recv(connectData->SocketID, tcpEvent->Buff, BuffSize - 1, 0);
	if (len <= 0)
	{
		WRITE_LOG(LogLevel::Info, "OnRecv Failed. SessionID[%d], len[%d] DisConnect", connectData->SessionID, len);
		tcpEvent->Free();
		DisConnect(connectData->SessionID);
	}
	else
	{
		tcpEvent->Buff[len] = '\0';
		WRITE_LOG(LogLevel::Debug, "OnRecv: SessionID[%d], len[%d], [%s]", connectData->SessionID, len, tcpEvent->Buff);
		tcpEvent->EventID = EventRecv;
		tcpEvent->SessionID = connectData->SessionID;
		tcpEvent->IP = connectData->RemoteIP;
		tcpEvent->Port = connectData->RemotePort;
		tcpEvent->Length = len;
		if (m_Subscriber)
		{
			m_Subscriber->OnRecv(tcpEvent);
		}
	}
}
void TcpBase::AddConnect(ConnectData* connectData)
{
	WRITE_LOG(LogLevel::Info, "New Connection. SessionID[%d], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	{
		std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
		m_ConnectDatas.insert(std::make_pair(connectData->SessionID, connectData));
	}
	if (m_Subscriber)
	{
		m_Subscriber->OnConnect(connectData->SessionID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	}
}
void TcpBase::RemoveConnect(ConnectData* connectData)
{
	WRITE_LOG(LogLevel::Info, "RemoveConnect. SessionID[%d], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	if (m_Subscriber)
	{
		m_Subscriber->OnDisConnect(connectData->SessionID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	}
	std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
	m_ConnectDatas.erase(connectData->SessionID);
	connectData->Free();
}
ConnectData* TcpBase::GetConnect(int sessionID)
{
	std::lock_guard<std::mutex> guard(m_ConnectDataMutex);
	if (m_ConnectDatas.find(sessionID) == m_ConnectDatas.end())
	{
		WRITE_LOG(LogLevel::Warning, "Connect not Exist For SessionID:[%d]", sessionID);
		return nullptr;
	}
	return m_ConnectDatas[sessionID];
}


bool TcpBase::InitSocket(SOCKET socketID)
{
	if (!SetSockUnblock(socketID) || !SetSockReuse(socketID)|| !SetSockNodelay(socketID))
	{
		WRITE_LOG(LogLevel::Warning, "InitSocket Failed. ErrorID:[%d]", GetLastError());
		return false;
	}
	return true;
}
SOCKET TcpBase::PrepareSocket(int family)
{
	auto socketID = socket(family, SOCK_STREAM, IPPROTO_TCP);
	if (!InitSocket(socketID))
	{
		closesocket(socketID);
		return INVALID_SOCKET;
	}
	return socketID;
}
