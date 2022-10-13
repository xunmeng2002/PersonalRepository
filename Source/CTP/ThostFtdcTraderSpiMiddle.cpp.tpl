#include "ThostFtdcTraderSpiMiddle.h"
#include "Logger.h"
#include "StructWriteLogFunc.h"


!!types={}!!
!!types['bool']='d'!!
!!types['char']='c'!!
!!types['short']='d'!!
!!types['int']='d'!!
!!types['double']='f'!!
!!types['string']='s'!!

!!entry ctp!!
!!entry spi!!
!!travel!!
void CThostFtdcTraderSpiMiddle::!!@name!!(!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@type!! !!if @custom == "True":!!!!inc indent!!*p!!dec indent!!!!@name!!!!leave!!)
{
	WRITE_LOG(LogLevel::Info, "!!@name!!:!!travel!!!!if @custom == "False":!!!!inc indent!!!!currType=types[@basetype]!! !!@name!![%!!$currType!!]!!dec indent!!!!leave!!"!!travel!!!!if @custom == "False":!!!!inc indent!!, !!@name!!!!dec indent!!!!leave!!);
!!travel!!
!!if @custom == "True":!!
!!inc indent!!
	Write!!@name!!(p!!@name!!);
!!dec indent!!
!!leave!!
}

!!leave!!
!!leave!!
!!leave!!
