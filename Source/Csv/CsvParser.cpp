#include "CsvParser.h"
#include <string>

using namespace std;

CSVParser::CSVParser()
{
	m_CurrChar = '\0';
	m_NextChar = '\0';
	m_Separator[0] = ',';
	m_Separator[1] = '\0';
	m_Data = nullptr;
	m_Curr = nullptr;
	m_ErrorCode = CSV_PARSER_ERROR::CPE_END;

	m_CurrWord = new char[TOKEN_MAX_LEN + 1];
}
CSVParser::CSVParser(const char *pszData)
{
	m_Separator[0] = ',';
	m_Separator[1] = '\0';
	m_Data = pszData;
	m_Curr = (char *)m_Data;
	NextChar();

	m_CurrWord = new char[TOKEN_MAX_LEN + 1];
}
CSVParser::~CSVParser()
{
	delete m_CurrWord;
}
void CSVParser::SetSeparator(char chSeparator)
{
	m_Separator[0] = chSeparator;
}
char* CSVParser::GetNextToken()
{
	switch (m_CurrChar)
	{
	case '"':
		NextChar();
		MakeWord("\"");
		if (m_CurrChar != '"')
		{
			m_ErrorCode = CSV_PARSER_ERROR::CPE_MARK_NOT_MATCH;
			return nullptr;
		}
		NextChar();
		break;
	default:
		MakeWord(m_Separator);
	}
	if (m_CurrChar == m_Separator[0])
	{
		m_ErrorCode = CSV_PARSER_ERROR::CPE_HAS_NEXT;
		NextChar();
		return m_CurrWord;
	}
	if (m_CurrChar == '\0')
	{
		m_ErrorCode = CSV_PARSER_ERROR::CPE_END;
		return m_CurrWord;
	}

	m_ErrorCode = CSV_PARSER_ERROR::CPE_TOKEN_TOO_LONG;
	return nullptr;
}
void CSVParser::Parse(const char* pszData)
{
	m_Data = pszData;
	m_Curr = (char*)m_Data;
	m_ErrorCode = CSV_PARSER_ERROR::CPE_HAS_NEXT;
	NextChar();

	m_CurrWord = new char[TOKEN_MAX_LEN + 1];
}
CSV_PARSER_ERROR CSVParser::GetErrorCode()
{
	return m_ErrorCode;
}


void CSVParser::NextChar()
{
	m_CurrChar = *m_Curr;
	if (m_CurrChar == '\0' || m_CurrChar == '\r' || m_CurrChar == '\n')
	{
		m_CurrChar = '\0';
		m_NextChar = '\0';
	}
	else
	{
		m_Curr++;
		m_NextChar = *m_Curr;
	}
}
void CSVParser::MakeWord(const char* pszEnd)
{
	int i = 0;
	for (;i < TOKEN_MAX_LEN; i++)
	{
		if (m_CurrChar == '\0')
		{
			break;
		}
		if (strchr(pszEnd, m_CurrChar) != nullptr)
		{
			if (m_CurrChar == '"' && m_NextChar == '"')
			{
				NextChar();
			}
			else
			{
				break;
			}
		}
		m_CurrWord[i] = m_CurrChar;
		NextChar();
	}
	m_CurrWord[i] = '\0';
}

