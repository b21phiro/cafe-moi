#ifndef CAFEMOI_LOGGER_H
#define CAFEMOI_LOGGER_H

#include <string>
#include <SFML/Graphics/Texture.hpp>

namespace CafeMoi
{
    class Logger
    {
    public:

        static void log(const std::string& context, const std::string& message);

        static void error(const std::string& context, const std::string& message);

    };
}

#endif