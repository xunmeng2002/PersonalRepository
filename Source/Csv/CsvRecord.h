#pragma once
#include <vector>
#include <map>


const int CSV_RECORD_MAX_HEAD_SIZE = 1024;
const int CSV_RECORD_MAX_CONTENT_SIZE = 64 * 1024;

class CSVRecord  
{
public:
	CSVRecord();
	virtual ~CSVRecord();
	void SetSeparator(char chSeparator);
	bool Analysis(const char *pszFieldName, const char *pszFieldContent);
	bool AnalysisFieldName(const char *pszFieldName);
	bool AnalysisFieldContent(const char *pszFieldContent);

	int GetFieldCount();
	const char* GetFieldName(int nIndex);
	const char* GetFieldContent(int nIndex);
	const char *GetFieldAsString(const char *pszFieldName);
	int GetFieldAsInt(const char *pszFieldName);
	double GetFieldAsDouble(const char *pszFieldName);
private:
	char *AppendNameToken(const char *pszToken);
	char *AppendContentToken(const char *pszToken);
private:
	struct TCSVField
	{
		char *pFieldName;
		char *pFieldContent;
	};
	std::vector<TCSVField> m_CSVFields;
	struct ltstr
	{
	  bool operator()(const char* s1, const char* s2) const
	  {
		return strcmp(s1, s2) < 0;
	  }
	};
	typedef std::map<const char*, const char *, ltstr> CCSVFieldMap;
	CCSVFieldMap m_mapCSVField;

	char* m_NameBuffer;
	size_t m_NameBufferLen;
	char* m_ContentBuffer;
	size_t m_ContentBufferLen;
	char m_Separator;
};
