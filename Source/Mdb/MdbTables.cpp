#ifdef _MSC_VER
#pragma warning(disable : 26495)
#endif

#include "MdbTables.h"
#include "Mdb.h"


int OrderSequence::ToStream(char* buff, int size) const
{
	return snprintf(buff, size, " '%s',  '%d'",
		TradingDay.c_str(), MaxOrderLocalID);
}
int OrderSequence::ToString(char* buff, int size) const
{
	return snprintf(buff, size, "MdbOrderSequence: TradingDay:[%s], MaxOrderLocalID:[%d]",
		TradingDay.c_str(), MaxOrderLocalID);
}
string OrderSequence::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_MdbOrderSequence(TradingDay char(32), MaxOrderLocalID char(32), PRIMARY KEY(TradingDay));";
}
string OrderSequence::InsertSql()
{
	::memset(m_Buff, 0, sizeof(m_Buff));
	ToStream(m_Buff, 4096);
	return "REPLACE INTO t_MdbOrderSequence VALUES(" + string(m_Buff) + ");";
}
int OrderSequence::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new OrderSequence();
	field->TradingDay = colValues[0];
	field->MaxOrderLocalID = atoi(colValues[1]);

	((MdbCallback*)callback)->SelectMdbOrderSequenceCallback(field);
	return 0;
}

