#include "TestInit.h"
#include "Config.h"
#include "Logger.h"

extern std::string ProgramName;
extern std::string ConfigName;

bool TestInit::Init()
{
	InitConfig();
	InitLogger();
	return true;
}
bool TestInit::InitTestEngine(MdbSubscriber* mdbSubscriber)
{
	m_TestEngine = new TestEngine();
	m_TestEngine->RegisterSubscriber(mdbSubscriber);
	return m_TestEngine->Init();
}
void TestInit::Stop()
{
	Logger::GetInstance().Stop();
	Logger::GetInstance().Join();
}
TestEngine* TestInit::GetTestEngine()
{
	return m_TestEngine;
}

void TestInit::InitConfig()
{
	Config::GetInstance().Load(ConfigName.c_str());
}
void TestInit::InitLogger()
{
	Logger::GetInstance().Init(ProgramName.c_str());
	Logger::GetInstance().SetLogLevel(LogLevel(Config::GetInstance().LogLevel));
	Logger::GetInstance().Start();
}
