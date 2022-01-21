﻿#include <iostream>
#include <set>
#include <string.h>
#include "TestTcpSelectServer.h"
#include "TestTcpIOCPServer.h"
#include "TestUdpServer.h"
#include "Logger.h"



using namespace std;



int main(int argc, const char* argv[])
{
    Logger::GetInstance().Init(argv[0]);
    Logger::GetInstance().Start();

    //TestTcpSelectServer();
    //TestTcpIOCPServer();
    TestUdpServer();

    Logger::GetInstance().Join();
    Logger::GetInstance().Join();
	return 0;
}
