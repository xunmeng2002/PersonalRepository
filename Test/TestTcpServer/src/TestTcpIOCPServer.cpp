#include "TestTcpIOCPServer.h"
#include "TcpIOCPServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"



void TestTcpIOCPServer()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "127.0.0.1";
    auto IP3 = "192.168.2.29";
    auto IP4 = "::";
    auto IP5 = "::0";
    auto IP6 = "::1";
    auto IP7 = "fe80::59d8:5d6d:25cc:42cf%14";

    auto Port = "10000";

    TcpIOCPServer tcpIOCPServer;
    tcpIOCPServer.SetTimeOut(1000);
    tcpIOCPServer.SetSocketTimeOut(5000);
    tcpIOCPServer.SetBindAddressInfo(Port);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpIOCPServer);
    tcpIOCPServer.Subscriber(&tcpServerSubscriberImpl);

    if (!tcpIOCPServer.Init(AF_INET6))
    {
        return;
    }
    tcpIOCPServer.Start();

    tcpIOCPServer.Join();
}