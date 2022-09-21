#include "Config.h"
#include "json/json.h"
#include "Logger.h"
#include <iostream>
#include <fstream>


Config Config::m_Instance;
Config::Config()
{

}
Config& Config::GetInstance()
{
	return m_Instance;
}
void Config::Load(const char* fileName)
{
	Json::Reader reader;
	Json::FastWriter writer;
	Json::Value root;
	std::ifstream in_file(fileName, std::ios::binary);
	std::cout << "parse: " << reader.parse(in_file, root) << std::endl;
	in_file.close();
	ProtocolType = root["ProtocolType"].asString();
	ConnectIP = root["ConnectIP"].asString();
	ConnectPort = root["ConnectPort"].asString();

	Print();
}

void Config::Print()
{
	WRITE_LOG(LogLevel::Info, "ProtocolType:[%s], ConnectIP:[%s], ConnectPort:[%s]",
		ProtocolType.c_str(), ConnectIP.c_str(), ConnectPort.c_str());
}
