#include "TestTcpSelectClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"


void TestTcpSelectClient()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "127.0.0.1";
    auto IP3 = "192.168.2.29";
    auto IP4 = "::";
    auto IP5 = "::0";
    auto IP6 = "::1";
    auto IP7 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto Port = "10000";

    TcpSelectClient tcpSelectClient;
    tcpSelectClient.SetTimeOut(1000);
    tcpSelectClient.SetSocketTimeOut(5000);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpSelectClient);
    tcpSelectClient.Subscriber(&tcpClientSubscriberImpl);

    if (!tcpSelectClient.Init(AF_INET6))
    {
        return;
    }
    tcpSelectClient.Start();

    tcpSelectClient.Connect(IP1, Port);
    tcpSelectClient.Connect(IP2, Port);
    tcpSelectClient.Connect(IP3, Port);
    tcpSelectClient.Connect(IP4, Port);
    tcpSelectClient.Connect(IP5, Port);
    tcpSelectClient.Connect(IP6, Port);
    tcpSelectClient.Connect(IP7, Port);

    tcpSelectClient.Join();
}
