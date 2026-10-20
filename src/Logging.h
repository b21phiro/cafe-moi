#ifndef CAFEMOI_LOGGING_H
#define CAFEMOI_LOGGING_H

#include <string>

class Logging
{
public:

    Logging();

    void set_logging_level(std::string level);

    void debug(const std::string& message);

    std::string get_logging_level();

private:

    std::string logging_level;

};

#endif
