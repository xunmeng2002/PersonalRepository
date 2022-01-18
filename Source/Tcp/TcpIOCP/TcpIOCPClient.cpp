#include "TcpIOCPClient.h"
#include "Logger.h"
#include "SocketApi.h"


TcpIOCPClient::TcpIOCPClient()
    :TcpIOCP("TcpIOCPClient")
{

}
TcpIOCPClient::~TcpIOCPClient()
{

}

void TcpIOCPClient::Connect(const char* ip, const char* port)
{
    TcpEvent* tcpEvent = TcpEvent::Allocate();
    tcpEvent->EventID = EventConnect;
    tcpEvent->IP = ip;
    tcpEvent->Port = port;
    OnEvent(tcpEvent);
}

bool TcpIOCPClient::PostConnect(const char* ip, const char* port)
{
    OverlappedData* overlappedData = OverlappedData::Allocate();
    auto ret = GetAddrinfo(ip, port, overlappedData->RemoteAddressInfo);
    if (ret != 0)
    {
        overlappedData->Free();
        return false;
    }
    overlappedData->EventID = EventConnect;
    overlappedData->SessionID = ++m_MaxSessionID;
    overlappedData->ConnectSocket = PrepareSocket(overlappedData->RemoteAddressInfo->ai_family);
    if (overlappedData->ConnectSocket == INVALID_SOCKET)
    {
        closesocket(overlappedData->ConnectSocket);
        overlappedData->Free();
        return false;
    }
    if (!Bind(overlappedData->ConnectSocket, overlappedData->RemoteAddressInfo->ai_family))
    {
        closesocket(overlappedData->ConnectSocket);
        overlappedData->Free();
        return false;
    }
    if (!AssociateDevice(overlappedData->ConnectSocket))
    {
        closesocket(overlappedData->ConnectSocket);
        overlappedData->Free();
        return false;
    }
    overlappedData->WsaBuffer.len = sizeof(overlappedData->Buffer);
    overlappedData->WsaBuffer.buf = overlappedData->Buffer;
    overlappedData->RemoteIP = ip;
    overlappedData->RemotePort = port;
    memset(overlappedData->Buffer, 0, sizeof(overlappedData->Buffer));
    
    DWORD transBytes = 0;
    if (!SocketApi::GetInstance().ConnectEx(overlappedData->RemoteAddressInfo->ai_family, overlappedData->ConnectSocket, overlappedData->RemoteAddressInfo->ai_addr, overlappedData->RemoteAddressInfo->ai_addrlen,
        nullptr, 0, &transBytes, overlappedData) && WSAGetLastError() != ERROR_IO_PENDING)
    {
        WRITE_ERROR_LOG(WSAGetLastError(), "Call ConnectEx Failed.");
        return false;
    }
    return true;
}
