#pragma once

const int TOKEN_MAX_LEN = 64 * 1024; 

enum class CSV_PARSER_ERROR : int
{
	CPE_HAS_NEXT,
	CPE_END,
	CPE_MARK_NOT_MATCH,
	CPE_TOKEN_TOO_LONG,
};

class CSVParser  
{
public:
	CSVParser();
	CSVParser(const char *pszData);
	virtual ~CSVParser();
	void SetSeparator(char chSeparator);
	char *GetNextToken();
	void Parse(const char *pszData);
	CSV_PARSER_ERROR GetErrorCode();
private:
	void NextChar();
	void MakeWord(const char *pszEnd);
private:
	CSV_PARSER_ERROR m_ErrorCode;
	const char *m_Data;
	char* m_CurrWord;
	char *m_Curr;
	char m_CurrChar;
	char m_NextChar;
	char m_Separator[2];
};

