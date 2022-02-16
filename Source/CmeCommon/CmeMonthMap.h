#pragma once

#include <map>
#include <string>


class CmeMonthMap
{
	CmeMonthMap();
public:
	static CmeMonthMap GetInstance();
	std::string GetMonthLetter(std::string month);
	std::string GetMonthNum(std::string letter);


private:
	static CmeMonthMap m_Instance;
	std::map<std::string, std::string> m_CmeMonthMap;
};


