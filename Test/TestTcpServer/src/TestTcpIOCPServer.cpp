#include "TestTcpIOCPServer.h"
#include "TcpIOCPServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"



void TestTcpIOCPServer(const char* ip, const char* port)
{
    TcpIOCPServer tcpIOCPServer;
    tcpIOCPServer.SetTimeOut(1000);
    tcpIOCPServer.SetSocketTimeOut(5000);
    tcpIOCPServer.SetBindAddressInfo(port);
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpIOCPServer);
    tcpIOCPServer.Subscriber(&tcpServerSubscriberImpl);

    if (!tcpIOCPServer.Init(AF_INET6))
    {
        return;
    }
    tcpIOCPServer.Start();

    tcpIOCPServer.Join();
}