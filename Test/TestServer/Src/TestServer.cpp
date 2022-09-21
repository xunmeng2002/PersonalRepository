#include <iostream>
#include <set>
#include <string.h>
#include "TestTcpSelectServer.h"
#include "TestUdpServer.h"
#include "Logger.h"
#include "Config.h"

auto ConfigName = "TestServer.json";

int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().SetLogLevel(LogLevel::Info, LogLevel::Info);
    Logger::GetInstance().Start();
    Config::GetInstance().Load(ConfigName);
    auto& config = Config::GetInstance();
    switch (config.ProtocolType[0])
    {
    case '0':
        TestTcpSelectServer();
        break;
    case '1':
        TestUdpServer();
        break;
    default:
        break;
    }

    Logger::GetInstance().Join();
    Logger::GetInstance().Join();
	return 0;
}
