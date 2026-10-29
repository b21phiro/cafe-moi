#ifndef CAFEMOI_MENU_H
#define CAFEMOI_MENU_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace sf { class RenderWindow; }

class Cafemoi;

class Menu
{
    Cafemoi& m_cafemoi;

    sf::Color m_backgroundColor;

    sf::RectangleShape m_playButtonRect;
    sf::RectangleShape m_playButtonRectTopLeft;
    sf::RectangleShape m_playButtonRectTopRight;
    sf::RectangleShape m_playButtonRectTop;
    sf::RectangleShape m_playButtonRectLeft;
    sf::RectangleShape m_playButtonRectRight;
    sf::RectangleShape m_playButtonRectBottomLeft;
    sf::RectangleShape m_playButtonRectBottomRight;
    sf::RectangleShape m_playButtonRectBottom;

    std::unique_ptr<sf::Text> m_playButtonText;

    void initPlayButton();
    void drawPlayButton();

public:

    Menu(Cafemoi &cafemoi);

    void update();

    void draw();

};

#endif