int Order::ToStream(char* buff, int size) const
{
	return snprintf(buff, size, " '%s',  '%s',  '%s',  '%s',  '%s',  '%c',  '%c',  '%c',  '%c',  '%f',  '%d',  '%d',  '%c',  '%s',  '%s',  '%s',  '%d',  '%s',  '%s',  '%s',  '%s',  '%s',  '%s',  '%c',  '%c',  '%s',  '%c',  '%s',  '%c',  '%d',  '%c',  '%f',  '%d'",
		AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrderSysID.c_str(), Direction, OffsetFlag, HedgeFlag, OrderPriceType, Price, Volume, VolumeTraded, OrderStatus, StatusMsg.c_str(), RequestID.c_str(), FrontID.c_str(), SessionID, InsertDate.c_str(), InsertTime.c_str(), ExchangeInsertDate.c_str(), ExchangeInsertTime.c_str(), CancelDate.c_str(), CancelTime.c_str(), ForceCloseReason, IsLocalOrder, UserProductInfo.c_str(), TimeCondition, GTDDate.c_str(), VolumeCondition, MinVolume, ContingentCondition, StopPrice, IsSwapOrder);
}
int Order::ToString(char* buff, int size) const
{
	return snprintf(buff, size, "MdbOrder: AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderLocalID:[%s], OrderSysID:[%s], Direction:[%c], OffsetFlag:[%c], HedgeFlag:[%c], OrderPriceType:[%c], Price:[%f], Volume:[%d], VolumeTraded:[%d], OrderStatus:[%c], StatusMsg:[%s], RequestID:[%s], FrontID:[%s], SessionID:[%d], InsertDate:[%s], InsertTime:[%s], ExchangeInsertDate:[%s], ExchangeInsertTime:[%s], CancelDate:[%s], CancelTime:[%s], ForceCloseReason:[%c], IsLocalOrder:[%c], UserProductInfo:[%s], TimeCondition:[%c], GTDDate:[%s], VolumeCondition:[%c], MinVolume:[%d], ContingentCondition:[%c], StopPrice:[%f], IsSwapOrder:[%d]",
		AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrderSysID.c_str(), Direction, OffsetFlag, HedgeFlag, OrderPriceType, Price, Volume, VolumeTraded, OrderStatus, StatusMsg.c_str(), RequestID.c_str(), FrontID.c_str(), SessionID, InsertDate.c_str(), InsertTime.c_str(), ExchangeInsertDate.c_str(), ExchangeInsertTime.c_str(), CancelDate.c_str(), CancelTime.c_str(), ForceCloseReason, IsLocalOrder, UserProductInfo.c_str(), TimeCondition, GTDDate.c_str(), VolumeCondition, MinVolume, ContingentCondition, StopPrice, IsSwapOrder);
}
string Order::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_MdbOrder(AccountID char(32), ExchangeID char(32), InstrumentID char(32), OrderLocalID char(32), OrderSysID char(64), Direction char(32), OffsetFlag char(32), HedgeFlag char(32), OrderPriceType char(32), Price char(32), Volume char(32), VolumeTraded char(32), OrderStatus char(32), StatusMsg char(32), RequestID char(32), FrontID char(32), SessionID char(32), InsertDate char(32), InsertTime char(32), ExchangeInsertDate char(32), ExchangeInsertTime char(32), CancelDate char(32), CancelTime char(32), ForceCloseReason char(32), IsLocalOrder char(32), UserProductInfo char(32), TimeCondition char(32), GTDDate char(32), VolumeCondition char(32), MinVolume char(32), ContingentCondition char(32), StopPrice char(32), IsSwapOrder char(32), PRIMARY KEY(OrderLocalID));";
}
string Order::InsertSql()
{
	::memset(m_Buff, 0, sizeof(m_Buff));
	ToStream(m_Buff, 4096);
	return "REPLACE INTO t_MdbOrder VALUES(" + string(m_Buff) + ");";
}
int Order::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new Order();
	field->AccountID = colValues[0];
	field->ExchangeID = colValues[1];
	field->InstrumentID = colValues[2];
	field->OrderLocalID = colValues[3];
	field->OrderSysID = colValues[4];
	field->Direction = ConvertToDirection(colValues[5]);
	field->OffsetFlag = ConvertToOffsetFlag(colValues[6]);
	field->HedgeFlag = ConvertToHedgeFlag(colValues[7]);
	field->OrderPriceType = ConvertToOrderPriceType(colValues[8]);
	field->Price = atof(colValues[9]);
	field->Volume = atoi(colValues[10]);
	field->VolumeTraded = atoi(colValues[11]);
	field->OrderStatus = ConvertToOrderStatus(colValues[12]);
	field->StatusMsg = colValues[13];
	field->RequestID = colValues[14];
	field->FrontID = colValues[15];
	field->SessionID = atoi(colValues[16]);
	field->InsertDate = colValues[17];
	field->InsertTime = colValues[18];
	field->ExchangeInsertDate = colValues[19];
	field->ExchangeInsertTime = colValues[20];
	field->CancelDate = colValues[21];
	field->CancelTime = colValues[22];
	field->ForceCloseReason = ConvertToForceCloseReason(colValues[23]);
	field->IsLocalOrder = ConvertToIsLocalOrder(colValues[24]);
	field->UserProductInfo = colValues[25];
	field->TimeCondition = ConvertToTimeCondition(colValues[26]);
	field->GTDDate = colValues[27];
	field->VolumeCondition = ConvertToVolumeCondition(colValues[28]);
	field->MinVolume = atoi(colValues[29]);
	field->ContingentCondition = ConvertToContingentCondition(colValues[30]);
	field->StopPrice = atof(colValues[31]);
	field->IsSwapOrder = atoi(colValues[32]);

	((MdbCallback*)callback)->SelectMdbOrderCallback(field);
	return 0;
}

