#include "sqlite3.h"
#include "TimeUtility.h"
#include <iostream>
#include <string>
#include <map>
#include <thread>

using namespace std;


int main()
{
	sqlite3* sqliteDB;
	sqlite3_open("TestDB", &sqliteDB);

	std::map<string, int>* datas = new std::map<string, int>();

	for (auto i = 0; i < 10000; i++)
	{
		datas->insert(make_pair("key-" + std::to_string(i), i));
	}
	
	char* errorMsg;

	string createTable = "CREATE TABLE IF NOT EXISTS TestTable(KeyItem char(32), ValueItem int);";
	int rc = sqlite3_exec(sqliteDB, createTable.c_str(), nullptr, (void*)"CreateTable", &errorMsg);
	if (rc != SQLITE_OK)
	{
		printf("SQL error: %s\n", errorMsg);
		sqlite3_free(errorMsg);
		return -1;
	}
	string startTime = GetLocalDateTimeWithMilliSecond();
	string insertSql = "";
	for (auto& it : *datas)
	{
		insertSql = "INSERT INTO TestTable VALUES('" + it.first + "', '" + std::to_string(it.second) + "')";
		int rc = sqlite3_exec(sqliteDB, insertSql.c_str(), nullptr, (void*)"InsertRecord", &errorMsg);
		//if (rc != SQLITE_OK)
		//{
		//	printf("SQL error: %s\n", errorMsg);
		//	sqlite3_free(errorMsg);
		//	return;
		//}
	}
	string endTime = GetLocalDateTimeWithMilliSecond();

	printf("startTime:%s, endTime:%s\n", startTime.c_str(), endTime.c_str());
	return 0;
}

