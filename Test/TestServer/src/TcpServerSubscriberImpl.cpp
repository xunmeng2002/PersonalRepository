#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include <string.h>


TcpServerSubscriberImpl::TcpServerSubscriberImpl(TcpBase* tcp)
    :ThreadBase("TcpServerSubscriberImpl"), m_Tcp(tcp)
{
    m_Tcp->Subscriber(this);
}
bool TcpServerSubscriberImpl::Init()
{
    return m_Tcp->Init();
}
void TcpServerSubscriberImpl::HandleEvent()
{
    m_Tcp->HandleTcpEvent();
}

void TcpServerSubscriberImpl::OnConnect(int sessionID, const char* ip, const char* port)
{
    WRITE_LOG(LogLevel::Info, "TcpServerSubscriberImpl::OnConnect SessionID:[%d], IP:[%s], Port:[%s]", sessionID, ip, port);
}
void TcpServerSubscriberImpl::OnDisConnect(int sessionID, const char* ip, const char* port)
{
    WRITE_LOG(LogLevel::Info, "TcpServerSubscriberImpl::OnDisConnect SessionID:[%d], IP:[%s], Port:[%s]", sessionID, ip, port);
}
void TcpServerSubscriberImpl::OnRecv(TcpEvent* tcpEvent)
{
    char message[1024] = { 0 };
    auto n = sprintf(message, "TcpServerSubscriberImpl::OnRecv SessionID:[%d], IP:[%s], Port:[%s], Data:[%s]", tcpEvent->SessionID, tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->ReadPos);
    WRITE_LOG(LogLevel::Info, message);
    ::strcpy(tcpEvent->ReadPos, message);

    tcpEvent->EventID = EventSend;
    tcpEvent->Length = n;
    m_Tcp->Send(tcpEvent);
}