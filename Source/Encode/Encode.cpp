#include "Encode.h"
#include <codecvt>


std::vector<wchar_t> Encode::m_WcharBuffs;
std::vector<char> Encode::m_CharBuffs;

std::wstring Encode::to_wstring(const std::string& str, const std::locale& loc)
{
    m_WcharBuffs.clear();
    m_WcharBuffs.resize(str.size());
    std::use_facet<std::ctype<wchar_t>>(loc).widen(str.data(), str.data() + str.size(), m_WcharBuffs.data());
    return std::wstring(m_WcharBuffs.data(), m_WcharBuffs.size());
}
std::string Encode::to_string(const std::wstring& str, const std::locale& loc)
{
    m_CharBuffs.clear();
    m_CharBuffs.resize(str.size());
    std::use_facet<std::ctype<wchar_t>>(loc).narrow(str.data(), str.data() + str.size(), '?', m_CharBuffs.data());
    return std::string(m_CharBuffs.data(), m_CharBuffs.size());
}
std::wstring Encode::utf8_to_wstring(const std::string& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
}
std::string Encode::wstring_to_utf8(const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.to_bytes(str);
}