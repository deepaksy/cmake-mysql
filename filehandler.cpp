#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "filehandler.hxx"

// Define the static member outside the class
std::ofstream FileHandler::writer;

FileHandler::FileHandler() {
    // Default constructor, no initialization
}

FileHandler::FileHandler(const std::string& filename) {
    try {
        writer.open(filename, std::ios::out | std::ios::trunc);
        if (!writer) {
            throw std::ios_base::failure("Failed to open the file");
        }
    } catch (const std::exception& e) {  // Catch by reference to avoid copy
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
}

void FileHandler::write(const std::string& content) {
    if (writer.is_open()) {
        writer << content << std::endl;
    } else {
        std::cerr << "File is not open!" << std::endl;
    }
}

void FileHandler::close() {
    if (writer.is_open()) {
        writer.close();
    }
}

void FileHandler::open(const std::string& filename) {
    try {
        writer.open(filename, std::ios::app);
        if (!writer) {
            throw std::ios_base::failure("Failed to open the file");
        }
        auto now = std::chrono::system_clock::now();

        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        writer << "****************** PROGRAM STARTED ******************" << std::endl;
        writer << "Start time: "<< std::ctime(&now_time) << std::endl;
    } catch (const std::exception& e) {  // Catch by reference to avoid copy
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
}
