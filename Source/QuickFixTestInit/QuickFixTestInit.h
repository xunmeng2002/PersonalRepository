#pragma once
#ifdef WINDOWS
#include "TestInit.h"
#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/SocketInitiator.h"

class Application;
class QuickFixTestInit : public TestInit
{
public:
	virtual bool Init() override;
	virtual bool Start();
	virtual void Stop() override;

protected:
	FIX::SessionSettings* m_SessionSettings;
	FIX::FileStoreFactory* m_StoreFactory;
	FIX::FileLogFactory* m_FileLogFactory;
	FIX::Initiator* m_Initiator;
	Application* m_Application;
};
#endif

