#include "database.hxx"  // Include necessary MySQL Connector header files

// Define static members outside the class
sql::Connection* DB::con = nullptr;          // Initialize the static connection pointer to nullptr
sql::mysql::MySQL_Driver* DB::driver = nullptr; // Initialize the static driver pointer to nullptr

sql::Connection* DB::getConnection(std::string host, std::string user, std::string pass) {
    if (con == nullptr) {  // If the connection is not yet established
        driver = sql::mysql::get_driver_instance();  // Get the MySQL driver instance
        con = driver->connect(host, user, pass);  // Establish the connection
    }
    return con;  // Return the existing connection
}