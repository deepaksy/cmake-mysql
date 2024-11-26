#include "include.hxx"
#include "database.hxx"
#include "filehandler.hxx"
#include <string>
#include <format>
#define HOST "tcp:hostname:port"
#define USER "user"
#define PASS "pass"
using namespace std;
using namespace sql;



int main() {
	Statement* stmt;
	ResultSet* rs;
	Connection* conn = DB::getConnection(HOST, USER, PASS);
	conn->setSchema("portfolio");
	stmt = conn->createStatement();
	rs = stmt->executeQuery("select * from projects");
		FileHandler::open("output.txt");
	while (rs->next()) {
		string name = rs->getString("name");
		string des = rs->getString("description");
		string github_link = rs->getString("github_link");
		string content = "Name: "+ name +"\nDescription: "+des+"\nGithub Link: "+github_link+"\n****************************";
		FileHandler::write(content);
		cout << "Project Name: " << name << endl;
		cout << "Description: " << des << endl;
		cout << "Github Link: " << github_link << endl;
		cout << "******************************************" << endl;
	}
	FileHandler::close();
	return 0;
}