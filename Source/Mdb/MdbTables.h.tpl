#pragma once
#pragma warning(disable : 26495)
#include <string>
#include "MdbEnumDict.h"

using std::string;

!!entry mdb!!
!!entry tables!!
!!travel!!
class !!@name!!
{
public:
	int ToStream(char* buff, int size) const;
	int ToString(char* buff, int size) const;
	static std::string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
!!entry items!!
!!travel!!
!!if @type == "enum":!!
!!inc indent!!
	!!@name!! !!@name!! = !!@default!!;
!!dec indent!!
!!else:!!
!!inc indent!!
	!!@type!! !!@name!!;
!!dec indent!!
!!leave!!
!!leave!!
	
	static constexpr const char* TableName = "t_Mdb!!@name!!";
};

!!leave!!
!!leave!!

class MdbCallback
{
public:
!!travel tables!!
!!travel!!
	virtual void SelectMdb!!@name!!Callback(!!@name!!* field) { delete field; }
!!leave!!
!!leave!!
!!leave!!
};

