#include "TestTcpIOCPServer.h"
#include "TcpIOCPServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"



void TestTcpIOCPServer()
{
    auto IP1 = "0.0.0.0";
    auto IP2 = "::";

    auto Port = "10000";

    TcpIOCPServer tcpIOCPServer;
    tcpIOCPServer.SetTimeOut(1000);
    tcpIOCPServer.SetSocketTimeOut(5000);
    tcpIOCPServer.SetBindAddressInfo(Port, IP2);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpIOCPServer);
    tcpIOCPServer.Subscriber(&tcpServerSubscriberImpl);

    if (!tcpIOCPServer.Init())
    {
        return;
    }
    tcpIOCPServer.Start();

    tcpIOCPServer.Join();
}