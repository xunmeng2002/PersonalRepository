#include "FixInstrumentTransfer.h"
#include "CmeMonthMap.h"
#include "Logger.h"
#include "TimeUtility.h"


CmeInstrumentTransfer CmeInstrumentTransfer::m_Instance;

CmeInstrumentTransfer::CmeInstrument* CmeInstrumentTransfer::GetFixInstrumentFromBroker(const std::string& exchangeID, const std::string& instrumentID)
{
	auto it = find_if(m_CmeInstruments.begin(), m_CmeInstruments.end(), [&](CmeInstrument* fixInstrument) {
		return (fixInstrument->ExchangeID == exchangeID) && (fixInstrument->InstrumentID == instrumentID);
		});
	if (it == m_CmeInstruments.end())
	{
		WRITE_LOG(LogLevel::Warning, "Cannot find CmeInstrument from Broker ExchangeID[%s], InstrumentID[%s]", exchangeID.c_str(), instrumentID.c_str());
		std::string productID = std::string(instrumentID.begin(), instrumentID.end() - 4);
		std::string year = "20" + std::string(instrumentID.end() - 4, instrumentID.end() - 2);
		std::string month = std::string(instrumentID.end() - 2, instrumentID.end());
		std::string monthLetter = CmeMonthMap::GetInstance().GetMonthLetter(month);
		std::string fixInstrumentID = productID + monthLetter + std::string(1, year.back());
		auto fixInstrument = new CmeInstrument();
		fixInstrument->ExchangeID = exchangeID;
		fixInstrument->InstrumentID = instrumentID;
		fixInstrument->FixExchangeID = exchangeID;
		fixInstrument->FixInstrumentID = fixInstrumentID;
		fixInstrument->ProductID = productID;
		fixInstrument->MaturityMonthYear = year + month;
		m_CmeInstruments.insert(fixInstrument);
		
		WRITE_LOG(LogLevel::Warning, "Add CmeInstrument:[%s]", fixInstrument->ToString().c_str());
		return fixInstrument;
	}
	return *it;
}
CmeInstrumentTransfer::CmeInstrument* CmeInstrumentTransfer::GetFixInstrumentFromExchange(const std::string& fixExchangeID, const std::string& fixInstrumentID)
{
	auto it = find_if(m_CmeInstruments.begin(), m_CmeInstruments.end(), [&](CmeInstrument* fixInstrument) {
		return (fixInstrument->FixExchangeID == fixExchangeID) && (fixInstrument->FixInstrumentID == fixInstrumentID);
		});
	if (it == m_CmeInstruments.end())
	{
		WRITE_LOG(LogLevel::Warning, "Cannot find CmeInstrument from Broker FixExchangeID[%s], FixInstrumentID[%s]", fixExchangeID.c_str(), fixInstrumentID.c_str());
		std::string year = "";
		std::string monthLetter = "";
		std::string productID = "";
		for (auto rit = fixInstrumentID.rbegin(); rit != fixInstrumentID.rend(); rit++)
		{
			if (*rit > '9' || *rit < '0')
			{
				auto it = rit.base();
				year = std::string(it, fixInstrumentID.end());
				auto it2 = it - 1;
				monthLetter = std::string(it2, it);
				productID = std::string(fixInstrumentID.begin(), it2);
				break;
			}
		}
		if (year.length() < 2)
		{
			std::string date = GetLocalDate();
			year = std::string(date.begin() + 2, date.begin() + 3) + year;
		}
		else if (year.length() > 2)
		{
			year = std::string(year.end() - 2, year.end());
		}
		std::string monthNum = CmeMonthMap::GetInstance().GetMonthNum(monthLetter);
		std::string instrumentID = productID + year + monthNum;

		auto fixInstrument = new CmeInstrument();
		fixInstrument->ExchangeID = fixExchangeID;
		fixInstrument->InstrumentID = instrumentID;
		fixInstrument->FixExchangeID = fixExchangeID;
		fixInstrument->FixInstrumentID = fixInstrumentID;
		fixInstrument->ProductID = productID;
		fixInstrument->MaturityMonthYear = "20" + year + monthNum;
		m_CmeInstruments.insert(fixInstrument);

		WRITE_LOG(LogLevel::Warning, "Add CmeInstrument:[%s]", fixInstrument->ToString().c_str());
		return fixInstrument;
	}
	return *it;
}
CmeInstrumentTransfer::CmeInstrument* CmeInstrumentTransfer::GetFixInstrumentFromProduct(const std::string fixExchangeID, const std::string& productID, const std::string& maturityMonthYear)
{
	auto it = find_if(m_CmeInstruments.begin(), m_CmeInstruments.end(), [&](CmeInstrument* fixInstrument) {
		return (fixInstrument->FixExchangeID == fixExchangeID) && (fixInstrument->ProductID == productID) && (fixInstrument->MaturityMonthYear == maturityMonthYear);
		});
	if (it == m_CmeInstruments.end())
	{
		std::string year = std::string(maturityMonthYear.begin(), maturityMonthYear.end() - 2);
		std::string month = std::string(maturityMonthYear.end() - 2, maturityMonthYear.end());
		std::string monthLetter = CmeMonthMap::GetInstance().GetMonthLetter(month);

		std::string instrumentID = productID + std::string(year.end() - 2, year.end()) + month;
		std::string fixInstrumentID = productID + monthLetter + std::string(1, year.back());
		auto fixInstrument = new CmeInstrument();
		fixInstrument->ExchangeID = fixExchangeID;
		fixInstrument->InstrumentID = instrumentID;
		fixInstrument->FixExchangeID = fixExchangeID;
		fixInstrument->FixInstrumentID = fixInstrumentID;
		fixInstrument->ProductID = productID;
		fixInstrument->MaturityMonthYear = maturityMonthYear;
		m_CmeInstruments.insert(fixInstrument);

		return fixInstrument;
	}
	return *it;
}
