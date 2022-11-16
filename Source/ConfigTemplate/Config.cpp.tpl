#pragma warning(disable: 4311)
#include "Config.h"
#include "json/json.h"
#include "Logger.h"
#include <iostream>
#include <fstream>

!!entry config!!

!!formatSymbols = {}!!
!!formatSymbols["bool"] = "d"!!
!!formatSymbols["int"] = "d"!!
!!formatSymbols["double"] = "f"!!
!!formatSymbols["string"] = "s"!!
Config Config::m_Instance;
Config::Config()
{

}
Config& Config::GetInstance()
{
	return m_Instance;
}
void Config::Load(const char* fileName)
{
	Json::Reader reader;
	Json::FastWriter writer;
	Json::Value root;
	std::ifstream in_file(fileName, std::ios::binary);
	std::cout << "parse: " << reader.parse(in_file, root) << std::endl;
	in_file.close();
!!entry items!!
!!travel!!
!!if @type == "bool":!!
!!inc indent!!
	!!@name!! = root["!!@name!!"].asBool();
!!dec indent!!
!!elif @type == "int":!!
!!inc indent!!
	!!@name!! = root["!!@name!!"].asInt();
!!dec indent!!
!!elif @type == "double":!!
!!inc indent!!
	!!@name!! = root["!!@name!!"].asDouble();
!!dec indent!!
!!elif @type == "string":!!
!!inc indent!!
	!!@name!! = root["!!@name!!"].asString();
!!dec indent!!
!!else:!!
!!inc indent!!
	!!@name!! = root["!!@name!!"].asString();
!!dec indent!!
!!leave!!
!!leave!!
}

void Config::Print()
{
!!entry items!!
	WRITE_LOG(LogLevel::Info, "!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!itemType=formatSymbols[@type]!!!!@name!!:[%!!$itemType!!]!!leave!!",
		!!travel!!!!if pumpid > 0:!!!!inc indent!!, !!dec indent!!!!@name!!!!if @type == "string":!!!!inc indent!!.c_str()!!dec indent!!!!leave!!);
!!leave!!
}

!!leave!!
