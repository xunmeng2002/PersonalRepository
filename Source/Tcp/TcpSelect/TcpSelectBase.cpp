#include "TcpSelectBase.h"
#include "Logger.h"
#include "Event.h"
#include "TcpUtility.h"
#include <string.h>


TcpSelectBase::TcpSelectBase()
{
	FD_ZERO(&m_RecvFds);
	m_MaxID = 0;
}

void TcpSelectBase::SetSocketTimeOut(int milliSeconds)
{
	m_SocketTimeOut = milliSeconds;
	m_SelectSocketTimeOut.tv_sec = milliSeconds / 1000;
	m_SelectSocketTimeOut.tv_usec = (milliSeconds % 1000) * 1000;
}
void TcpSelectBase::HandleTcpEvent()
{
	DoDisConnect();
	PrepareFds();
	::select(int(m_MaxID + 1), &m_RecvFds, nullptr, nullptr, &m_SelectSocketTimeOut);
	if (FD_ISSET(m_ListenSocket, &m_RecvFds))
	{
		DoAccept();
	}
	for (auto& it : m_ConnectDatas)
	{
		auto connectData = it.second;
		if (FD_ISSET(connectData->SocketID, &m_RecvFds))
		{
			DoRecv(connectData);
		}
	}
}

void TcpSelectBase::PrepareFds()
{
	FD_ZERO(&m_RecvFds);
	m_MaxID = 0;
	for (auto& it : m_ConnectDatas)
	{
		FD_SET(it.second->SocketID, &m_RecvFds);
		if (it.second->SocketID > m_MaxID)
		{
			m_MaxID = it.second->SocketID;
		}
	}
}
