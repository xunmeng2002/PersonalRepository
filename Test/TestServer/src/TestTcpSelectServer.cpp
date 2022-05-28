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
    tcpSelectServer.SetSocketTimeOut(2000);
    tcpSelectServer.SetBindAddressInfo(IP1, Port);
    
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpSelectServer);
    if (!tcpServerSubscriberImpl.Init())
    {
        return;
    }
    tcpServerSubscriberImpl.Start();

    tcpServerSubscriberImpl.Join();
}
