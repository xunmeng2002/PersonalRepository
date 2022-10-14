#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_error.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/resultset.h>
#include <string>

using namespace std;
using namespace sql;
using namespace sql::mysql;


int main()
{
	Driver* driver = sql::mysql::get_driver_instance();
	string host = "tcp://192.168.2.238:3306/Test";
	string user = "test";
	string passwd = "test";
	Connection* conn = driver->connect(host.c_str(), user.c_str(), passwd.c_str());
	conn->setAutoCommit(false);
	auto statement = conn->createStatement();

	char sql[256];
	sprintf(sql, "truncate t_Bank;");
	statement->execute(sql);

	for (auto i = 1; i < 101; i++)
	{
		sprintf(sql, "replace into t_Bank values('%d', '%d', '%d', 'China');", i, i * 10000, i);
		statement->executeUpdate(sql);
	}
	conn->rollback();
	
	sprintf(sql, "select * from t_Bank;");
	auto result = statement->executeQuery(sql);

	while (result->next())
	{
		printf("ID:[%d], Code:[%s], Nation:[%d], Name:[%s]\n", result->getInt(1), result->getString(2).c_str(), result->getInt(3), result->getString(4).c_str());
	}
	conn->commit();

	return 0;
}

