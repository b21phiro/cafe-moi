#ifndef CAFEMOI_LOGGER_H
#define CAFEMOI_LOGGER_H

#include <string>
#include <SFML/Graphics/Texture.hpp>

namespace CafeMoi
{
    class Logger
    {
    public:

        static void log(std::string context, std::string message);

        static void error(std::string context, std::string message);

    };
}

#endif