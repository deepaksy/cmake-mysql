#include "include.hxx"
#include "database.hxx"
#define HOST "tcp://192.168.1.203:9981"
#define USER "root"
#define PASS "Navy@1234"
using namespace std;
using namespace sql;



int main() {
	Statement* stmt;
	ResultSet* rs;
	Connection* conn = DB::getConnection(HOST, USER, PASS);
	conn->setSchema("portfolio");
	stmt = conn->createStatement();
	rs = stmt->executeQuery("select * from projects");
	while (rs->next()) {
		cout << "Project Name: " << rs->getString("name") << endl;
		cout << "Description: " << rs->getString("description") << endl;
		cout << "Github Link: " << rs->getString("github_link") << endl;
		cout << "******************************************" << endl;
	}
	return 0;
}