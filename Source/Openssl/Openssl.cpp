#include "Openssl.h"
#include <openssl/hmac.h>
#include <string.h>


void Openssl::Replace(char* data, int len, char oldChar, char newChar)
{
	for (char* p = data; p - data < len; p++)
	{
		if (*p == oldChar)
		{
			*p = newChar;
		}
	}
}

int Openssl::Base64Encode(unsigned char* inData, int inLen, unsigned char* outData)
{
	return EVP_EncodeBlock(outData, inData, inLen);
}
int Openssl::Base64UrlEncode(unsigned char* inData, int inLen, unsigned char* outData)
{
	int outLen = Base64Encode(inData, inLen, outData);
	Replace((char*)outData, outLen, '+', '-');
	Replace((char*)outData, outLen, '/', '_');
	return outLen;
}
int Openssl::Base64Decode(unsigned char* inData, int inLen, unsigned char* outData)
{
	int len = 0;
	if (inLen % 4 != 0)
	{
		len = 4 - inLen % 4;
	}
	unsigned char* newInData = new unsigned char[inLen + len];
	memcpy(newInData, inData, inLen);

	unsigned char* p = (unsigned char*)newInData + inLen;
	for (int i = 0; i < len; i++)
	{
		*p++ = '=';
	}
	inLen += len;

	EVP_DecodeBlock(outData, newInData, inLen);
	int outLen = int(strlen((char*)outData));
	delete[] newInData;
	return outLen;
}
int Openssl::Base64UrlDecode(unsigned char* inData, int inLen, unsigned char* outData)
{
	Replace((char*)inData, inLen, '-', '+');
	Replace((char*)inData, inLen, '_', '/');
	return Base64Decode(inData, inLen, outData);
}

unsigned char* Openssl::HmacSHA1(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen)
{
	return HMAC(EVP_get_digestbyname("SHA1"), key, keyLen, inData, inLen, outData, &outLen);
}
unsigned char* Openssl::HmacSHA224(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen)
{
	return HMAC(EVP_get_digestbyname("SHA224"), key, keyLen, inData, inLen, outData, &outLen);
}
unsigned char* Openssl::HmacSHA256(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen)
{
	return HMAC(EVP_get_digestbyname("SHA256"), key, keyLen, inData, inLen, outData, &outLen);
}
unsigned char* Openssl::HmacSHA384(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen)
{
	return HMAC(EVP_get_digestbyname("SHA384"), key, keyLen, inData, inLen, outData, &outLen);
}
unsigned char* Openssl::HmacSHA512(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen)
{
	return HMAC(EVP_get_digestbyname("SHA512"), key, keyLen, inData, inLen, outData, &outLen);
}
unsigned char* Openssl::HmacMD5(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen)
{
	return HMAC(EVP_get_digestbyname("MD5"), key, keyLen, inData, inLen, outData, &outLen);
}

