#ifndef CAFEMOI_POSITION_COMPONENT_H
#define CAFEMOI_POSITION_COMPONENT_H

#include "Component.h"
#include <SFML/System/Vector2.hpp>

namespace CafeMoi
{
    struct PositionComponent : Component
    {

        sf::Vector2f value;

        PositionComponent(const int entity, sf::Vector2f&& value)
            : Component(entity)
            , value(value)
        {}

    };
}

#endif
