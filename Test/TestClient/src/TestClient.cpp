#include <iostream>
#include <set>
#include <string.h>
#include "Logger.h"
#include "TestTcpSelectClient.h"
#include "TestUdpClient.h"
#include "Config.h"

auto ConfigName = "TestClient.json";

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
        TestTcpSelectClient();
        break;
    case '1':
        TestUdpClient();
        break;
    default:
        break;
    }

    Sleep(10000);
    Logger::GetInstance().Stop();
    Logger::GetInstance().Join();

	return 0;
}
