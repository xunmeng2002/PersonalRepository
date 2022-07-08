#include <iostream>
#include <set>
#include <string.h>
#include "TestTcpSelectServer.h"
#include "Logger.h"



int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();

    TestTcpSelectServer();
    //TestTcpIOCPServer();
    //TestUdpServer();

    Logger::GetInstance().Join();
    Logger::GetInstance().Join();
	return 0;
}
