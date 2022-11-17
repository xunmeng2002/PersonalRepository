#pragma once
#include "MdbInterface.h"



class TestEngine : public MdbPublisher
{
public:
	TestEngine();
	~TestEngine();
	void RegisterSubscriber(MdbSubscriber* mdbSubscriber);
	bool Init();
	bool GetLoginStatus();

	virtual void UpdateLoginStatus(bool loginStatus) override;
	virtual void OnRtnOrder(Order* field) override;
	virtual void OnRtnTrade(Trade* field) override;
	virtual void OnErrRtnOrderCancel(OrderCancel* field) override;

	void ReqLogin();
	void ReqInsertOrder(Order* order);
	void ReqInsertOrderCancel(OrderCancel* orderCancel);

private:
	MdbSubscriber* m_MdbSubscriber;
	char* m_LogBuff;
	bool m_LoginStatus;
};
