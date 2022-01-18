#include "TcpServerSubscriberImpl.h"
#include "Logger.h"


TcpServerSubscriberImpl::TcpServerSubscriberImpl(TcpPublisher* tcpPublisher)
    :m_TcpPublisher(tcpPublisher)
{

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
    strcpy(tcpEvent->ReadPos, message);

    tcpEvent->EventID = EventSend;
    tcpEvent->Length = n;
    m_TcpPublisher->Send(tcpEvent);
}