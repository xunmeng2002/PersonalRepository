#include "TestTcpSelectServer.h"
#include "TcpSelectServer.h"
#include "TcpServerSubscriberImpl.h"
#include "Logger.h"
#include "Config.h"



void TestTcpSelectServer()
{
    TcpSelectServer tcpSelectServer;
    tcpSelectServer.SetSocketTimeOut(2000);
    tcpSelectServer.SetBindAddressInfo(Config::GetInstance().ListenIP.c_str(), Config::GetInstance().ListenPort.c_str());
    
    TcpServerSubscriberImpl tcpServerSubscriberImpl(&tcpSelectServer);
    if (!tcpServerSubscriberImpl.Init())
    {
        return;
    }
    tcpServerSubscriberImpl.Start();

    tcpServerSubscriberImpl.Join();
}
