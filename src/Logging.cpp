#include "Logging.h"
#include <iostream>
#include <ostream>

Logging::Logging()
    : logging_level("all")
{}

void Logging::set_logging_level(std::string level)
{
    if (level == "all" || level == "debug" || level == "off")
    {
        logging_level = level;
    }
}

void Logging::debug(const std::string& message)
{
    if (logging_level == "off") return;

    if (logging_level == "all" || logging_level == "debug")
    {
        std::cout << "[debug]\t" << message << "\n";
    }
}

std::string Logging::get_logging_level()
{
    return logging_level;
}
