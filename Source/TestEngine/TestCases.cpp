#include "TestCases.h"



void ReqInsertOrder(TestEngine* testEngine)
{
	Order* order = new Order();
	testEngine->ReqInsertOrder(order);
}
void ReqInsertOrderCancel(TestEngine* testEngine)
{
	OrderCancel* orderCancel = new OrderCancel();
	orderCancel->TradingDay = "20220906";
	orderCancel->AccountID = "025568";
	orderCancel->ExchangeID = "CME";
	orderCancel->InstrumentID = "CL2212";
	orderCancel->OrderLocalID = "";
	orderCancel->OrigOrderLocalID = "0906000001";
	orderCancel->OrderSysID = "1512325405";
	orderCancel->Direction = Direction::Buy;
	orderCancel->OrderRef = "0";
	orderCancel->FrontID = "";
	orderCancel->SessionID = 0;
	orderCancel->ErrorID = 0;
	orderCancel->ErrorMsg = "";
	orderCancel->InsertDate = "20220906";
	orderCancel->CancelDate = "";

	testEngine->ReqInsertOrderCancel(orderCancel);
}



