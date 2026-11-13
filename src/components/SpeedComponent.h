#ifndef CAFEMOI_SPEED_COMPONENT_H
#define CAFEMOI_SPEED_COMPONENT_H

#include <SFML/System/Vector2.hpp>

struct SpeedComponent
{

    sf::Vector2f current;

    SpeedComponent(sf::Vector2f initial = sf::Vector2f(0.f, 0.f));

};

#endif
