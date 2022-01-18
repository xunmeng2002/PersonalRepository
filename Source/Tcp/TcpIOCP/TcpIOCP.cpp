#include "TcpIOCP.h"
#include "Logger.h"
#include "Logger.h"
#include "SocketApi.h"
#include "MemCacheTemplate.h"
#include "IOCompletePort.h"
#include <assert.h>


#define EXIT_CODE 0


TcpIOCP::TcpIOCP(const char* name)
    :TcpBase(name), m_IOWaitTime(1000)
{

}
TcpIOCP::~TcpIOCP()
{

}

void TcpIOCP::SetSocketTimeOut(int milliSeconds)
{
    TcpBase::SetSocketTimeOut(milliSeconds);
    m_IOWaitTime = milliSeconds;
}
bool TcpIOCP::Init(int family)
{
    m_Family = family;
    auto sockV4 = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (!SocketApi::GetInstance().InitV4(sockV4))
    {
        return false;
    }
    auto sockV6 = WSASocket(AF_INET6, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (!SocketApi::GetInstance().InitV6(sockV6))
    {
        return false;
    }
    if (!IOCompletePort::GetInstance().Create())
    {
        WRITE_ERROR_LOG(LogLevel::Error, "Create IOCompletePort Failed.");
        return false;
    }
    return true;
}
void TcpIOCP::Stop()
{
    IOCompletePort::GetInstance().PostStatus(0, (DWORD)EXIT_CODE, NULL);
    m_ShouldRun.store(false);
}

void TcpIOCP::DisConnect(int sessionID)
{
    TcpEvent* tcpEvent = TcpEvent::Allocate();
    tcpEvent->EventID = EventDisConnect;
    tcpEvent->SessionID = sessionID;
    OnEvent(tcpEvent);
}
void TcpIOCP::Send(int sessionID, const char* data, int len)
{
    TcpEvent* tcpEvent = TcpEvent::Allocate();
    tcpEvent->EventID = EventSend;
    tcpEvent->SessionID = sessionID;
    memcpy(tcpEvent->Buff, data, len);
    tcpEvent->Length = len;
    tcpEvent->Buff[len] = '\0';
    OnEvent(tcpEvent);
}
void TcpIOCP::Send(TcpEvent* tcpEvent)
{
    OnEvent(tcpEvent);
}
void TcpIOCP::OnEventPostAccept()
{
    TcpEvent* tcpEvent = TcpEvent::Allocate();
    tcpEvent->EventID = EventAccept;
    OnEvent(tcpEvent);
}


void TcpIOCP::Run()
{
    HandleEvent();
    HandleCompletePortEvent();
}
void TcpIOCP::HandleEvent()
{
    Event* event = nullptr;
    TcpEvent* tcpEvent = nullptr;
    while (event = GetEvent())
    {
        switch (event->EventID)
        {
        case EventConnect:
        {
            tcpEvent = (TcpEvent*)event;
            PostConnect(tcpEvent->IP.c_str(), tcpEvent->Port.c_str());
            break;
        }
        case EventDisConnect:
        {
            tcpEvent = (TcpEvent*)event;
            PostDisConnect(tcpEvent->SessionID);
            break;
        }
        case EventAccept:
        {
            PostAccept();
            break;
        }
        case EventSend:
        {
            PostSend((TcpEvent*)event);
            break;
        }
        }
        event->Free();
    }
}
void TcpIOCP::HandleCompletePortEvent()
{
    DWORD len;
    SOCKET socket;
    OverlappedData* overlappedData;

    auto bOK = IOCompletePort::GetInstance().GetStatus(&len, (PULONG_PTR)&socket, (LPOVERLAPPED*)&overlappedData, m_IOWaitTime);
    WRITE_LOG(LogLevel::Info, "CompletionKey:[%d], Len:[%d], Ret:[%d].", socket, len, bOK);
    
    if (!bOK)
    {
        WRITE_LOG(LogLevel::Warning, "GetQueuedCompletionStatus Failed. ErrorID:[%d] CompetionKey:[%ull].", GetLastError(), socket);
        if (overlappedData != nullptr)
        {
            if (overlappedData->EventID == EventConnect || overlappedData->EventID == EventAccept)
            {
                NotifyDisConnect(ConnectData::Allocate(overlappedData->SessionID, overlappedData->ConnectSocket, overlappedData->RemoteIP, overlappedData->RemotePort));
            }
            else
            {
                PostDisConnect(overlappedData->SessionID);
            }
            overlappedData->Free();
        }
        return;
    }
    if (overlappedData == nullptr)
    {
        WRITE_LOG(LogLevel::Debug, "CompetionKey:[%d], OverlappedData is null.", socket);
        return;
    }
    if (len == 0 && (overlappedData->EventID == EventSend || overlappedData->EventID == EventRecv))
    {
        WRITE_LOG(LogLevel::Debug, "Disconnect SOCKET:[%lld].", overlappedData->ConnectSocket);
        PostDisConnect(overlappedData->SessionID);
        overlappedData->Free();
        return;
    }

    switch (overlappedData->EventID)
    {
    case EventConnect:
        ConnectComplete(overlappedData, len);
        break;
    case EventDisConnect:
        DisConnectComplete(overlappedData, len);
        break;
    case EventAccept:
        AcceptComplete(overlappedData, len);
        break;
    case EventSend:
        SendComplete(overlappedData, len);
        break;
    case EventRecv:
        RecvComplete(overlappedData, len);
        break;
    default:
        WRITE_LOG(LogLevel::Error, "INVALID EventID:[%d] SOCKET:[%lld].", overlappedData->EventID, overlappedData->ConnectSocket);
        assert(false);
        break;
    }
}


bool TcpIOCP::PostDisConnect(int sessionID)
{
    auto connectData = GetConnect(sessionID);
    if (connectData == nullptr)
    {
        WRITE_LOG(LogLevel::Warning, "Get ConnectData Failed while PostDisConnect For SessionID:[%d].", sessionID);
        return false;
    }

    WRITE_LOG(LogLevel::Info, "PostDisConnect For SessionID:[%d], Socket:[%lld].", sessionID, connectData->SocketID);
    auto overlappedData = OverlappedData::Allocate();
    overlappedData->EventID = EventDisConnect;
    overlappedData->SessionID = sessionID;
    overlappedData->ConnectSocket = connectData->SocketID;
    GetAddrinfo(connectData->RemoteIP.c_str(), connectData->RemotePort.c_str(), overlappedData->RemoteAddressInfo);
    overlappedData->RemoteIP = connectData->RemoteIP;
    overlappedData->RemotePort = connectData->RemotePort;
    if (!SocketApi::GetInstance().DisconnectEx(overlappedData->RemoteAddressInfo->ai_family, overlappedData->ConnectSocket, overlappedData, TF_REUSE_SOCKET, 0) && WSAGetLastError() != ERROR_IO_PENDING)
    {
        WRITE_ERROR_LOG(WSAGetLastError(), "Call DisconnectEx Failed.");
        return false;
    }

    return true;
}
bool TcpIOCP::PostSend(TcpEvent* tcpEvent)
{
    auto connectData = GetConnect(tcpEvent->SessionID);
    if (connectData == nullptr)
    {
        WRITE_LOG(LogLevel::Warning, "Get ConnectData Failed while PostSend For SessionID:[%d].", tcpEvent->SessionID);
        return false;
    }
    WRITE_LOG(LogLevel::Info, "WSASend sessionID:[%d] Len:[%d], Data:[%s].", tcpEvent->SessionID, tcpEvent->Length, tcpEvent->ReadPos);
    while (tcpEvent->Length > 0)
    {
        DWORD transBytes = 0, flag = 0;
        int currSendLen = tcpEvent->Length >= MESSAGE_SIZE ? MESSAGE_SIZE : tcpEvent->Length;
        auto overlappedData = OverlappedData::Allocate();
        overlappedData->EventID = EventSend;
        overlappedData->SessionID = connectData->SessionID;
        overlappedData->ConnectSocket = connectData->SocketID;
        overlappedData->RemoteIP = connectData->RemoteIP;
        overlappedData->RemotePort = connectData->RemotePort;
        overlappedData->WsaBuffer.len = currSendLen;
        overlappedData->WsaBuffer.buf = overlappedData->Buffer;
        memcpy(overlappedData->Buffer, tcpEvent->ReadPos, currSendLen);

        if (WSASend(overlappedData->ConnectSocket, &overlappedData->WsaBuffer, 1, &transBytes, flag, (LPOVERLAPPED)overlappedData, NULL) == SOCKET_ERROR && WSAGetLastError() != ERROR_IO_PENDING)
        {
            WRITE_ERROR_LOG(WSAGetLastError(), "PostSend: WSASend failed.");
            overlappedData->Free();
            PostDisConnect(tcpEvent->SessionID);
            return false;
        }

        tcpEvent->Length -= currSendLen;
        tcpEvent->ReadPos += currSendLen;
    }
    return true;
}
bool TcpIOCP::PostRecv(OverlappedData* overlappedData)
{
    WRITE_LOG(LogLevel::Info, "PostRecv SessionID:[%d] Socket:[%lld]", overlappedData->SessionID, overlappedData->ConnectSocket);
    overlappedData->EventID = EventRecv;
    overlappedData->WsaBuffer.len = sizeof(overlappedData->Buffer);
    overlappedData->WsaBuffer.buf = overlappedData->Buffer;
    memset(overlappedData->Buffer, 0, sizeof(overlappedData->Buffer));

    DWORD transBytes = 0, flag = 0;
    if (WSARecv(overlappedData->ConnectSocket, &overlappedData->WsaBuffer, 1, &transBytes, &flag, (LPOVERLAPPED)overlappedData, NULL) == SOCKET_ERROR && WSAGetLastError() != ERROR_IO_PENDING)
    {
        WRITE_ERROR_LOG(WSAGetLastError(), "PostRecv: WSARecv failed.");
        PostDisConnect(overlappedData->SessionID);
        overlappedData->Free();
        return false;
    }
    return true;
}

void TcpIOCP::ConnectComplete(OverlappedData* overlappedData, int len)
{
    WRITE_LOG(LogLevel::Info, "ConnectComplete SessionID:[%d] SOCKET:[%lld] RemoteIP:[%s], RemotePort:[%s], Len:[%d], WSALen:[%d].",
        overlappedData->SessionID, overlappedData->ConnectSocket, overlappedData->RemoteIP.c_str(), overlappedData->RemotePort.c_str(), len, overlappedData->WsaBuffer.len);
    auto connectData = ConnectData::Allocate(overlappedData->SessionID, overlappedData->ConnectSocket, overlappedData->RemoteIP, overlappedData->RemotePort);
    TcpBase::AddConnect(connectData);
    PostRecv(overlappedData);
}
void TcpIOCP::DisConnectComplete(OverlappedData* overlappedData, int len)
{
    WRITE_LOG(LogLevel::Info, "DisConnectComplete SessionID:[%d] SOCKET:[%lld].", overlappedData->SessionID, overlappedData->ConnectSocket);
    TcpBase::RemoveConnect(overlappedData->SessionID);
    overlappedData->Free();
}
void TcpIOCP::SendComplete(OverlappedData* overlappedData, int len)
{
    WRITE_LOG(LogLevel::Info, "SendComplete  SessionID:[%d] SOCKET:[%lld], WsaLen=[%d], Len=[%d].", overlappedData->SessionID, overlappedData->ConnectSocket, overlappedData->WsaBuffer.len, len);
    if (len < overlappedData->WsaBuffer.len)
    {
        WRITE_LOG(LogLevel::Warning, "Sendlen:[%d] Less than TargetLen:[%d].", len, overlappedData->WsaBuffer.len);
        PostDisConnect(overlappedData->SessionID);
    }
}
void TcpIOCP::RecvComplete(OverlappedData* overlappedData, int len)
{
    WRITE_LOG(LogLevel::Info, "RecvComplete  SessionID:[%d] SOCKET:[%lld], WsaLen=[%d], Len=[%d].", overlappedData->SessionID, overlappedData->ConnectSocket, overlappedData->WsaBuffer.len, len);
    overlappedData->EventID = EventRecv;
    overlappedData->WsaBuffer.len = len;

    TcpEvent* tcpEvent = TcpEvent::Allocate();
    tcpEvent->EventID = EventRecv;
    tcpEvent->SessionID = overlappedData->SessionID;
    tcpEvent->IP = overlappedData->RemoteIP;
    tcpEvent->Port = overlappedData->RemotePort;
    memcpy(tcpEvent->Buff, overlappedData->WsaBuffer.buf, overlappedData->WsaBuffer.len);
    tcpEvent->Length = overlappedData->WsaBuffer.len;
    tcpEvent->ReadPos[tcpEvent->Length] = '\0';
    
    if (m_Subscriber)
    {
        m_Subscriber->OnRecv(tcpEvent);
    }
    PostRecv(overlappedData);
}

SOCKET TcpIOCP::PrepareSocket(int family)
{
    auto socket = WSASocket(family, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (!InitSocket(socket))
    {
        return INVALID_SOCKET;
    }
    return socket;
}
bool TcpIOCP::Bind(SOCKET socket, int family)
{
    auto ret = 0;
    if (family == AF_INET)
    {
        ret = bind(socket, m_BindAddressInfoV4->ai_addr, m_BindAddressInfoV4->ai_addrlen);
    }
    else
    {
        ret = bind(socket, m_BindAddressInfoV6->ai_addr, m_BindAddressInfoV6->ai_addrlen);
    }
    if (ret == SOCKET_ERROR)
    {
        WRITE_LOG(LogLevel::Error, "Bind Failed. ErrorID:[%d]", GetLastError());
        return false;
    }
    return true;
}
bool TcpIOCP::AssociateDevice(SOCKET socket)
{
    if (!IOCompletePort::GetInstance().AssociateDevice((HANDLE)socket, socket))
    {
        WRITE_LOG(LogLevel::Error, "Associate CompletionPort Failed. ErrorID:[%d], Socket:[%lld]", GetLastError(), socket);
        return false;
    }
    return true;
}
