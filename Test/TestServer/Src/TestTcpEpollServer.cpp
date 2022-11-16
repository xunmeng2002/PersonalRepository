#include "TestTcpEpollServer.h"
#ifdef LINUX
#include "TcpEpollServer.h"
#endif
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "Config.h"


void TestTcpEpollServer()
{
#ifdef LINUX
    TcpEpollServer tcpEpollServer;
    tcpEpollServer.SetSocketTimeOut(2000);
    tcpEpollServer.SetBindAddressInfo(Config::GetInstance().ListenIP.c_str(), Config::GetInstance().ListenPort.c_str());

    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpEpollServer);
    if (!tcpServerSubscriberImpl.Init())
    {
        return;
    }
    tcpServerSubscriberImpl.Start();

    tcpServerSubscriberImpl.Join();
#endif
}

