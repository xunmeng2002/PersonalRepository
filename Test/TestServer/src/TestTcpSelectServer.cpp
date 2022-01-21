#include "TestTcpSelectServer.h"
#include "TcpSelectServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"



void TestTcpSelectServer()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "::";

    auto Port = "10000";

    TcpSelectServer tcpSelectServer;
    tcpSelectServer.SetTimeOut(1000);
    tcpSelectServer.SetSocketTimeOut(2000);
    tcpSelectServer.SetBindAddressInfo(IP1, Port);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpSelectServer);
    tcpSelectServer.Subscriber(&tcpServerSubscriberImpl);

    if (!tcpSelectServer.Init())
    {
        return;
    }
    tcpSelectServer.Start();

    tcpSelectServer.Join();
}
