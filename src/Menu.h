#ifndef CAFEMOI_MENU_H
#define CAFEMOI_MENU_H

#include <SFML/Graphics/Color.hpp>

#include "SFML/Graphics/RenderWindow.hpp"

class Cafemoi;

class Menu
{
    Cafemoi& m_cafemoi;

    sf::Color m_backgroundColor;

public:

    Menu(Cafemoi &cafemoi);

    void draw(sf::RenderWindow &window);

};

#endif
