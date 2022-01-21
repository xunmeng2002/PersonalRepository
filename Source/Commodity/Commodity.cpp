#include "Commodity.h"
#include "Logger.h"
#include "CsvRecord.h"
#include <fstream>

Commodity Commodity::m_Instance;


Commodity::Commodity()
{

}
Commodity::~Commodity()
{
	for (auto item : m_CommodityRecords)
	{
		delete item;
	}
	m_CommodityRecords.clear();
}
bool Commodity::Load(const char* csvFileName)
{
	std::fstream file(csvFileName, std::fstream::in);
	if (!file)
	{
		WRITE_LOG(LogLevel::Error, "Can't Open CsvFile:[%s]", csvFileName);
		return false;
	}
	
	CSVRecord csvRecord;
	char* headerBuffer = new char[1024];
	char* contentBuffer = new char[1024];
	
	::memset(contentBuffer, 0, 1024);
	file.getline(headerBuffer, 1024, '\n');	//第一是字段名
	while (!file.eof())
	{
		::memset(contentBuffer, 0, 1024);
		file.getline(contentBuffer, 1024, '\n');
		if (contentBuffer[0] == '\0')	//遇到空行就结束
			break;
		if (!csvRecord.Analysis(headerBuffer, contentBuffer))
		{
			WRITE_LOG(LogLevel::Error, "Analysis [%s] failed. Header:[%s], Line:[%s]", csvFileName, headerBuffer, contentBuffer);
			file.close();
			return false;
		}
		auto commodityRecord = new CommodityRecord();
		commodityRecord->CmeExchangeNo = csvRecord.GetFieldAsInt("CmeExchangeNo");
		commodityRecord->ExchangeID = csvRecord.GetFieldAsString("ExchangeID");
		commodityRecord->ProductID = csvRecord.GetFieldAsString("ProductID");
		commodityRecord->PoboExchangeNo = csvRecord.GetFieldAsInt("PoboExchangeNo");
		commodityRecord->PoboExchangeID = csvRecord.GetFieldAsString("PoboExchangeID");
		commodityRecord->PoboProductID = csvRecord.GetFieldAsString("PoboProductID");
		commodityRecord->ProductName = csvRecord.GetFieldAsString("ProductName");
		commodityRecord->GroupID = csvRecord.GetFieldAsInt("GroupID");
		commodityRecord->MagnificationFactor = csvRecord.GetFieldAsInt("MagnificationFactor");
		commodityRecord->DecimalPlace = csvRecord.GetFieldAsInt("DecimalPlace");
		commodityRecord->DominantContractNo = csvRecord.GetFieldAsInt("DominantContractNo");
		m_CommodityRecords.insert(commodityRecord);
	}
	file.close();
	delete[] headerBuffer;
	delete[] contentBuffer;
	return true;
}
double Commodity::GetCommodityMagnificationFactor(std::string exchangeID, std::string productID)
{
	auto it = find_if(m_CommodityRecords.begin(), m_CommodityRecords.end(), [&](CommodityRecord* commodityRecord) {
		return (commodityRecord->ExchangeID == exchangeID) && (commodityRecord->ProductID == productID);
		});
	if (it != m_CommodityRecords.end())
	{
		return pow(10, (*it)->DecimalPlace);
	}
	return 1;
}
