#pragma once
#include <string>
#include <vector>

!!entry protocols!!
!!travel!!
!!travel!!
class Its!!@name!!
{
public:
	Its!!@name!!();
	Its!!@name!!(const std::vector<std::string>& items);
	int ToString(char* buff, int size);
	int ToStream(char* buff, int size);
	static std::string CreateSql();
	std::string InsertSql();
	static int OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames);

public:
!!entry items!!
!!travel!!
	std::string !!@name!!;
!!leave!!
!!leave!!

	static constexpr const char* TableName = "t_Its!!@name!!";
private:
	char m_Buff[4096];
};

!!leave!!
!!leave!!

class ItsMdbCallback
{
public:
!!travel!!
!!travel!!
	virtual void SelectIts!!@name!!Callback(Its!!@name!!* field) { delete field; }
!!leave!!
!!leave!!
!!leave!!
};

