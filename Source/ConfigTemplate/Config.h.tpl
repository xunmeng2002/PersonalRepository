#pragma once
#include <string>

using std::string;

class Config
{
	Config();
public:
	static Config& GetInstance();
	void Load(const char* fileName);
	void Print();
	
public:
!!entry items!!
!!travel!!
	!!@type!! !!@name!!;
!!leave!!
!!leave!!
	
private:
	static Config m_Instance;
};
