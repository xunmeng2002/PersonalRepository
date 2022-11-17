#ifdef _MSC_VER
#pragma warning(disable : 26495)
#endif

#include "MdbTables.h"
#include "Mdb.h"

thread_local char StreamBuff[4096];


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
	::memset(StreamBuff, 0, sizeof(StreamBuff));
	ToStream(StreamBuff, 4096);
	return "REPLACE INTO t_MdbOrderSequence VALUES(" + string(StreamBuff) + ");";
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
	return snprintf(buff, size, " '%s',  '%s',  '%s',  '%s',  '%s',  '%s',  '%s',  '%c',  '%c',  '%c',  '%c',  '%f',  '%d',  '%d',  '%c',  '%d',  '%s',  '%s',  '%s',  '%d',  '%s',  '%s',  '%s',  '%s',  '%s',  '%s',  '%c',  '%c',  '%s',  '%c',  '%s',  '%c',  '%d',  '%c',  '%f',  '%d',  '%d'",
		TradingDay.c_str(), AccountID.c_str(), CurrencyID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrderSysID.c_str(), Direction, OffsetFlag, HedgeFlag, OrderPriceType, Price, Volume, VolumeTraded, OrderStatus, ErrorID, ErrorMsg.c_str(), RequestID.c_str(), FrontID.c_str(), SessionID, InsertDate.c_str(), InsertTime.c_str(), ExchangeInsertDate.c_str(), ExchangeInsertTime.c_str(), CancelDate.c_str(), CancelTime.c_str(), ForceCloseReason, IsLocalOrder, UserProductInfo.c_str(), TimeCondition, GTDDate.c_str(), VolumeCondition, MinVolume, ContingentCondition, StopPrice, IsSwapOrder, T1Valid);
}
int Order::ToString(char* buff, int size) const
{
	return snprintf(buff, size, "MdbOrder: TradingDay:[%s], AccountID:[%s], CurrencyID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderLocalID:[%s], OrderSysID:[%s], Direction:[%c], OffsetFlag:[%c], HedgeFlag:[%c], OrderPriceType:[%c], Price:[%f], Volume:[%d], VolumeTraded:[%d], OrderStatus:[%c], ErrorID:[%d], ErrorMsg:[%s], RequestID:[%s], FrontID:[%s], SessionID:[%d], InsertDate:[%s], InsertTime:[%s], ExchangeInsertDate:[%s], ExchangeInsertTime:[%s], CancelDate:[%s], CancelTime:[%s], ForceCloseReason:[%c], IsLocalOrder:[%c], UserProductInfo:[%s], TimeCondition:[%c], GTDDate:[%s], VolumeCondition:[%c], MinVolume:[%d], ContingentCondition:[%c], StopPrice:[%f], IsSwapOrder:[%d], T1Valid:[%d]",
		TradingDay.c_str(), AccountID.c_str(), CurrencyID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrderSysID.c_str(), Direction, OffsetFlag, HedgeFlag, OrderPriceType, Price, Volume, VolumeTraded, OrderStatus, ErrorID, ErrorMsg.c_str(), RequestID.c_str(), FrontID.c_str(), SessionID, InsertDate.c_str(), InsertTime.c_str(), ExchangeInsertDate.c_str(), ExchangeInsertTime.c_str(), CancelDate.c_str(), CancelTime.c_str(), ForceCloseReason, IsLocalOrder, UserProductInfo.c_str(), TimeCondition, GTDDate.c_str(), VolumeCondition, MinVolume, ContingentCondition, StopPrice, IsSwapOrder, T1Valid);
}
string Order::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_MdbOrder(TradingDay char(32), AccountID char(32), CurrencyID char(32), ExchangeID char(32), InstrumentID char(32), OrderLocalID char(32), OrderSysID char(64), Direction char(32), OffsetFlag char(32), HedgeFlag char(32), OrderPriceType char(32), Price char(32), Volume char(32), VolumeTraded char(32), OrderStatus char(32), ErrorID char(32), ErrorMsg char(255), RequestID char(32), FrontID char(32), SessionID char(32), InsertDate char(32), InsertTime char(32), ExchangeInsertDate char(32), ExchangeInsertTime char(32), CancelDate char(32), CancelTime char(32), ForceCloseReason char(32), IsLocalOrder char(32), UserProductInfo char(32), TimeCondition char(32), GTDDate char(32), VolumeCondition char(32), MinVolume char(32), ContingentCondition char(32), StopPrice char(32), IsSwapOrder char(32), T1Valid char(32), PRIMARY KEY(TradingDay, OrderLocalID));";
}
string Order::InsertSql()
{
	::memset(StreamBuff, 0, sizeof(StreamBuff));
	ToStream(StreamBuff, 4096);
	return "REPLACE INTO t_MdbOrder VALUES(" + string(StreamBuff) + ");";
}
int Order::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new Order();
	field->TradingDay = colValues[0];
	field->AccountID = colValues[1];
	field->CurrencyID = colValues[2];
	field->ExchangeID = colValues[3];
	field->InstrumentID = colValues[4];
	field->OrderLocalID = colValues[5];
	field->OrderSysID = colValues[6];
	field->Direction = ConvertToDirection(colValues[7]);
	field->OffsetFlag = ConvertToOffsetFlag(colValues[8]);
	field->HedgeFlag = ConvertToHedgeFlag(colValues[9]);
	field->OrderPriceType = ConvertToOrderPriceType(colValues[10]);
	field->Price = atof(colValues[11]);
	field->Volume = atoi(colValues[12]);
	field->VolumeTraded = atoi(colValues[13]);
	field->OrderStatus = ConvertToOrderStatus(colValues[14]);
	field->ErrorID = atoi(colValues[15]);
	field->ErrorMsg = colValues[16];
	field->RequestID = colValues[17];
	field->FrontID = colValues[18];
	field->SessionID = atoi(colValues[19]);
	field->InsertDate = colValues[20];
	field->InsertTime = colValues[21];
	field->ExchangeInsertDate = colValues[22];
	field->ExchangeInsertTime = colValues[23];
	field->CancelDate = colValues[24];
	field->CancelTime = colValues[25];
	field->ForceCloseReason = ConvertToForceCloseReason(colValues[26]);
	field->IsLocalOrder = ConvertToIsLocalOrder(colValues[27]);
	field->UserProductInfo = colValues[28];
	field->TimeCondition = ConvertToTimeCondition(colValues[29]);
	field->GTDDate = colValues[30];
	field->VolumeCondition = ConvertToVolumeCondition(colValues[31]);
	field->MinVolume = atoi(colValues[32]);
	field->ContingentCondition = ConvertToContingentCondition(colValues[33]);
	field->StopPrice = atof(colValues[34]);
	field->IsSwapOrder = atoi(colValues[35]);
	field->T1Valid = atoi(colValues[36]);

	((MdbCallback*)callback)->SelectMdbOrderCallback(field);
	return 0;
}

