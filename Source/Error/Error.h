#pragma once
#include <string>

#define ERROR_Success 0
#define ERROR_PrimaryAccountNotLogin 10000

std::string GetErrorMessage(unsigned int errorID);

