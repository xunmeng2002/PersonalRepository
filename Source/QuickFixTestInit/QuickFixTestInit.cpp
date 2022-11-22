#pragma warning(disable: 4311 4302 5040)
#ifdef WINDOWS
#include "QuickFixTestInit.h"
#include "Logger.h"
#include "Config.h"
#include "Application.h"
#include "Commodity.h"


auto QuickFixConfig = "TTQuickFixTest.cfg";


bool QuickFixTestInit::Init()
{
	TestInit::Init();

	auto& config = Config::GetInstance();
	Commodity::GetInstance().Load(config.CommodityFile.c_str());

	m_SessionSettings = new FIX::SessionSettings(QuickFixConfig);
	m_StoreFactory = new FIX::FileStoreFactory(*m_SessionSettings);
	m_FileLogFactory = new FIX::FileLogFactory(*m_SessionSettings);
	m_Application = new Application(*m_SessionSettings);
	m_Initiator = new FIX::SocketInitiator(*m_Application, *m_StoreFactory, *m_SessionSettings, *m_FileLogFactory);

	if (!InitTestEngine(m_Application))
	{
		return false;
	}
	m_Application->RegisterMdbPublisher(m_TestEngine);
	m_Application->SetInitiator(m_Initiator);

	auto sessions = m_SessionSettings->getSessions();
	for (auto& session : sessions)
	{
		WRITE_LOG(LogLevel::Info, "sessionCfg: BeginString[%s], SenderCompID:[%s], TargetCompID:[%s], SessionQualifier:[%s], isFIXT:[%d]",
			session.getBeginString().getValue().c_str(), session.getSenderCompID().getValue().c_str(), session.getTargetCompID().getValue().c_str(), session.getSessionQualifier().c_str(), session.isFIXT());
	}
	return m_Application->Init();
}
bool QuickFixTestInit::Start()
{
	m_Initiator->start();
	return true;
}
void QuickFixTestInit::Stop()
{
	WRITE_LOG(LogLevel::Info, "OnExit");
	m_Initiator->stop();
	TestInit::Stop();

	delete m_Initiator;
	delete m_Application;
	delete m_FileLogFactory;
	delete m_StoreFactory;
	delete m_SessionSettings;
}
#endif
