#pragma warning(disable: 4311)
#include "Dbo.h"
#include <string.h>

!!formats = {}!!
!!dataTypes = {}!!
!!entry types!!
!!entry bools!!
!!travel!!
!!formats[@name] = '%d'!!
!!dataTypes[@name] = 'bool'!!
!!leave!!
!!leave!!
!!entry ints!!
!!travel!!
!!formats[@name] = '%d'!!
!!dataTypes[@name] = 'int'!!
!!leave!!
!!leave!!
!!entry int64s!!
!!travel!!
!!formats[@name] = '%lld'!!
!!dataTypes[@name] = 'int64'!!
!!leave!!
!!leave!!
!!entry doubles!!
!!travel!!
!!formats[@name] = '%f'!!
!!dataTypes[@name] = 'double'!!
!!leave!!
!!leave!!
!!entry strings!!
!!travel!!
!!formats[@name] = '%s'!!
!!dataTypes[@name] = 'string'!!
!!leave!!
!!leave!!
!!entry enums!!
!!travel!!
!!formats[@name] = '%c'!!
!!dataTypes[@name] = 'enum'!!
!!leave!!
!!leave!!
!!entry datetimes!!
!!travel!!
!!formats[@name] = '%s'!!
!!dataTypes[@name] = 'string'!!
!!leave!!
!!leave!!
!!leave!!

!!entry tables!!
Dbo::Dbo(const std::string& host, const std::string& user, const std::string& passwd)
{
	m_Sql = new char[4096];
	m_Host = host;
	m_User = user;
	m_Passwd = passwd;

	m_Driver = sql::mysql::get_driver_instance();
	m_DBConnection = m_Driver->connect(host, user, passwd);

!!travel!!
!!className = "Dbo" + @name!!
	m_!!$className!!InsertStatement = nullptr;
	m_!!$className!!TruncateStatement = nullptr;
	m_!!$className!!DeleteStatement = nullptr;
	m_!!$className!!UpdateStatement = nullptr;
	m_!!$className!!PrimaryKeyStatement = nullptr;
!!entry uniquekeys!!
!!travel!!
	m_!!$className!!UniqueKeyStatement!!@name!! = nullptr;
!!leave!!
!!leave!!
!!entry indexes!!
!!travel!!
	m_!!$className!!IndexStatement!!@name!! = nullptr;
!!leave!!
!!leave!!
!!leave!!
}
Dbo::~Dbo()
{
	delete[] m_Sql;
}

!!travel!!
!!className = "Dbo" + @name!!
!!tableName = "t_" + @name!!
!!fieldTypeNames = {}!!
!!entry fields!!
!!travel!!
!!fieldTypeNames[@name] = @type!!
!!leave!!
!!leave!!

