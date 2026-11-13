#include "AnimatedSpriteComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent() = default;

AnimatedSpriteComponent::AnimatedSpriteComponent(const sf::Sprite &sprite)
    : SpriteComponent(sprite)
{}
