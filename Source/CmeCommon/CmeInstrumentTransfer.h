#pragma once
#include <string>
#include <set>


class CmeInstrumentTransfer
{
	CmeInstrumentTransfer() {}
	CmeInstrumentTransfer(const CmeInstrumentTransfer&) = delete;
	CmeInstrumentTransfer& operator=(const CmeInstrumentTransfer&) = delete;
public:
	struct CmeInstrument
	{
	public:
		std::string ExchangeID;
		std::string InstrumentID;
		std::string FixExchangeID;
		std::string FixInstrumentID;
		std::string ProductID;
		std::string MaturityMonthYear;

		std::string ToString()
		{
			return "ExchangeID:" + ExchangeID + " InstrumentID:" + InstrumentID + " FixExchangeID:" + FixExchangeID + " FixInstrumentID:" + FixInstrumentID + " ProductID:" + ProductID + " MaturityMonthYear:" + MaturityMonthYear;
		}
	};

	static CmeInstrumentTransfer& GetInstance()
	{
		return m_Instance;
	}
	CmeInstrument* GetFixInstrumentFromBroker(const std::string& exchangeID, const std::string& instrumentID);
	CmeInstrument* GetFixInstrumentFromExchange(const std::string& fixExchangeID, const std::string& fixInstrumentID);
	CmeInstrument* GetFixInstrumentFromProduct(const std::string fixExchangeID, const std::string& productID, const std::string& maturityMonthYear);


private:
	static CmeInstrumentTransfer m_Instance;
	std::set<CmeInstrument*> m_CmeInstruments;
};

