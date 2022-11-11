#pragma once
#include "SocketInit.h"
#include <mutex>
#include <string>
#include <chrono>

class ConnectData
{
public:
	static ConnectData* Allocate(int sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void Free();

	void Set(int sessionID, const SOCKET& socketID, const std::string& remoteIP, const std::string& remotePort);
	void UpdateLastSendTime();


	int SessionID;
	SOCKET SocketID;
	std::string RemoteIP;
	std::string RemotePort;
	std::chrono::steady_clock::time_point LastSendTimePoint;
};