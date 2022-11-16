#include "StructWriteLogFunc.h"
#include "Logger.h"

!!types={}!!
!!types['char']='c'!!
!!types['short']='d'!!
!!types['int']='d'!!
!!types['double']='f'!!
!!types['string']='s'!!

!!entry ctp!!
!!entry fields!!
!!travel!!
void Write!!@shortname!!(!!@name!!* !!@shortname!!)
{
	if(!!@shortname!!)
	{
!!fieldName=@shortname!!
		WRITE_LOG(LogLevel::Info, "!!@name!!: !!travel!!!!currType=types[@basetype]!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@name!![%!!$currType!!]!!leave!!",
			!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!$fieldName!!->!!@name!!!!leave!!);
	}
}

!!leave!!
!!leave!!
!!leave!!
