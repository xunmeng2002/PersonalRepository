#include "TestTcpSelectClient.h"
#include "TcpClientSubscriberImpl.h"
#include "Logger.h"


void TestTcpSelectClient()
{
    auto IP1 = "127.0.0.1";
    auto IP2 = "192.168.2.29";
    auto IP3 = "::1";
    auto IP4 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto Port = "10000";

    TcpSelectClient tcpSelectClient;
    tcpSelectClient.SetTimeOut(1000);
    tcpSelectClient.SetSocketTimeOut(5000);
    TcpClientSubscriberImpl tcpClientSubscriberImpl(&tcpSelectClient);
    tcpSelectClient.Subscriber(&tcpClientSubscriberImpl);

    tcpSelectClient.Start();

    tcpSelectClient.Connect(IP1, Port);
    tcpSelectClient.Connect(IP2, Port);
    tcpSelectClient.Connect(IP3, Port);
    tcpSelectClient.Connect(IP4, Port);

    tcpSelectClient.Join();
}
