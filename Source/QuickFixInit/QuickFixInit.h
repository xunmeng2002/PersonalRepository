#pragma once
#ifdef WINDOWS
#include "OfferInit.h"
#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/SocketInitiator.h"

class Application;
class QuickFixInit : public OfferInit
{
public:
	virtual bool Init(COfferDlg* offerDlg) override;
	virtual void SetAccountInfo() override;
	virtual bool Start() override;
	virtual void Stop() override;

protected:
	FIX::SessionSettings* m_SessionSettings;
	FIX::FileStoreFactory* m_StoreFactory;
	FIX::FileLogFactory* m_FileLogFactory;
	FIX::Initiator* m_Initiator;
	Application* m_Application;
};
#endif

