#pragma once
#include "ThreadBase.h"
#include "MdbInterface.h"



class OfferBase : public ThreadBase, public MdbSubscriber
{
public:
	OfferBase(const char* name);
	virtual void ReqInsertOrder(Order* order)  override;
	virtual void ReqInsertOrderCancel(OrderCancel* orderCancel)  override;

protected:
	virtual void HandleEvent() override;

	virtual void HandleInsertOrder(Order* order) = 0;
	virtual void HandleInsertOrderCancel(OrderCancel* orderCancel) = 0;
};

