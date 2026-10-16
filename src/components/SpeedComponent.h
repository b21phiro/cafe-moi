#ifndef CAFEMOI_SPEED_COMPONENT_H
#define CAFEMOI_SPEED_COMPONENT_H
#include "Component.h"
#include "SFML/System/Vector2.hpp"

namespace CafeMoi
{
    struct SpeedComponent : Component
    {

        sf::Vector2f value;

        SpeedComponent(const int entity, sf::Vector2f&& value)
            : Component(entity)
            , value(value)
        {}

    };
}

#endif
