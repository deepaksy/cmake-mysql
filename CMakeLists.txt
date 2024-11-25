# Specify the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(HelloProject CXX)  # Use C++ language

# Specify where to find header files for MySQL
include_directories("/home/deepak/Documents/c/mysql/include/jdbc")  # Adjust path as needed

# Add the source files for the project (your C++ files)
set(SOURCE_FILES main.cpp database.cpp)  # Include all your C++ source files

# Add the directory containing the MySQL library
link_directories("/home/deepak/Documents/c/mysql/lib64")  # Adjust path if needed

# Specify the name of the MySQL library to link against
# If you're using the MySQL C++ connector library:
set(MYSQL_LIB mysqlcppconn)  # No need to add 'lib' prefix or '.so' extension
# If you're using the MySQL C client library, use:
# set(MYSQL_LIB mysqlclient)

# Create the executable
add_executable(main ${SOURCE_FILES})

# Link the executable with the MySQL library
target_link_libraries(main ${MYSQL_LIB})

# If MySQL is installed with additional dependencies (like pthreads), you may need to explicitly link those too
# Uncomment the following line if needed
#target_link_libraries(hello pthread)
