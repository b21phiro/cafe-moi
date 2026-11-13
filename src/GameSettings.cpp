#include "GameSettings.h"

GameSettings::GameSettings()
    : m_screenSize({ 1280u, 720u })
{
}

sf::Vector2u& GameSettings::getScreenSize()
{
    return m_screenSize;
}