int OrderCancel::ToStream(char* buff, int size) const
{
	return snprintf(buff, size, " '%s',  '%s',  '%s',  '%s',  '%s',  '%s',  '%s',  '%c',  '%s',  '%s',  '%d',  '%d',  '%s',  '%s',  '%s'",
		TradingDay.c_str(), AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrigOrderLocalID.c_str(), OrderSysID.c_str(), Direction, OrderRef.c_str(), FrontID.c_str(), SessionID, ErrorID, ErrorMsg.c_str(), InsertDate.c_str(), CancelDate.c_str());
}
int OrderCancel::ToString(char* buff, int size) const
{
	return snprintf(buff, size, "MdbOrderCancel: TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], OrderLocalID:[%s], OrigOrderLocalID:[%s], OrderSysID:[%s], Direction:[%c], OrderRef:[%s], FrontID:[%s], SessionID:[%d], ErrorID:[%d], ErrorMsg:[%s], InsertDate:[%s], CancelDate:[%s]",
		TradingDay.c_str(), AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), OrderLocalID.c_str(), OrigOrderLocalID.c_str(), OrderSysID.c_str(), Direction, OrderRef.c_str(), FrontID.c_str(), SessionID, ErrorID, ErrorMsg.c_str(), InsertDate.c_str(), CancelDate.c_str());
}
string OrderCancel::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_MdbOrderCancel(TradingDay char(32), AccountID char(32), ExchangeID char(32), InstrumentID char(32), OrderLocalID char(32), OrigOrderLocalID char(32), OrderSysID char(64), Direction char(32), OrderRef char(32), FrontID char(32), SessionID char(32), ErrorID char(32), ErrorMsg char(255), InsertDate char(32), CancelDate char(32), PRIMARY KEY(TradingDay, OrderLocalID));";
}
string OrderCancel::InsertSql()
{
	::memset(StreamBuff, 0, sizeof(StreamBuff));
	ToStream(StreamBuff, 4096);
	return "REPLACE INTO t_MdbOrderCancel VALUES(" + string(StreamBuff) + ");";
}
int OrderCancel::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new OrderCancel();
	field->TradingDay = colValues[0];
	field->AccountID = colValues[1];
	field->ExchangeID = colValues[2];
	field->InstrumentID = colValues[3];
	field->OrderLocalID = colValues[4];
	field->OrigOrderLocalID = colValues[5];
	field->OrderSysID = colValues[6];
	field->Direction = ConvertToDirection(colValues[7]);
	field->OrderRef = colValues[8];
	field->FrontID = colValues[9];
	field->SessionID = atoi(colValues[10]);
	field->ErrorID = atoi(colValues[11]);
	field->ErrorMsg = colValues[12];
	field->InsertDate = colValues[13];
	field->CancelDate = colValues[14];

	((MdbCallback*)callback)->SelectMdbOrderCancelCallback(field);
	return 0;
}

