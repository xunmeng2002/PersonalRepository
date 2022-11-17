#pragma once
#include "DboDataStruct.h"
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_error.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <string>
#include <vector>

!!entry tables!!
class Dbo
{
public:
	Dbo(const std::string& host, const std::string& user, const std::string& passwd);
	~Dbo();
!!travel!!
!!className = "Dbo" + @name!!
!!tableName = "t_" + @name!!
!!fieldTypeNames = {}!!
!!entry fields!!
!!travel!!
!!fieldTypeNames[@name] = @type!!
!!leave!!
!!leave!!
	bool Insert!!$className!!(!!$className!!* record);
	bool Truncate!!$className!!();
	bool Delete!!$className!!(!!$className!!* record);
	bool Update!!$className!!(!!$className!!* record);
!!entry primarykey!!
	!!$className!!* Query!!$className!!FromPrimaryKey(!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!const C!!$fieldTypeName!!Type& !!@name!!!!leave!!);
!!leave!!
!!entry uniquekeys!!
!!travel!!
	!!$className!!* Query!!$className!!FromUniqueKey!!@name!!(!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!const C!!$fieldTypeName!!Type& !!@name!!!!leave!!);
!!leave!!
!!leave!!
!!entry indexes!!
!!travel!!
	void Query!!$className!!FromIndex!!@name!!(std::vector<!!$className!!*>& records!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!);
!!leave!!
!!leave!!
	void SetStatementFor!!$className!!Record(sql::PreparedStatement* statement, !!$className!!* record);
!!entry primarykey!!
	void SetStatementFor!!$className!!PrimaryKey(sql::PreparedStatement* statement!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!);
!!leave!!
!!entry uniquekeys!!
!!travel!!
	void SetStatementFor!!$className!!UniqueKey!!@name!!(sql::PreparedStatement* statement!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!);
!!leave!!
!!leave!!
!!entry indexes!!
!!travel!!
	void SetStatementFor!!$className!!Index!!@name!!(sql::PreparedStatement* statement!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!);
!!leave!!
!!leave!!
	!!$className!!* Get!!$className!!Record(sql::ResultSet* result);

!!leave!!

private:
	sql::Driver* m_Driver;
	sql::Connection* m_DBConnection;

	std::string m_Host;
	std::string m_User;
	std::string m_Passwd;
	char* m_Sql;

!!travel!!
!!className = "Dbo" + @name!!
	sql::PreparedStatement* m_!!$className!!InsertStatement;
	sql::PreparedStatement* m_!!$className!!TruncateStatement;
	sql::PreparedStatement* m_!!$className!!DeleteStatement;
	sql::PreparedStatement* m_!!$className!!UpdateStatement;
	sql::PreparedStatement* m_!!$className!!PrimaryKeyStatement;
!!entry uniquekeys!!
!!travel!!
	sql::PreparedStatement* m_!!$className!!UniqueKeyStatement!!@name!!;
!!leave!!
!!leave!!
!!entry indexes!!
!!travel!!
	sql::PreparedStatement* m_!!$className!!IndexStatement!!@name!!;
!!leave!!
!!leave!!
!!leave!!
};
!!leave!!
