#include "ThostFtdcTraderApiMiddle.h"
#include "Logger.h"
#include "StructWriteLogFunc.h"


!!types={}!!
!!types['enum']='d'!!
!!types['bool']='d'!!
!!types['char']='c'!!
!!types['short']='d'!!
!!types['int']='d'!!
!!types['double']='f'!!
!!types['string']='s'!!

CThostFtdcTraderApi *CThostFtdcTraderApiMiddle::CreateFtdcTraderApi(const char *pszFlowPath)
{
	WRITE_LOG(LogLevel::Info, "CreateFtdcTraderApi: pszFlowPath[%s]", pszFlowPath);
	
	auto traderApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
	auto apiMiddle = new CThostFtdcTraderApiMiddle();
	apiMiddle->m_TraderApi = traderApi;
	
	return apiMiddle;
}

const char *CThostFtdcTraderApiMiddle::GetApiVersion()
{
	WRITE_LOG(LogLevel::Info, "GetApiVersion:");
	
	return CThostFtdcTraderApi::GetApiVersion();
}

!!entry ctp!!
!!entry api!!
!!travel!!
!!@return!! CThostFtdcTraderApiMiddle::!!@name!!(!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@type!! !!if @custom == "True":!!!!inc indent!!*p!!dec indent!!!!@name!!!!leave!!)
{
	WRITE_LOG(LogLevel::Info, "!!@name!!:!!travel!!!!if @custom == "False":!!!!inc indent!!!!currType=types[@basetype]!! !!@name!![%!!$currType!!]!!dec indent!!!!leave!!"!!travel!!!!if @custom == "False":!!!!inc indent!!, !!@name!!!!dec indent!!!!leave!!);
!!travel!!
!!if @custom == "True" and @name != "TraderSp":!!
!!inc indent!!
	Write!!@name!!(p!!@name!!);
!!dec indent!!
!!leave!!

	return m_TraderApi->!!@name!!(!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!if @custom == "True":!!!!inc indent!!p!!dec indent!!!!@name!!!!leave!!);
}

!!leave!!
!!leave!!
!!leave!!
