#ifdef _MSC_VER
#pragma warning(disable : 26495)
#endif

#include "MdbTables.h"
#include "Mdb.h"

thread_local char StreamBuff[4096];

!!formatSymbols = {}!!
!!formatSymbols["string"] = "s"!!
!!formatSymbols["int"] = "d"!!
!!formatSymbols["double"] = "f"!!
!!formatSymbols["enum"] = "c"!!

!!entry mdb!!
!!entry tables!!
!!travel!!
int !!@name!!::ToStream(char* buff, int size) const
{
!!entry items!!
	return snprintf(buff, size, "!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!! !!itemType=formatSymbols[@type]!!'%!!$itemType!!'!!leave!!",
		!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@name!!!!if @type == "string":!!!!inc indent!!.c_str()!!dec indent!!!!leave!!);
!!leave!!
}
int !!@name!!::ToString(char* buff, int size) const
{
!!entry items!!
	return snprintf(buff, size, "Mdb!!@name!!: !!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@name!!!!itemType=formatSymbols[@type]!!:[%!!$itemType!!]!!leave!!",
		!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@name!!!!if @type == "string":!!!!inc indent!!.c_str()!!dec indent!!!!leave!!);
!!leave!!
}
string !!@name!!::CreateSql()
{
	return "CREATE TABLE IF NOT EXISTS t_Mdb!!@name!!(!!entry items!!!!travel!!!!@name!! char(!!@len!!), !!leave!!!!leave!!!!entry primarykey!!PRIMARY KEY(!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@name!!!!leave!!!!leave!!));";
}
string !!@name!!::InsertSql()
{
	::memset(StreamBuff, 0, sizeof(StreamBuff));
	ToStream(StreamBuff, 4096);
	return "REPLACE INTO t_Mdb!!@name!! VALUES(" + string(StreamBuff) + ");";
}
int !!@name!!::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)
{
	auto field = new !!@name!!();
!!entry items!!
!!travel!!
!!if @type == 'enum':!!
!!inc indent!!
	field->!!@name!! = ConvertTo!!@name!!(colValues[!!$pumpid!!]);
!!dec indent!!
!!elif @type == 'int':!!
!!inc indent!!
	field->!!@name!! = atoi(colValues[!!$pumpid!!]);
!!dec indent!!
!!elif @type == 'double':!!
!!inc indent!!
	field->!!@name!! = atof(colValues[!!$pumpid!!]);
!!dec indent!!
!!else:!!
!!inc indent!!
	field->!!@name!! = colValues[!!$pumpid!!];
!!dec indent!!
!!leave!!
!!leave!!

	((MdbCallback*)callback)->SelectMdb!!@name!!Callback(field);
	return 0;
}

!!leave!!
!!leave!!
!!leave!!
