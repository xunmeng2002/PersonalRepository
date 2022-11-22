#include "DboDataStruct.h"
#include <string>

thread_local char t_DataStringBuffer[10240];

!!types = {}!!
!!formats = {}!!
!!entry types!!
!!entry bools!!
!!travel!!
!!formats[@name] = '%d'!!
!!types[@name] = 'bool'!!
!!leave!!
!!leave!!
!!entry ints!!
!!travel!!
!!formats[@name] = '%d'!!
!!types[@name] = 'int'!!
!!leave!!
!!leave!!
!!entry int64s!!
!!travel!!
!!formats[@name] = '%lld'!!
!!types[@name] = 'int64'!!
!!leave!!
!!leave!!
!!entry doubles!!
!!travel!!
!!formats[@name] = '%f'!!
!!types[@name] = 'double'!!
!!leave!!
!!leave!!
!!entry strings!!
!!travel!!
!!formats[@name] = '%s'!!
!!types[@name] = 'string'!!
!!leave!!
!!leave!!
!!entry enums!!
!!travel!!
!!formats[@name] = '%c'!!
!!types[@name] = 'enum'!!
!!leave!!
!!leave!!
!!entry datetimes!!
!!travel!!
!!formats[@name] = '%s'!!
!!types[@name] = 'datetime'!!
!!leave!!
!!leave!!
!!leave!!


!!entry tables!!
!!travel!!
!!tableName = "Dbo" + @name!!
const char* !!$tableName!!::GetString() const
{
!!entry fields!!
	sprintf(t_DataStringBuffer, "!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!format = formats[@type]!!!!$format!!!!leave!!",
		!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!if types[@type] == 'enum':!!!!inc indent!!(char)!!dec indent!!!!@name!!!!leave!!);
	return t_DataStringBuffer;
!!leave!!
}
const char* !!$tableName!!::GetDebugString() const
{
!!entry fields!!
	sprintf(t_DataStringBuffer, "!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!format = formats[@type]!!!!@name!!:[!!$format!!]!!leave!!",
		!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!if types[@type] == 'enum':!!!!inc indent!!(char)!!dec indent!!!!@name!!!!leave!!);
	return t_DataStringBuffer;
!!leave!!
}

!!leave!!
!!leave!!

