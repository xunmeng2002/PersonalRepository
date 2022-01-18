#include "TestTcpSelectServer.h"
#include "TcpSelectServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"



void TestTcpSelectServer()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "127.0.0.1";
    auto IP3 = "192.168.2.29";
    auto IP4 = "::";
    auto IP5 = "::0";
    auto IP6 = "::1";
    auto IP7 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto Port = "10000";

    TcpSelectServer tcpSelectServer;
    tcpSelectServer.SetTimeOut(1000);
    tcpSelectServer.SetSocketTimeOut(2000);
    tcpSelectServer.SetBindAddressInfo(Port);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpSelectServer);
    tcpSelectServer.Subscriber(&tcpServerSubscriberImpl);

    if (!tcpSelectServer.Init(AF_INET6))
    {
        return;
    }
    tcpSelectServer.Start();

    tcpSelectServer.Join();
}