!!entry fields!!
bool Dbo::Insert!!$className!!(!!$className!!* record)
{
	if (m_!!$className!!InsertStatement == nullptr)
	{
		m_!!$className!!InsertStatement = m_DBConnection->prepareStatement("insert into !!$tableName!! Values(!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!?!!leave!!);");
	}
	SetStatementFor!!$className!!Record(m_!!$className!!InsertStatement, record);
	return m_!!$className!!InsertStatement->execute();
}
!!leave!!
bool Dbo::Truncate!!$className!!()
{
	if(m_!!$className!!TruncateStatement == nullptr)
	{
		m_!!$className!!TruncateStatement = m_DBConnection->prepareStatement("truncate  table !!$tableName!! ;");
	}
	return m_!!$className!!TruncateStatement->execute();
}
!!entry primarykey!!
bool Dbo::Delete!!$className!!(!!$className!!* record)
{
	if (m_!!$className!!DeleteStatement == nullptr)
	{
		m_!!$className!!DeleteStatement = m_DBConnection->prepareStatement("delete from !!$tableName!! where !!travel!!!!if pumpid > 0:!!!!inc indent!! and !!dec indent!!!!@name!! = ?!!leave!!;");
	}
	SetStatementFor!!$className!!PrimaryKey(m_!!$className!!DeleteStatement!!travel!!, record->!!@name!!!!leave!!);
	return m_!!$className!!DeleteStatement->execute();
}
!!leave!!
!!entry fields!!
bool Dbo::Update!!$className!!(!!$className!!* record)
{
	if (m_!!$className!!UpdateStatement == nullptr)
	{
		m_!!$className!!UpdateStatement = m_DBConnection->prepareStatement("replace into !!$tableName!! Values(!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!?!!leave!!);");
	}
	SetStatementFor!!$className!!Record(m_!!$className!!UpdateStatement, record);
	return m_!!$className!!UpdateStatement->execute();
}
!!leave!!
!!entry primarykey!!
!!$className!!* Dbo::Query!!$className!!FromPrimaryKey(!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!const C!!$fieldTypeName!!Type& !!@name!!!!leave!!)
{
	if (m_!!$className!!PrimaryKeyStatement == nullptr)
	{
		m_!!$className!!PrimaryKeyStatement = m_DBConnection->prepareStatement("select * from !!$tableName!! where !!travel!!!!if pumpid > 0:!!!!inc indent!! and !!dec indent!!!!@name!! = ?!!leave!!;");
	}
	SetStatementFor!!$className!!PrimaryKey(m_!!$className!!PrimaryKeyStatement!!travel!!, !!@name!!!!leave!!);
	auto result = m_!!$className!!PrimaryKeyStatement->executeQuery();
	if (result->next())
	{
		return Get!!$className!!Record(result);
	}
	return nullptr;
}
!!leave!!
!!entry uniquekeys!!
!!travel!!
!!$className!!* Dbo::Query!!$className!!FromUniqueKey!!@name!!(!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!const C!!$fieldTypeName!!Type& !!@name!!!!leave!!)
{
	if (m_!!$className!!UniqueKeyStatement!!@name!! == nullptr)
	{
		m_!!$className!!UniqueKeyStatement!!@name!! = m_DBConnection->prepareStatement("select * from !!$tableName!! where !!travel!!!!if pumpid > 0:!!!!inc indent!! and !!dec indent!!!!@name!! = ?!!leave!!;");
	}
	SetStatementFor!!$className!!UniqueKey!!@name!!(m_!!$className!!UniqueKeyStatement!!@name!!!!travel!!, !!@name!!!!leave!!);
	auto result = m_!!$className!!UniqueKeyStatement!!@name!!->executeQuery();
	if (result->next())
	{
		return Get!!$className!!Record(result);
	}
	return nullptr;
}
!!leave!!
!!leave!!
!!entry indexes!!
!!travel!!
void Dbo::Query!!$className!!FromIndex!!@name!!(std::vector<!!$className!!*>& records!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!)
{
	if (m_!!$className!!IndexStatement!!@name!! == nullptr)
	{
		m_!!$className!!IndexStatement!!@name!! = m_DBConnection->prepareStatement("select * from !!$tableName!! where !!travel!!!!if pumpid > 0:!!!!inc indent!! and !!dec indent!!!!@name!! = ?!!leave!!;");
	}
	SetStatementFor!!$className!!Index!!@name!!(m_!!$className!!IndexStatement!!@name!!!!travel!!, !!@name!!!!leave!!);
	auto result = m_!!$className!!IndexStatement!!@name!!->executeQuery();
	while (result->next())
	{
		auto record = Get!!$className!!Record(result);
		records.push_back(record);
	}
}
!!leave!!
!!leave!!
!!entry fields!!
void Dbo::SetStatementFor!!$className!!Record(sql::PreparedStatement* statement, !!$className!!* record)
{
!!travel!!
!!index = pumpid + 1!!
!!dataType = dataTypes[@type]!!
!!if dataType == 'bool':!!
!!inc indent!!
	statement->setBoolean(!!$index!!, record->!!@name!!);
!!dec indent!!
!!if dataType == 'int':!!
!!inc indent!!
	statement->setInt(!!$index!!, record->!!@name!!);
!!dec indent!!
!!if dataType == 'int64':!!
!!inc indent!!
	statement->setInt64(!!$index!!, record->!!@name!!);
!!dec indent!!
!!if dataType == 'double':!!
!!inc indent!!
	statement->setDouble(!!$index!!, record->!!@name!!);
!!dec indent!!
!!if dataType == 'string':!!
!!inc indent!!
	statement->setString(!!$index!!, record->!!@name!!);
!!dec indent!!
!!if dataType == 'enum':!!
!!inc indent!!
	statement->setInt(!!$index!!, int(record->!!@name!!));
!!dec indent!!
!!leave!!
}
!!leave!!
!!entry primarykey!!
void Dbo::SetStatementFor!!$className!!PrimaryKey(sql::PreparedStatement* statement!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!)
{
!!travel!!
!!index = pumpid + 1!!
!!fieldTypeName = fieldTypeNames[@name]!!
!!dataType = dataTypes[fieldTypeName]!!
!!if dataType == 'bool':!!
!!inc indent!!
	statement->setBoolean(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'int':!!
!!inc indent!!
	statement->setInt(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'int64':!!
!!inc indent!!
	statement->setInt64(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'double':!!
!!inc indent!!
	statement->setDouble(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'string':!!
!!inc indent!!
	statement->setString(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'enum':!!
!!inc indent!!
	statement->setInt(!!$index!!, int(!!@name!!));
!!dec indent!!
!!leave!!
}
!!leave!!
!!entry uniquekeys!!
!!travel!!
void Dbo::SetStatementFor!!$className!!UniqueKey!!@name!!(sql::PreparedStatement* statement!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!)
{
!!travel!!
!!index = pumpid + 1!!
!!fieldTypeName = fieldTypeNames[@name]!!
!!dataType = dataTypes[fieldTypeName]!!
!!if dataType == 'bool':!!
!!inc indent!!
	statement->setBoolean(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'int':!!
!!inc indent!!
	statement->setInt(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'int64':!!
!!inc indent!!
	statement->setInt64(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'double':!!
!!inc indent!!
	statement->setDouble(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'string':!!
!!inc indent!!
	statement->setString(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'enum':!!
!!inc indent!!
	statement->setInt(!!$index!!, int(!!@name!!));
!!dec indent!!
!!leave!!
}
!!leave!!
!!leave!!
!!entry indexes!!
!!travel!!
void Dbo::SetStatementFor!!$className!!Index!!@name!!(sql::PreparedStatement* statement!!travel!!!!fieldTypeName = fieldTypeNames[@name]!!, const C!!$fieldTypeName!!Type& !!@name!!!!leave!!)
{
!!travel!!
!!index = pumpid + 1!!
!!fieldTypeName = fieldTypeNames[@name]!!
!!dataType = dataTypes[fieldTypeName]!!
!!if dataType == 'bool':!!
!!inc indent!!
	statement->setBoolean(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'int':!!
!!inc indent!!
	statement->setInt(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'int64':!!
!!inc indent!!
	statement->setInt64(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'double':!!
!!inc indent!!
	statement->setDouble(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'string':!!
!!inc indent!!
	statement->setString(!!$index!!, !!@name!!);
!!dec indent!!
!!if dataType == 'enum':!!
!!inc indent!!
	statement->setInt(!!$index!!, int(!!@name!!));
!!dec indent!!
!!leave!!
}
!!leave!!
!!leave!!
!!$className!!* Dbo::Get!!$className!!Record(sql::ResultSet* result)
{
	!!$className!!* record = new !!$className!!();
!!entry fields!!
!!travel!!
!!index = pumpid + 1!!
!!dataType = dataTypes[@type]!!
!!if dataType == 'bool':!!
!!inc indent!!
	record->!!@name!! = result->getBoolean(!!$index!!);
!!dec indent!!
!!if dataType == 'int':!!
!!inc indent!!
	record->!!@name!! = result->getInt(!!$index!!);
!!dec indent!!
!!if dataType == 'int64':!!
!!inc indent!!
	record->!!@name!! = result->getInt64(!!$index!!);
!!dec indent!!
!!if dataType == 'double':!!
!!inc indent!!
	record->!!@name!! = result->getDouble(!!$index!!);
!!dec indent!!
!!if dataType == 'string':!!
!!inc indent!!
	strcpy(record->!!@name!!, result->getString(!!$index!!).c_str());
!!dec indent!!
!!if dataType == 'enum':!!
!!inc indent!!
	record->!!@name!! = C!!@type!!Type(result->getInt(!!$index!!));
!!dec indent!!
!!leave!!
!!leave!!
	return record;
}

!!leave!!
!!leave!!
