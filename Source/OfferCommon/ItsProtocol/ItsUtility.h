#pragma once
#include <string>
#include <vector>

void GetItsItems(const char* buff, const char* end, std::vector<std::string>& items);

const char* GetItsItemEnd(const char* buff, const char* end, char op = '|');

bool CheckItsMessage(const std::vector<std::string>& items);
