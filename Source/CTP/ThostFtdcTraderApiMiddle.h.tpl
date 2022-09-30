#pragma once
#include "ThostFtdcTraderApi.h"


class CThostFtdcTraderApiMiddle : public CThostFtdcTraderApi
{
public:
	static CThostFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");
	
	static const char *GetApiVersion();

!!entry ctp!!
!!entry api!!
!!travel!!
	virtual !!@return!! !!@name!!(!!travel!!!!if $pumpid >= '1':!!!!inc indent!!, !!dec indent!!!!@type!! !!if @custom == "True":!!!!inc indent!!*p!!dec indent!!!!@name!!!!leave!!);

!!leave!!
!!leave!!
!!leave!!

private:
	CThostFtdcTraderApi* m_TraderApi;
};