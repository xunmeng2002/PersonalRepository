#include "TcpIOCPServer.h"
#include "Logger.h"
#include "IOCompletePort.h"
#include "SocketApi.h"


#define EXIT_CODE 0
#define MAX_ACCPET_NUM 5


TcpIOCPServer::TcpIOCPServer()
    :TcpIOCP("TcpIOCPServer")
{

}
TcpIOCPServer::~TcpIOCPServer()
{
}
bool TcpIOCPServer::Init()
{
    if (!TcpIOCP::Init())
    {
        return false;
    }
    m_ListenSocket = PrepareSocket(m_BindAddressInfo->ai_family);
    if (m_ListenSocket == INVALID_SOCKET)
    {
        return false;
    }
    if (!Bind())
    {
        return false;
    }
    if (!AssociateDevice(m_ListenSocket))
    {
        return false;
    }
    return Listen();
}
void TcpIOCPServer::ThreadInit()
{
    ThreadBase::ThreadInit();
    for (auto i = 0; i < MAX_ACCPET_NUM; i++)
    {
        if (!PostAccept())
        {
            WRITE_LOG(LogLevel::Debug, "ThreadInit PostAccept Failed.");
            break;
        }
    }
}


bool TcpIOCPServer::PostAccept()
{
    auto socket = WSASocket(m_BindAddressInfo->ai_family, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (socket == INVALID_SOCKET)
    {
        WRITE_LOG(LogLevel::Error, "CreateSocket Failed. ErrorID:[%d]", GetLastError());
        OnEventPostAccept();
        return false;
    }

    OverlappedData* overlappedData = OverlappedData::Allocate();
    overlappedData->EventID = EventAccept;
    overlappedData->SessionID = ++m_MaxSessionID;
    overlappedData->ConnectSocket = socket;
    overlappedData->WsaBuffer.len = sizeof(overlappedData->Buffer);
    overlappedData->WsaBuffer.buf = overlappedData->Buffer;
    memset(overlappedData->Buffer, 0, sizeof(overlappedData->Buffer));

    WRITE_LOG(LogLevel::Info, "PostAccept SessionID:[%d] SOCKET:[%lld].", overlappedData->SessionID, overlappedData->ConnectSocket);
    DWORD transBytes = 0;
    if (!SocketApi::GetInstance().AcceptEx(m_BindAddressInfo->ai_family, m_ListenSocket, overlappedData->ConnectSocket, overlappedData->WsaBuffer.buf,
        0, sizeof(sockaddr_storage), sizeof(sockaddr_storage), &transBytes, (LPOVERLAPPED)overlappedData) && GetLastError() != ERROR_IO_PENDING)
    {
        WRITE_LOG(LogLevel::Error, "Call AcceptEx Failed. Socket:[%lld]", overlappedData->ConnectSocket);
        WRITE_ERROR_LOG(GetLastError(), "Call AcceptEx Failed.");

        closesocket(overlappedData->ConnectSocket);
        overlappedData->Free();

        OnEventPostAccept();
        return false;
    }
    return true;
}
void TcpIOCPServer::AcceptComplete(OverlappedData* overlappedData, int len)
{
    sockaddr* localAddr = nullptr;
    sockaddr* remoteAddr = nullptr;
    int remoteLen = sizeof(sockaddr_storage), localLen = sizeof(sockaddr_storage);
    SocketApi::GetInstance().GetAcceptExSockAddrs(m_BindAddressInfo->ai_family, overlappedData->WsaBuffer.buf,
        0, sizeof(sockaddr_storage), sizeof(sockaddr_storage), &localAddr, &localLen, &remoteAddr, &remoteLen);
    std::string localIP, localPort, remoteIP, remotePort;
    GetNameinfo(localAddr, localLen, localIP, localPort);
    GetNameinfo(remoteAddr, remoteLen, remoteIP, remotePort);
    WRITE_LOG(LogLevel::Info, "AcceptComplete: Local<%s:%s> Remote<%s:%s> SOCKET:[%lld] Len:[%d], WSALen:[%d].",
        localIP.c_str(), localPort.c_str(), remoteIP.c_str(), remotePort.c_str(), overlappedData->ConnectSocket, len, overlappedData->WsaBuffer.len);
    GetAddrinfo(remoteIP.c_str(), remotePort.c_str(), overlappedData->RemoteAddressInfo);
    overlappedData->RemoteIP = remoteIP;
    overlappedData->RemotePort = remotePort;

    if (!IOCompletePort::GetInstance().AssociateDevice((HANDLE)overlappedData->ConnectSocket, overlappedData->ConnectSocket))
    {
        WRITE_LOG(LogLevel::Error, "Associate CompletionPort Failed, SessionID:[%d] Socket:[%lld]", overlappedData->SessionID, overlappedData->ConnectSocket);
    }
    ConnectComplete(overlappedData, len);
    PostAccept();
}

