#pragma once
#include <locale>
#include <codecvt>
#include <string>
#include <vector>


class Encode
{
public:
	static std::wstring to_wstring(const std::string& str, const std::locale& loc = std::locale());

	static std::string to_string(const std::wstring& str, const std::locale& loc = std::locale());

	static std::wstring utf8_to_wstring(const std::string& str);

	static std::string wstring_to_utf8(const std::wstring& str);

private:
	static std::vector<wchar_t> m_WcharBuffs;
	static std::vector<char> m_CharBuffs;
};
