#include "Logger.h"

#include <iostream>

void CafeMoi::Logger::log(const std::string& context, const std::string& message)
{
    std::cout << "[ Log ]: "<< context <<": " << message << "\n";
}
