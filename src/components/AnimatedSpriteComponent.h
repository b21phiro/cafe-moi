#ifndef CAFEMOI_ANIMATED_SPRITE_COMPONENT_H
#define CAFEMOI_ANIMATED_SPRITE_COMPONENT_H

#include "SpriteComponent.h"

struct AnimatedSpriteComponent : SpriteComponent
{

    AnimatedSpriteComponent();

    explicit AnimatedSpriteComponent(const sf::Sprite &sprite);

};

#endif