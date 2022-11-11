#include "TestTcpEpollServer.h"
#include "TcpEpollServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "Config.h"


void TestTcpEpollServer()
{
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
}