int Trade::ToStream(char* buff, int size) const
{
	return snprintf(buff, size, " '%s',  '%s',  '%s',  '%s',  '%s',  '%c',  '%c',  '%c',  '%f',  '%d',  '%s',  '%s',  '%s',  '%s'",
		TradingDay.c_str(), AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), TradeID.c_str(), Direction, OffsetFlag, HedgeFlag, Price, Volume, OrderLocalID.c_str(), OrderSysID.c_str(), TradeTime.c_str(), TradeDate.c_str());
}
int Trade::ToString(char* buff, int size) const
{
	return snprintf(buff, size, "MdbTrade: TradingDay:[%s], AccountID:[%s], ExchangeID:[%s], InstrumentID:[%s], TradeID:[%s], Direction:[%c], OffsetFlag:[%c], HedgeFlag:[%c], Price:[%f], Volume:[%d], OrderLocalID:[%s], OrderSysID:[%s], TradeTime:[%s], TradeDate:[%s]",
		TradingDay.c_str(), AccountID.c_str(), ExchangeID.c_str(), InstrumentID.c_str(), TradeID.c_str(), Direction, OffsetFlag, HedgeFlag, Price, Volume, OrderLocalID.c_str(), OrderSysID.c_str(), TradeTime.c_str(), TradeDate.c_str());
}
string Trade::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_MdbTrade(TradingDay char(32), AccountID char(32), ExchangeID char(32), InstrumentID char(32), TradeID char(32), Direction char(32), OffsetFlag char(32), HedgeFlag char(32), Price char(32), Volume char(32), OrderLocalID char(32), OrderSysID char(64), TradeTime char(32), TradeDate char(32), PRIMARY KEY(TradingDay, TradeDate, OrderSysID, TradeID));";
}
string Trade::InsertSql()
{
	::memset(StreamBuff, 0, sizeof(StreamBuff));
	ToStream(StreamBuff, 4096);
	return "REPLACE INTO t_MdbTrade VALUES(" + string(StreamBuff) + ");";
}
int Trade::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new Trade();
	field->TradingDay = colValues[0];
	field->AccountID = colValues[1];
	field->ExchangeID = colValues[2];
	field->InstrumentID = colValues[3];
	field->TradeID = colValues[4];
	field->Direction = ConvertToDirection(colValues[5]);
	field->OffsetFlag = ConvertToOffsetFlag(colValues[6]);
	field->HedgeFlag = ConvertToHedgeFlag(colValues[7]);
	field->Price = atof(colValues[8]);
	field->Volume = atoi(colValues[9]);
	field->OrderLocalID = colValues[10];
	field->OrderSysID = colValues[11];
	field->TradeTime = colValues[12];
	field->TradeDate = colValues[13];

	((MdbCallback*)callback)->SelectMdbTradeCallback(field);
	return 0;
}

