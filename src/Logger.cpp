#include "Logger.h"

#include <iostream>

void CafeMoi::Logger::log(const std::string& context, const std::string& message)
{
    std::cout << "[  Log  ] "<< context << "\t" << message << "\n";
}

void CafeMoi::Logger::error(const std::string& context, const std::string& message)
{
    std::cerr << "[ Error ] "<< context << "\t" << message << "\n";
}