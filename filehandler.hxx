#pragma once

#include <fstream>
#include <string>  // For std::string

class FileHandler {
private:
    static std::ofstream writer;

public:
    FileHandler();
    FileHandler(const std::string& filename);  // Pass by reference to avoid unnecessary copies

    static void open(const std::string& filename);
    static void write(const std::string& content);
    static void close();
};
