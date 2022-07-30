#pragma once
#include <string>

using std::string;

class Config
{
	Config();
public:
	static Config& GetInstance();
	void Load(const char* fileName);
	void Print();

public:
	string ProtocolType;
	string ConnectIP;
	string ConnectPort;

private:
	static Config m_Instance;
};
