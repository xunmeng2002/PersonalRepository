#include "CmeCalculateHmac.h"
#include "Openssl.h"
#include "Logger.h"



std::string calculateHMACOpenssl(const std::string& key, const std::string& canonicalRequest)
{
    unsigned char* keyData = new unsigned char[key.length() + 1]{ 0 };
    unsigned char* decodeKeyData = new unsigned char[key.length() + 1]{ 0 };
    memcpy(keyData, key.c_str(), key.length());

    auto decodeKeyLen = Openssl::Base64UrlDecode(keyData, int(key.length()), decodeKeyData);

    unsigned char* hmacData = new unsigned char[128]{ 0 };
    unsigned int hmacLen = 0;
    Openssl::HmacSHA256((const unsigned char*)canonicalRequest.c_str(), int(canonicalRequest.length()), decodeKeyData, decodeKeyLen, hmacData, hmacLen);

    unsigned char* encodeData = new unsigned char[hmacLen * 2]{ 0 };
    int encodeLen = Openssl::Base64UrlEncode(hmacData, hmacLen, encodeData);
    return std::string((char*)encodeData, encodeLen);
}
