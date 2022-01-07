#pragma once
#include <string>
#include <set>

struct CommodityRecord
{
	int CmeExchangeNo;
	std::string ExchangeID;
	std::string ProductID;
	int PoboExchangeNo;
	std::string PoboExchangeID;
	std::string PoboProductID;
	std::string ProductName;
	int GroupID;
	int MagnificationFactor;
	int DecimalPlace;
	int DominantContractNo;

	bool operator<(const CommodityRecord& o)
	{
		if (ExchangeID < o.ExchangeID)
		{
			return true;
		}
		else if (ExchangeID > o.ExchangeID)
		{
			return false;
		}
		if (ProductID < o.ProductID)
		{
			return true;
		}
		else if (ProductID > o.ProductID)
		{
			return false;
		}
		return false;
	}
	bool operator==(const CommodityRecord& o)
	{
		if (ExchangeID != o.ExchangeID)
		{
			return false;
		}
		if (ProductID != o.ProductID)
		{
			return false;
		}
		return true;
	}
};


class Commodity
{
	Commodity();
	~Commodity();
	Commodity(const Commodity&) = delete;
	Commodity& operator=(const Commodity&) = delete;
public:
	static Commodity& GetInstance()
	{
		return m_Instance;
	}
	bool Load(const char* csvFileName);
	double GetCommodityMagnificationFactor(std::string exchangeID, std::string productID);


private:
	static Commodity m_Instance;

	std::set<CommodityRecord*> m_CommodityRecords;
};


