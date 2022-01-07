#pragma once
#include <string>
#include "MdbEnumDict.h"



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
	!!@name!! !!@name!!;
!!dec indent!!
!!else:!!
!!inc indent!!
	!!@type!! !!@name!!;
!!dec indent!!
!!leave!!
!!leave!!
	
	static constexpr const char* TableName = "t_Mdb!!@name!!";
private:
	char m_Buff[4096];
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
};

