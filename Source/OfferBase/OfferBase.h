#pragma once
#include "ThreadBase.h"
#include "MdbInterface.h"



class OfferBase : public ThreadBase, public MdbSubscriber
{
public:
	OfferBase(const char* name);
	void RegisterMdbPublisher(MdbPublisher* mdbPublisher);
	virtual void ReqInsertOrder(Order* order) override;
	virtual void ReqInsertOrderCancel(OrderCancel* orderCancel) override;
	virtual void ReqQryOrder() override;
	virtual void ReqQryTrade() override;
	virtual void OnRtnOrder(Order* order) override;
	virtual void OnRtnTrade(Trade* trade) override;
	virtual void OnErrRtnOrderCancel(OrderCancel* orderCancel) override;

protected:
	virtual void HandleEvent() override;

	virtual void HandleInsertOrder(Order* order) {}
	virtual void HandleInsertOrderCancel(OrderCancel* orderCancel) {}
	virtual void HandleQryOrder() {}
	virtual void HandleQryTrade() {}
	virtual void HandleRtnOrder(Order* order) {}
	virtual void HandleRtnTrade(Trade* trade) {}
	virtual void HandleErrRtnOrderCancel(OrderCancel* orderCancel) {}

protected:
	MdbPublisher* m_MdbPublisher;
};

