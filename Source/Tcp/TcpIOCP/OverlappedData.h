#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#pragma once

#define MESSAGE_SIZE 64 * 1024


struct OverlappedData : public OVERLAPPED
{
    OverlappedData();
    static OverlappedData* Allocate();
    void Free();
    void Clear();

    int EventID;
    int SessionID;
    SOCKET ConnectSocket;
    WSABUF WsaBuffer;
    char Buffer[MESSAGE_SIZE];
    addrinfo* RemoteAddressInfo;
    std::string RemoteIP;
    std::string RemotePort;
};
