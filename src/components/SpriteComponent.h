#ifndef CAFEMOI_SPRITE_COMPONENT_H
#define CAFEMOI_SPRITE_COMPONENT_H

#include "Component.h"
#include <SFML/Graphics/Sprite.hpp>

namespace CafeMoi
{

    struct SpriteComponent : Component
    {

        sf::Sprite sprite;

        SpriteComponent(const int entity, sf::Sprite&& sprite)
            : Component(entity)
            , sprite(sprite)
        {}

    };

}

#endif
