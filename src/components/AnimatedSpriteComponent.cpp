#include "AnimatedSpriteComponent.h"

#include <iostream>
#include <stdexcept>

AnimatedSpriteComponent::AnimatedSpriteComponent()
    : animation(nullptr)
{}

AnimatedSpriteComponent::AnimatedSpriteComponent(const sf::Sprite &sprite)
    : SpriteComponent(sprite)
    , animation(nullptr)
{}

void AnimatedSpriteComponent::addAnimation(const std::string& name, std::vector<AnimationFrame>&& frames)
{
    animations.insert(std::pair(name, Animation(*sprite, std::move(frames))));
}

void AnimatedSpriteComponent::play(const std::string& animationName)
{
    if (animations.find(animationName) == animations.end())
    {
        throw std::runtime_error("*Error* Attempted to play unknown animation: " + animationName);
    }
    animation = &animations.at(animationName);
}

void AnimatedSpriteComponent::update(const sf::Time& delta)
{
    if (animation == nullptr)
    {
        playTheFirstAnimation();
    }
    animation->update(delta);
}

void AnimatedSpriteComponent::playTheFirstAnimation()
{
    play(animations.begin()->first);
}
