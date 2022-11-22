#pragma once
#include <string>



std::string calculateHMACOpenssl(const std::string& key, const std::string& canonicalRequest);

