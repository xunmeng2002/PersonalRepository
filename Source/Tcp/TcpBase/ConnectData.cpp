#include "ConnectData.h"
#include "Logger.h"
#include "MemCacheTemplateSingleton.h"
#include "TimeUtility.h"


ConnectData* ConnectData::Allocate(int sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	ConnectData* connectData = MemCacheTemplateSingleton<ConnectData>::GetInstance().Allocate();
	connectData->Set(sessionID, socketID, remoteIP, remotePort);
	return connectData;
}
void ConnectData::Free()
{
	closesocket(SocketID);
	MemCacheTemplateSingleton<ConnectData>::GetInstance().Free(this);
}

void ConnectData::Set(int sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort)
{
	SessionID = sessionID;
	SocketID = socketID;
	RemoteIP = remoteIP;
	RemotePort = remotePort;
	LastSendTimePoint = std::chrono::steady_clock::now();
}
void ConnectData::UpdateLastSendTime()
{
	LastSendTimePoint = std::chrono::steady_clock::now();
}
