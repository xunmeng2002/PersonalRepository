#pragma once
#include <string>
#include "MdbEnumDict.h"
#include "sqlite3.h"
#include "Logger.h"
#include "Mdbtables.h"
#include "TimeUtility.h"

class Mdb
{
	Mdb();
	Mdb(const Mdb&) = delete;
	Mdb& operator=(const Mdb&) = delete;
public:
	static Mdb& GetInstance();
	void SetDB(sqlite3* db);
	void SetCallback(MdbCallback* callback);
	
	void CreateAllTables();
	void TruncateAllTables();
	void SelectAllTables();

	template<typename T>
	int CreateTable()
	{
		std::string sql = T::CreateSql();
		WRITE_LOG(LogLevel::Info, "CreateSql SQL:[%s]", sql.c_str());

		int rc = sqlite3_exec(m_DB, sql.c_str(), nullptr, (void*)"CreateTable", &m_ErrorMsg);
		if (rc != SQLITE_OK)
		{
			WRITE_LOG(LogLevel::Warning, "SQL error: %s", m_ErrorMsg);
			sqlite3_free(m_ErrorMsg);
		}
		return rc;
	}
	template<typename T>
	int TruncateTable()
	{
		std::string sql = std::string("DELETE FROM ") + T::TableName + ";";
		WRITE_LOG(LogLevel::Debug, "TruncateSql SQL:[%s]", sql.c_str());

		int rc = sqlite3_exec(m_DB, sql.c_str(), nullptr, (void*)"TruncateTable", &m_ErrorMsg);
		if (rc != SQLITE_OK)
		{
			WRITE_LOG(LogLevel::Warning, "SQL error: %s", m_ErrorMsg);
			WRITE_LOG(LogLevel::Warning, "SQL: %s", sql.c_str());
			sqlite3_free(m_ErrorMsg);
		}
		return rc;
	}
	template<typename T>
	int InsertRecord(T* field)
	{
		std::string sql = field->InsertSql();
		WRITE_LOG(LogLevel::Debug, "InsertRecord SQL:[%s]", sql.c_str());

		int rc = sqlite3_exec(m_DB, sql.c_str(), nullptr, (void*)"InsertRecord", &m_ErrorMsg);
		if (rc != SQLITE_OK)
		{
			WRITE_LOG(LogLevel::Warning, "SQL error: %s", m_ErrorMsg);
			WRITE_LOG(LogLevel::Warning, "SQL: %s", sql.c_str());
			sqlite3_free(m_ErrorMsg);
		}
		return rc;
	}
	template<typename T>
	int SelectTable()
	{
		std::string sql = std::string("SELECT * FROM ") + T::TableName + " WHERE TradingDay = '" + GetLocalDate() + "';";
		WRITE_LOG(LogLevel::Info, "SelectTable SQL:[%s]", sql.c_str());

		int rc = sqlite3_exec(m_DB, sql.c_str(), T::OnSelectCallback, m_Callback, &m_ErrorMsg);
		if (rc != SQLITE_OK)
		{
			WRITE_LOG(LogLevel::Warning, "SQL error: %s", m_ErrorMsg);
			WRITE_LOG(LogLevel::Warning, "SQL: %s", sql.c_str());
			sqlite3_free(m_ErrorMsg);
		}
		else
		{
			WRITE_LOG(LogLevel::Info, "Select Table %s successfully", T::TableName);
		}
		return rc;
	}
	int SelectHistoryOrder();
private:
	static Mdb m_Instance;
	sqlite3* m_DB;
	MdbCallback* m_Callback;
	char* m_ErrorMsg;
};
