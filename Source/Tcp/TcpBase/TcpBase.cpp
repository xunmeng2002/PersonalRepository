#include "TcpBase.h"
#include "Logger.h"
#include "TcpUtility.h"


TcpBase::TcpBase()
	:m_Subscriber(nullptr), m_MaxSessionID(0)
{
	m_SocketTimeOut.tv_sec = 1;
	m_SocketTimeOut.tv_usec = 0;
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
	m_SocketTimeOut.tv_sec = milliSeconds / 1000;
	m_SocketTimeOut.tv_usec = (milliSeconds % 1000) * 1000;
}



void TcpBase::AddConnect(ConnectData* connectData)
{
	m_ConnectDatas.insert(std::make_pair(connectData->SessionID, connectData));
	WRITE_LOG(LogLevel::Info, "New Connection. SessionID[%d], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	if (m_Subscriber)
	{
		m_Subscriber->OnConnect(connectData->SessionID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
	}
}
void TcpBase::RemoveConnect(int sessionID)
{
	if (auto connectData = GetConnect(sessionID))
	{
		WRITE_LOG(LogLevel::Info, "DisConnection. SessionID[%d], Socket[%lld], RemoteIP[%s], RemotePort[%s]", connectData->SessionID, connectData->SocketID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
		if (m_Subscriber)
		{
			m_Subscriber->OnDisConnect(connectData->SessionID, connectData->RemoteIP.c_str(), connectData->RemotePort.c_str());
		}
		connectData->Free();
	}
	m_ConnectDatas.erase(sessionID);
}
ConnectData* TcpBase::GetConnect(int sessionID)
{
	if (m_ConnectDatas.find(sessionID) == m_ConnectDatas.end())
	{
		WRITE_LOG(LogLevel::Warning, "Connect not Exist For SessionID:[%d]", sessionID);
		return nullptr;
	}
	return m_ConnectDatas[sessionID];
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
