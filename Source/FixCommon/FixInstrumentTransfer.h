#pragma once
#include <string>
#include <set>


class FixInstrumentTransfer
{
	FixInstrumentTransfer() {}
	FixInstrumentTransfer(const FixInstrumentTransfer&) = delete;
	FixInstrumentTransfer& operator=(const FixInstrumentTransfer&) = delete;
public:
	struct FixInstrument
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

	static FixInstrumentTransfer& GetInstance()
	{
		return m_Instance;
	}
	FixInstrument* GetFixInstrumentFromBroker(const std::string& exchangeID, const std::string& instrumentID);
	FixInstrument* GetFixInstrumentFromExchange(const std::string& fixExchangeID, const std::string& fixInstrumentID);
	FixInstrument* GetFixInstrumentFromProduct(const std::string fixExchangeID, const std::string& productID, const std::string& maturityMonthYear);


private:
	static FixInstrumentTransfer m_Instance;
	std::set<FixInstrument*> m_FixInstruments;
};

