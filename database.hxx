#pragma once
#ifndef C_DB
#define C_DB
#include "include.hxx"
class DB {
public:
    static sql::Connection* getConnection(std::string host, std::string user, std::string pass);
private:
    static sql::Connection* con;
    static sql::mysql::MySQL_Driver* driver;  // Declaring the static driver
};
#endif