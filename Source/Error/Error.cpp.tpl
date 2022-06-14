#include "Error.h"
#include <map>


std::map<int, std::string>* InitErrorMap()
{
	std::map<int, std::string>* errorMap = new std::map<int, std::string>();

!!entry errors!!
!!travel!!
	(*errorMap)[ERROR_!!@name!!] = "!!@desc!!";
!!leave!!
!!leave!!

	return errorMap;
}

static std::map<int, std::string>* ErrorMap = InitErrorMap();

std::string GetErrorMessage(unsigned int errorID)
{
	if(ErrorMap->find(errorID) != ErrorMap->end())
	{
		return (*ErrorMap)[errorID];
	}
	return "";
}
