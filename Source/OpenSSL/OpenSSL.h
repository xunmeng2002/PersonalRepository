#pragma once


class OpenSSL
{
public:
	static void Replace(char* data, int len, char oldChar, char newChar);

	static int Base64Encode(unsigned char* inData, int inLen, unsigned char* outData);
	static int Base64UrlEncode(unsigned char* inData, int inLen, unsigned char* outData);

	static int Base64Decode(unsigned char* inData, int inLen, unsigned char* outData);
	static int Base64UrlDecode(unsigned char* inData, int inLen, unsigned char* outData);

	static unsigned char* HmacSHA1(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen);
	static unsigned char* HmacSHA224(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen);
	static unsigned char* HmacSHA256(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen);
	static unsigned char* HmacSHA384(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen);
	static unsigned char* HmacSHA512(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen);
	static unsigned char* HmacMD5(const unsigned char* inData, int inLen, const unsigned char* key, int keyLen, unsigned char* outData, unsigned int& outLen);


};