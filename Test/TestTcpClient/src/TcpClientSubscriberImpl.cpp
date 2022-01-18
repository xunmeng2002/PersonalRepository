#include "TcpClientSubscriberImpl.h"
#include "TcpSelectClient.h"
#include "Logger.h"


TcpClientSubscriberImpl::TcpClientSubscriberImpl(TcpPublisher* tcpPublisher)
    :m_TcpPublisher(tcpPublisher)
{

}
void TcpClientSubscriberImpl::OnConnect(int sessionID, const char* ip, const char* port)
{
    WRITE_LOG(LogLevel::Info, "TcpClientSubscriberImpl::OnConnect SessionID:[%d], IP:[%s], Port:[%s]", sessionID, ip, port);
    Send(sessionID, ip, port);
}
void TcpClientSubscriberImpl::OnDisConnect(int sessionID, const char* ip, const char* port)
{
    WRITE_LOG(LogLevel::Info, "TcpClientSubscriberImpl::OnDisConnect SessionID:[%d], IP:[%s], Port:[%s]", sessionID, ip, port);
    m_MessageCounts.erase(sessionID);
}
void TcpClientSubscriberImpl::OnRecv(TcpEvent* tcpEvent)
{
    WRITE_LOG(LogLevel::Info, "TcpClientSubscriberImpl::OnRecv SessionID:[%d], IP:[%s], Port:[%s], Data:[%s]", tcpEvent->SessionID, tcpEvent->IP.c_str(), tcpEvent->Port.c_str(), tcpEvent->ReadPos);
    if (m_MessageCounts[tcpEvent->SessionID] < 5)
    {
        Send(tcpEvent->SessionID, tcpEvent->IP.c_str(), tcpEvent->Port.c_str());
    }
    else
    {
        m_TcpPublisher->DisConnect(tcpEvent->SessionID);
        tcpEvent->Free();
    }
}
void TcpClientSubscriberImpl::Send(int sessionID, const char* ip, const char* port)
{
    ++m_MessageCounts[sessionID];
    TcpEvent* tcpEvent = TcpEvent::Allocate();
    tcpEvent->EventID = EventSend;
    tcpEvent->SessionID = sessionID;
    tcpEvent->IP = ip;
    tcpEvent->Port = port;
    int n = sprintf(tcpEvent->Buff, "Message [%d] From Client SessionID;[%d].", m_MessageCounts[sessionID], sessionID);
    tcpEvent->Length = n;
    m_TcpPublisher->Send(tcpEvent);
}

