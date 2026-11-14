#include "SpeedComponent.h"

SpeedComponent::SpeedComponent(const sf::Vector2f initial)
    : current(initial)
    , previous(current)
{}

void SpeedComponent::setCurrent(const sf::Vector2f &value)
{
    previous = current;
    current = value;
}

void SpeedComponent::setCurrentX(const float &value)
{
    setCurrent(sf::Vector2f(value, current.y));
}

void SpeedComponent::setCurrentY(const float &value)
{
    setCurrent(sf::Vector2f(current.x, value));
}
