#include "Logger.h"

#include <iostream>

void CafeMoi::Logger::log(std::string context, std::string message)
{
    std::cout << "[  Log  ]\t" << context << "\t\t" << message << "\n";
}

void CafeMoi::Logger::error(std::string context, std::string message)
{
    std::cerr << "[ Error ]\t" << context << "\t\t" << message << "\n";
}