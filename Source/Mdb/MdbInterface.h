#pragma once
#include <string>
#include "MdbTables.h"


class MdbSubscriber
{
public:
	virtual void ReqInsertOrder(Order* order) {}
	virtual void ReqInsertOrderCancel(OrderCancel* orderCancel) {}
	virtual void ReqQryOrder() {}
	virtual void ReqQryTrade() {}
	virtual void OnRtnOrder(Order* order) {}
	virtual void OnRtnTrade(Trade* trade) {}
	virtual void OnErrRtnOrderCancel(OrderCancel* field) {}
};

class MdbPublisher
{
public:
	virtual void OnRtnOrder(Order* field) {}
	virtual void OnRtnTrade(Trade* field) {}
	virtual void OnErrRtnOrderCancel(OrderCancel* field) {}
};