int OrderCancel::ToStream(char* buff, int size) const
{
	return snprintf(buff, size, " '%s',  '%s',  '%s',  '%s',  '%s',  '%s',  '%c',  '%s',  '%s',  '%d',  '%d',  '%s',  '%s',  '%s'",
		AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrigOrderLocalID.c_str(), OrderSysID.c_str(), Direction, OrderRef.c_str(), FrontID.c_str(), SessionID, ErrorID, ErrorMsg.c_str(), InsertDate.c_str(), CancelDate.c_str());
}
int OrderCancel::ToString(char* buff, int size) const
{
	return snprintf(buff, size, "MdbOrderCancel: AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderLocalID:[%s], OrigOrderLocalID:[%s], OrderSysID:[%s], Direction:[%c], OrderRef:[%s], FrontID:[%s], SessionID:[%d], ErrorID:[%d], ErrorMsg:[%s], InsertDate:[%s], CancelDate:[%s]",
		AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrigOrderLocalID.c_str(), OrderSysID.c_str(), Direction, OrderRef.c_str(), FrontID.c_str(), SessionID, ErrorID, ErrorMsg.c_str(), InsertDate.c_str(), CancelDate.c_str());
}
string OrderCancel::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_MdbOrderCancel(AccountID char(32), ExchangeID char(32), InstrumentID char(32), OrderLocalID char(32), OrigOrderLocalID char(32), OrderSysID char(64), Direction char(32), OrderRef char(32), FrontID char(32), SessionID char(32), ErrorID char(32), ErrorMsg char(255), InsertDate char(32), CancelDate char(32), PRIMARY KEY(OrderLocalID));";
}
string OrderCancel::InsertSql()
{
	::memset(m_Buff, 0, sizeof(m_Buff));
	ToStream(m_Buff, 4096);
	return "REPLACE INTO t_MdbOrderCancel VALUES(" + string(m_Buff) + ");";
}
int OrderCancel::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new OrderCancel();
	field->AccountID = colValues[0];
	field->ExchangeID = colValues[1];
	field->InstrumentID = colValues[2];
	field->OrderLocalID = colValues[3];
	field->OrigOrderLocalID = colValues[4];
	field->OrderSysID = colValues[5];
	field->Direction = ConvertToDirection(colValues[6]);
	field->OrderRef = colValues[7];
	field->FrontID = colValues[8];
	field->SessionID = atoi(colValues[9]);
	field->ErrorID = atoi(colValues[10]);
	field->ErrorMsg = colValues[11];
	field->InsertDate = colValues[12];
	field->CancelDate = colValues[13];

	((MdbCallback*)callback)->SelectMdbOrderCancelCallback(field);
	return 0;
}

int Trade::ToStream(char* buff, int size) const
{
	return snprintf(buff, size, " '%s',  '%s',  '%s',  '%s',  '%c',  '%c',  '%c',  '%f',  '%d',  '%s',  '%s',  '%s',  '%s'",
		AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), TradeID.c_str(), Direction, OffsetFlag, HedgeFlag, Price, Volume, OrderLocalID.c_str(), OrderSysID.c_str(), TradeTime.c_str(), TradeDate.c_str());
}
int Trade::ToString(char* buff, int size) const
{
	return snprintf(buff, size, "MdbTrade: AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], TradeID:[%s], Direction:[%c], OffsetFlag:[%c], HedgeFlag:[%c], Price:[%f], Volume:[%d], OrderLocalID:[%s], OrderSysID:[%s], TradeTime:[%s], TradeDate:[%s]",
		AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), TradeID.c_str(), Direction, OffsetFlag, HedgeFlag, Price, Volume, OrderLocalID.c_str(), OrderSysID.c_str(), TradeTime.c_str(), TradeDate.c_str());
}
string Trade::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_MdbTrade(AccountID char(32), ExchangeID char(32), InstrumentID char(32), TradeID char(32), Direction char(32), OffsetFlag char(32), HedgeFlag char(32), Price char(32), Volume char(32), OrderLocalID char(32), OrderSysID char(64), TradeTime char(32), TradeDate char(32), PRIMARY KEY(TradeDate, OrderSysID, TradeID));";
}
string Trade::InsertSql()
{
	::memset(m_Buff, 0, sizeof(m_Buff));
	ToStream(m_Buff, 4096);
	return "REPLACE INTO t_MdbTrade VALUES(" + string(m_Buff) + ");";
}
int Trade::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new Trade();
	field->AccountID = colValues[0];
	field->ExchangeID = colValues[1];
	field->InstrumentID = colValues[2];
	field->TradeID = colValues[3];
	field->Direction = ConvertToDirection(colValues[4]);
	field->OffsetFlag = ConvertToOffsetFlag(colValues[5]);
	field->HedgeFlag = ConvertToHedgeFlag(colValues[6]);
	field->Price = atof(colValues[7]);
	field->Volume = atoi(colValues[8]);
	field->OrderLocalID = colValues[9];
	field->OrderSysID = colValues[10];
	field->TradeTime = colValues[11];
	field->TradeDate = colValues[12];

	((MdbCallback*)callback)->SelectMdbTradeCallback(field);
	return 0;
}

