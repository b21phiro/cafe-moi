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
    animations.insert(std::pair(name, Animation(name, *sprite, std::move(frames))));
}

void AnimatedSpriteComponent::play(const std::string& animationName)
{
    if (animations.find(animationName) == animations.end())
    {
        throw std::runtime_error("*Error* Attempted to play unknown animation: " + animationName);
    }
    if (animation != nullptr)
    {
        if (animation->name == animationName)
        {
            // Do nothing, already playing the animation.
        } else
        {
            animation->stop();
            animation = &animations.at(animationName);
            animation->start();
        }
    } else
    {
        animation = &animations.at(animationName);
        animation->start();
    }
}

void AnimatedSpriteComponent::update(const sf::Time& delta)
{
    if (animation != nullptr && animation->isPlaying)
    {
        animation->update(delta);
    }
}

void AnimatedSpriteComponent::playTheFirstAnimation()
{
    play(animations.begin()->first);
}

void AnimatedSpriteComponent::stop(const std::string& animationName)
{
    if (animations.find(animationName) == animations.end())
    {
        throw std::runtime_error(
            "*Error* Attempted to stop unknown animation: " + animationName
        );
    }

    if (animation != nullptr && animation->name == animationName)
    {
        animation->stop();
        animation = nullptr;
    }
}
