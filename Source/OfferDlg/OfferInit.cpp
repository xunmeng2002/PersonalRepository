#pragma warning(disable: 4311 4302)
#include "pch.h"
#include "OfferDlg.h"
#include "OfferInit.h"
#include "Logger.h"
#include "Config.h"
#include "ItsEngine.h"
#include "Sqlite.h"


bool OfferInit::Init(COfferDlg* offerDlg)
{
	InitConfig();
	InitLogger();
	SetAccountInfo();
	InitOfferDlg(offerDlg);
	return true;
}
void OfferInit::InitConfig()
{
	Config::GetInstance().Load(ConfigName.c_str());
}
void OfferInit::InitLogger()
{
	Logger::GetInstance().Init(ProgramName.c_str());
	Logger::GetInstance().SetLogLevel(LogLevel(Config::GetInstance().LogLevel));
	Logger::GetInstance().Start();
}
void OfferInit::InitOfferDlg(COfferDlg* offerDlg)
{
	offerDlg->AddAccountInfo(m_AccountInfo);
	offerDlg->SetProgramName(ProgramName.c_str());
}
bool OfferInit::InitItsEngine(MdbSubscriber* mdbSubscriber, COfferDlg* offerDlg)
{
	auto& config = Config::GetInstance();
	m_ItsEngine = new ItsEngine(config.ChannelID, config.ListenIP, config.ListenPort, config.UdpIP, config.UdpPort);
	m_Sqlite = new Sqlite();

	m_ItsEngine->RegisterSubscriber(mdbSubscriber);
	m_ItsEngine->RegisterSqlite(m_Sqlite);
	m_ItsEngine->SetOfferDlg(offerDlg, m_AccountInfo);

	
	return m_ItsEngine->Init() && m_Sqlite->Init(m_ItsEngine);
}
bool OfferInit::Start()
{
	return m_ItsEngine->Start() && m_Sqlite->Start();
}
void OfferInit::Stop()
{
	m_ItsEngine->Stop();
	m_ItsEngine->Join();

	m_Sqlite->Stop();
	m_Sqlite->Join();

	Logger::GetInstance().Stop();
	Logger::GetInstance().Join();
}