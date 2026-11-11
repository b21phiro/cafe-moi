#ifndef CAFEMOI_SPRITE_COMPONENT_H
#define CAFEMOI_SPRITE_COMPONENT_H

#include <memory>
#include <SFML/Graphics/Sprite.hpp>

struct SpriteComponent
{

    std::unique_ptr<sf::Sprite> sprite;

    SpriteComponent();

    explicit SpriteComponent(sf::Sprite sprite);

};

#endif