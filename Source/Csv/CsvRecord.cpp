#include "CsvRecord.h"
#include "CsvParser.h"

CSVRecord::CSVRecord()
{
	m_NameBufferLen = 0;
	m_ContentBufferLen = 0;
	m_Separator = ',';

	m_NameBuffer = new char[CSV_RECORD_MAX_HEAD_SIZE];
	m_ContentBuffer = new char[CSV_RECORD_MAX_CONTENT_SIZE];
}
CSVRecord::~CSVRecord()
{
	delete m_NameBuffer;
	delete m_ContentBuffer;
}


void CSVRecord::SetSeparator(char chSeparator)
{
	m_Separator = chSeparator;
}
bool CSVRecord::Analysis(const char *pszFieldName, const char *pszFieldContent)
{
	if (!AnalysisFieldName(pszFieldName))
	{
		return false;
	}
	return AnalysisFieldContent(pszFieldContent);
}
bool CSVRecord::AnalysisFieldName(const char* pszFieldName)
{
	m_NameBufferLen = 0;
	m_CSVFields.clear();
	m_mapCSVField.clear();

	CSVParser csvParser(pszFieldName);
	csvParser.SetSeparator(m_Separator);
	TCSVField field = { nullptr, nullptr };

	do
	{
		char* pszToken = csvParser.GetNextToken();
		if (pszToken == nullptr)
		{
			break;
		}
		field.pFieldName = AppendNameToken(pszToken);
		m_CSVFields.push_back(field);
	} while (csvParser.GetErrorCode() == CSV_PARSER_ERROR::CPE_HAS_NEXT);

	return true;
}
bool CSVRecord::AnalysisFieldContent(const char* pszFieldContent)
{
	m_ContentBufferLen = 0;

	CSVParser csvParser(pszFieldContent);
	for (unsigned int i = 0; i < m_CSVFields.size(); i++)
	{
		char* pszToken = csvParser.GetNextToken();
		if (pszToken == nullptr)
		{
			break;
		}
		m_CSVFields[i].pFieldContent = AppendContentToken(pszToken);
		m_mapCSVField[m_CSVFields[i].pFieldName] = m_CSVFields[i].pFieldContent;
	}

	return true;
}

int CSVRecord::GetFieldCount()
{
	return int(m_CSVFields.size());
}
const char* CSVRecord::GetFieldName(int nIndex)
{
	return m_CSVFields[nIndex - 1].pFieldName;
}
const char* CSVRecord::GetFieldContent(int nIndex)
{
	return m_CSVFields[nIndex - 1].pFieldContent;
}
const char* CSVRecord::GetFieldAsString(const char* pszFieldName)
{
	CCSVFieldMap::iterator itor = m_mapCSVField.find(pszFieldName);
	if (itor == m_mapCSVField.end())
	{
		return nullptr;
	}

	return (*itor).second;
}
int CSVRecord::GetFieldAsInt(const char* pszFieldName)
{
	const char* pszFieldContent = GetFieldAsString(pszFieldName);
	if (pszFieldContent == nullptr)
	{
		return 0;
	}
	return atoi(pszFieldContent);
}
double CSVRecord::GetFieldAsDouble(const char* pszFieldName)
{
	const char* pszFieldContent = GetFieldAsString(pszFieldName);
	if (pszFieldContent == nullptr)
	{
		return DBL_MAX;
	}
	if (*pszFieldContent == '\0')
	{
		return DBL_MAX;
	}

	return atof(pszFieldContent);
}

char *CSVRecord::AppendNameToken(const char *pszToken)
{
	size_t nTokenLen = strlen(pszToken) + 1;
	char *pszTarget = m_NameBuffer+m_NameBufferLen;
	memcpy(m_NameBuffer+m_NameBufferLen, pszToken, nTokenLen);
	m_NameBufferLen += nTokenLen;
	return pszTarget;
}
char *CSVRecord::AppendContentToken(const char *pszToken)
{
	size_t nTokenLen = strlen(pszToken) + 1;
	char *pszTarget = m_ContentBuffer+m_ContentBufferLen;
	memcpy(m_ContentBuffer+m_ContentBufferLen, pszToken, nTokenLen);
	m_ContentBufferLen += nTokenLen;
	return pszTarget;
}

#if 0
int main()
{
	const char *pszFieldName = "name,age,money";
	const char *pszFieldContent = "\"peter pan\",\"20\",\"123.5\"";
	CSVRecord record;
	if (!record.Analysis(pszFieldName, pszFieldContent))
	{
		printf("Analysis fail\n");
		return -1;
	}
	int i = 0;
	for (i=1; i<=record.GetFieldCount(); i++)
	{
		printf("[%s] : [%s]\n", record.GetFieldName(i), record.GetFieldContent(i));
	}
	
	printf("name = [%s]\n", record.GetFieldAsString("name"));
	printf("age = [%d]\n", record.GetFieldAsInt("age"));
	printf("money = [%lf]\n", record.GetFieldAsDouble("money"));
	printf("error str = [%s]\n", record.GetFieldAsString("error str"));
	printf("error int = [%d]\n", record.GetFieldAsInt("error int"));
	printf("error double = [%lf]\n", record.GetFieldAsDouble("error double"));
	return 0;
}
#endif