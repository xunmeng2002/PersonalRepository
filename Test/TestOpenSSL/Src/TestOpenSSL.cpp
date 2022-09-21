#include <openssl/hmac.h>
#include "OpenSSL.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>


void Print(const unsigned char* data, int len)
{
	for (auto p = data; p - data < len; p++)
	{
		printf("%02X", *p);
	}
	printf("\n");
}
void HmacCalculate(const char* name, unsigned char* inData, int inLen, unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen)
{
	if (strcmp(name, "SHA1") == 0)
	{
		OpenSSL::HmacSHA1(inData, inLen, key, keyLen, outData, outLen);
	}
	else if (strcmp(name, "SHA224") == 0)
	{
		OpenSSL::HmacSHA224(inData, inLen, key, keyLen, outData, outLen);
	}
	else if (strcmp(name, "SHA256") == 0)
	{
		OpenSSL::HmacSHA256(inData, inLen, key, keyLen, outData, outLen);
	}
	else if (strcmp(name, "SHA384") == 0)
	{
		OpenSSL::HmacSHA384(inData, inLen, key, keyLen, outData, outLen);
	}
	else if (strcmp(name, "SHA512") == 0)
	{
		OpenSSL::HmacSHA512(inData, inLen, key, keyLen, outData, outLen);
	}
	else if (strcmp(name, "MD5") == 0)
	{
		OpenSSL::HmacMD5(inData, inLen, key, keyLen, outData, outLen);
	}
	printf("HMAC By:[%s], hmacOutLen:[%d] strlen(hmacOut):[%lld]\n", name, outLen, (long long)strlen((char*)outData));
	Print(outData, outLen);

	printf("\n");
}

int main()
{
	unsigned char* key = new unsigned char[1024]{ 0 };
	memcpy(key, "MCDcTzCDusVFFmM5mfQ6NtBFeZDPdcoMvg_kbPh5trM", strlen("MCDcTzCDusVFFmM5mfQ6NtBFeZDPdcoMvg_kbPh5trM"));
	int inLen = strlen((const char*)key);

	unsigned char decodeKey[1024] = { 0 };
	auto decodeKeyLen = OpenSSL::Base64UrlDecode(key, inLen, decodeKey);

	Print(decodeKey, decodeKeyLen);
	printf("decodeKeyLen:[%d], strlen(decodeKey):[%lld]\n", decodeKeyLen, (long long)strlen((const char*)decodeKey));

	unsigned char* hmacOut = new unsigned char[1024]{ 0 };
	unsigned char* target = new unsigned char[1024]{ 0 };
	memcpy(target, "1168\n2F5004U\n004\n20220805-10:13:36.577\nG\n30\nCN\nTEST_BYIFTS\n1.0\nBoyee", strlen("1168\n2F5004U\n004\n20220805-10:13:36.577\nG\n30\nCN\nTEST_BYIFTS\n1.0\nBoyee"));
	int targetLen = strlen((char*)target);
	Print(target, targetLen);
	printf("targetLen:[%d]\n", targetLen);

	unsigned int hmacOutLen = 0;
	HmacCalculate("SHA1", target, targetLen, decodeKey, decodeKeyLen, hmacOut, hmacOutLen);
	HmacCalculate("SHA224", target, targetLen, decodeKey, decodeKeyLen, hmacOut, hmacOutLen);
	HmacCalculate("SHA256", target, targetLen, decodeKey, decodeKeyLen, hmacOut, hmacOutLen);
	HmacCalculate("SHA384", target, targetLen, decodeKey, decodeKeyLen, hmacOut, hmacOutLen);
	HmacCalculate("SHA512", target, targetLen, decodeKey, decodeKeyLen, hmacOut, hmacOutLen);
	HmacCalculate("MD5", target, targetLen, decodeKey, decodeKeyLen, hmacOut, hmacOutLen);


	unsigned char* encodeData = new unsigned char[1024]{ 0 };
	int encodeLen = OpenSSL::Base64UrlEncode(hmacOut, strlen((char*)hmacOut), encodeData);
	printf("encodeLen:[%d], encodeData:[%s]\n", encodeLen, encodeData);

	return 0;
}