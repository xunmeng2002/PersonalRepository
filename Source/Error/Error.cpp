#include "Error.h"
#include <map>


std::map<int, std::string>* InitErrorMap()
{
	std::map<int, std::string>* errorMap = new std::map<int, std::string>();

	(*errorMap)[ERROR_Success] = "发送成功";
	(*errorMap)[ERROR_PrimaryAccountNotLogin] = "主账号未登录";

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
