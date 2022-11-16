#pragma once
#include "MdbInterface.h"
#include <atomic>

class OfferBase : public MdbSubscriber
{
public:
	OfferBase();
	~OfferBase();
	void RegisterMdbPublisher(MdbPublisher* mdbPublisher);

	virtual void ReqLogin() override {}
	virtual void OnRtnOrder(Order* order);
	virtual void OnRtnTrade(Trade* trade);
	virtual void OnErrRtnOrderCancel(OrderCancel* orderCancel);
	
	virtual void UpdateLoginStatus(bool loginStatus);
	

protected:
	MdbPublisher* m_MdbPublisher;
	std::atomic<bool> m_LoginStatus;
};

