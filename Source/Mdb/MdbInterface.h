#pragma once
#include <string>
#include "MdbTables.h"


class MdbSubscriber
{
public:
	virtual void ReqLogin() = 0;
	virtual void ReqInsertOrder(Order* order) = 0;
	virtual void ReqInsertOrderCancel(OrderCancel* orderCancel) = 0;
	virtual void ReqQryOrder() {}
	virtual void ReqQryTrade() {}
};

class MdbPublisher
{
public:
	virtual void UpdateLoginStatus(bool loginStatus) {}
	virtual void OnRtnOrder(Order* field) {}
	virtual void OnRtnTrade(Trade* field) {}
	virtual void OnErrRtnOrderCancel(OrderCancel* field) {}
};

