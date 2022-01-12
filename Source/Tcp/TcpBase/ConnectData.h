#pragma once
#include "SocketInit.h"
#include "CacheList.h"
#include <mutex>
#include <string>

class ConnectData
{
public:
	static ConnectData* Allocate(int sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void Free();

	void Set(int sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);

	int SessionID;
	SOCKET SocketID;
	std::string RemoteIP;
	std::string RemotePort;
};