#include <iostream>
#include <set>
#include <string.h>
#include "Logger.h"
#include "TestTcpSelectClient.h"



int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();

    TestTcpSelectClient();
    //TestTcpIOCPClient();
    //TestUdpClient();


    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();

	return 0;
}
