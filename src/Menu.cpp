#include "Menu.h"

#include "SFML/Graphics/RenderWindow.hpp"

Menu::Menu(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
    , m_backgroundColor(sf::Color(208, 245, 126))
{

}

void Menu::draw(sf::RenderWindow &window)
{
    window.clear(m_backgroundColor);
    window.display();
}
