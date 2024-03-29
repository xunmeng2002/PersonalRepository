#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_error.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
using namespace sql;
using namespace sql::mysql;

typedef char CSoftwareType[12];
typedef char CAuthCodeType[16];
typedef int CAccountType;
struct DboAuthorizedSoftware
{
public:
	CSoftwareType Software;
	CAuthCodeType AuthCode;
	CAccountType Account;
};

char m_Sql[4096];
sql::Statement* m_Statement;

bool InsertDboAuthorizedSoftware(DboAuthorizedSoftware* record)
{
	sprintf(m_Sql, "insert into t_AuthorizedSoftware Values('%s', '%s', '%d');", record->Software, record->AuthCode, record->Account);
	return m_Statement->execute(m_Sql);
}
bool DeleteDboAuthorizedSoftware(DboAuthorizedSoftware* record)
{
	sprintf(m_Sql, "delete from t_AuthorizedSoftware WHERE Software = '%s' AND Account = '%d';", record->Software, record->Account);
	return m_Statement->execute(m_Sql);
}
bool UpdateDboAuthorizedSoftware(DboAuthorizedSoftware* record)
{
	sprintf(m_Sql, "replace into t_AuthorizedSoftware Values('%s', '%s', '%d');", record->Software, record->AuthCode, record->Account);
	return m_Statement->executeUpdate(m_Sql);
}
DboAuthorizedSoftware* QueryDboAuthorizedSoftwareFromPrimaryKey(const CSoftwareType& software, const CAccountType& account)
{
	sprintf(m_Sql, "select * from t_AuthorizedSoftware where Software = '%s' and Account = '%d';", software, account);
	auto result = m_Statement->executeQuery(m_Sql);
	if (result->next())
	{
		DboAuthorizedSoftware* record = new DboAuthorizedSoftware();
		strcpy(record->Software, result->getString(1).c_str());
		strcpy(record->AuthCode, result->getString(2).c_str());
		record->Account = result->getInt(3);
		return record;
	}
	return nullptr;
}
DboAuthorizedSoftware* QueryDboAuthorizedSoftwareFromUniqueKeyAuthCode(const CSoftwareType& software, const CAuthCodeType& authCode)
{
	sprintf(m_Sql, "select * from t_AuthorizedSoftware where Software = '%s' and AuthCode = '%s';", software, authCode);
	auto result = m_Statement->executeQuery(m_Sql);
	if (result->next())
	{
		DboAuthorizedSoftware* record = new DboAuthorizedSoftware();
		strcpy(record->Software, result->getString(1).c_str());
		strcpy(record->AuthCode, result->getString(2).c_str());
		record->Account = result->getInt(3);
		return record;
	}
	return nullptr;
}
void QueryDboAuthorizedSoftwareFromIndexAccount(std::vector<DboAuthorizedSoftware*>& records, const CAccountType& account)
{
	sprintf(m_Sql, "select * from t_AuthorizedSoftware where Account = '%d';", account);
	auto result = m_Statement->executeQuery(m_Sql);
	while (result->next())
	{
		DboAuthorizedSoftware* record = new DboAuthorizedSoftware();
		strcpy(record->Software, result->getString(1).c_str());
		strcpy(record->AuthCode, result->getString(2).c_str());
		record->Account = result->getInt(3);
		records.push_back(record);
	}
}

DboAuthorizedSoftware* PrepareDboAuthorizedSoftware(int index)
{
	DboAuthorizedSoftware* record = new DboAuthorizedSoftware();
	strcpy(record->Software, std::to_string(index).c_str());
	strcpy(record->AuthCode, std::to_string(index).c_str());
	record->Account = index;
	return record;
}
void Print(DboAuthorizedSoftware* record)
{
	printf("Software:%s, AuthCode:%s, Account:%d\n", record->Software, record->AuthCode, record->Account);
}
void Test()
{
	for (auto i = 0; i < 10; i++)
	{
		auto record = PrepareDboAuthorizedSoftware(i);
		InsertDboAuthorizedSoftware(record);
	}

	CSoftwareType software("1");
	CAuthCodeType authCode("1");
	auto record = QueryDboAuthorizedSoftwareFromPrimaryKey(software, 1);
	cout << "QueryDboAuthorizedSoftwareFromPrimaryKey" << endl;
	if (record)
	{
		Print(record);
	}
	record = QueryDboAuthorizedSoftwareFromUniqueKeyAuthCode(software, authCode);
	cout << "QueryDboAuthorizedSoftwareFromUniqueKeyAuthCode" << endl;
	if (record)
	{
		Print(record);
	}
	vector<DboAuthorizedSoftware*> records;
	QueryDboAuthorizedSoftwareFromIndexAccount(records, 1);
	cout << "QueryDboAuthorizedSoftwareFromIndexAccount" << endl;
	if (records.size() > 0)
	{
		for (auto record : records)
		{
			Print(record);
		}
	}
}

enum class CTradeStatusType : char
{
	//未知
	Unknown = '0',
	//集合竞价报单
	AuctionOrdering = '1',
	//连续交易
	Trading = '2',
	//暂停
	Pause = '3',
	//收市
	Closed = '4',
};

int main()
{
	Driver* driver = sql::mysql::get_driver_instance();
	string host = "tcp://192.168.2.238:3306/Test";
	string user = "test";
	string passwd = "test";
	Connection* conn = driver->connect(host, user, passwd);
	PreparedStatement* state = conn->prepareStatement("insert into t_AuthorizedSoftware Values(?, ?, ?);");
	PreparedStatement* state2 = conn->prepareStatement("replace into t_AuthorizedSoftware Values(?, ?, ?);");
	PreparedStatement* state3 = conn->prepareStatement("delete from t_AuthorizedSoftware where Account = ? and Software = ?;");
	//state: insert into
	state->setString(1, "100");
	state->setString(2, "100");
	state->setInt(3, 100);
	state->execute();

	state->setString(1, "101");
	state->setString(2, "101");
	state->setInt(3, 101);
	state->execute();

	state->setString(1, "102");
	state->setString(2, "102");
	state->setInt(3, 102);
	state->execute();

	//state2:replace into
	state2->setString(1, "102");
	state2->setString(2, "103");
	state2->setInt(3, 102);
	state2->execute();
	conn->commit();

	//state3:delete
	state3->setInt(1, 100);
	state3->setString(2, "100");
	state3->execute();

	state3->setInt(1, 101);
	state3->setString(2, "101");
	state3->execute();

	state3->setInt(1, 102);
	state3->setString(2, "102");
	state3->execute();

	return 0;
}

