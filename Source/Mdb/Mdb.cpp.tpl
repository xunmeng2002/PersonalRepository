#include "Mdb.h"


Mdb Mdb::m_Instance;

!!entry mdb!!
!!entry tables!!
Mdb::Mdb()
	:m_DB(nullptr), m_Callback(nullptr), m_ErrorMsg(nullptr)
{
}
Mdb& Mdb::GetInstance()
{
	return m_Instance;
}
void Mdb::SetDB(sqlite3* db)
{
	m_DB = db;
}
void Mdb::SetCallback(MdbCallback* callback)
{
	m_Callback = callback;
}
void Mdb::CreateAllTables()
{
!!travel!!
	CreateTable<!!@name!!>();
!!leave!!
}
void Mdb::TruncateAllTables()
{
!!travel!!
	TruncateTable<!!@name!!>();
!!leave!!
}
void Mdb::SelectAllTables()
{
!!travel!!
	SelectTable<!!@name!!>();
!!leave!!
	SelectHistoryOrder();
}
int Mdb::SelectHistoryOrder()
{
	std::string localDate = GetLocalDate();
	std::string tableName = Order::TableName;
	std::string sql = "SELECT * FROM " + tableName + " WHERE TradingDay != '' AND TradingDay < '" + localDate + "' AND OrderStatus <= '2' AND TimeCondition = '5'"
					  "UNION ALL "
					  "SELECT * FROM " + tableName + " WHERE TradingDay != '' AND TradingDay < '" + localDate + "' AND OrderStatus <= '2' AND TimeCondition = '4' AND GTDDate != '' AND GTDDate >= '" + localDate + "';";

	WRITE_LOG(LogLevel::Info, "SelectHistoryOrder SQL:[%s]", sql.c_str());

	int rc = sqlite3_exec(m_DB, sql.c_str(), Order::OnSelectCallback, m_Callback, &m_ErrorMsg);
	if (rc != SQLITE_OK)
	{
		WRITE_LOG(LogLevel::Warning, "SQL error: %s", m_ErrorMsg);
		WRITE_LOG(LogLevel::Warning, "SQL: %s", sql.c_str());
		sqlite3_free(m_ErrorMsg);
	}
	else
	{
		WRITE_LOG(LogLevel::Info, "SelectHistoryOrder successfully");
	}
	return rc;
}

!!leave!!
!!leave!!
