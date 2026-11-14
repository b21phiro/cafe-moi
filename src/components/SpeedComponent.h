#ifndef CAFEMOI_SPEED_COMPONENT_H
#define CAFEMOI_SPEED_COMPONENT_H

#include <SFML/System/Vector2.hpp>

struct SpeedComponent
{

    sf::Vector2f current;

    sf::Vector2f previous;

    SpeedComponent(sf::Vector2f initial = sf::Vector2f(0.f, 0.f));

    void setCurrent(const sf::Vector2f& value);

    void setCurrentX(const float& value);

    void setCurrentY(const float& value);

};

#endif
