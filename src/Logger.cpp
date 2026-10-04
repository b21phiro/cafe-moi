#include "Logger.h"

#include <iostream>

void CafeMoi::Logger::log(std::string context, std::string message)
{
    std::cout << "[  Log  ] " << context << ": " << message << "\n";
}

void CafeMoi::Logger::error(std::string context, std::string message)
{
    std::cerr << "[  Error  ] " << context << ": " << message << "\n";
}