#pragma once
#include <string>



std::string calculateHMACOpenSSL(const std::string& key, const std::string& canonicalRequest);

