#include "SpriteComponent.h"

SpriteComponent::SpriteComponent()
{

}

SpriteComponent::SpriteComponent(sf::Sprite sprite)
    : sprite(std::make_unique<sf::Sprite>(std::move(sprite)))
{
}
