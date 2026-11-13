#ifndef CAFEMOI_GAME_SETTINGS_H
#define CAFEMOI_GAME_SETTINGS_H

#include <SFML/System/Vector2.hpp>

class GameSettings
{

    sf::Vector2u m_screenSize;

public:

    GameSettings();

    sf::Vector2u& getScreenSize();

};

#endif
