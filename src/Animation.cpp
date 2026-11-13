#include "Animation.h"
#include <SFML/Graphics/Sprite.hpp>

Animation::Animation(sf::Sprite& sprite, std::vector<AnimationFrame>&& frames)
    : sprite(sprite)
    , frames(frames)
    , currentFrame(0)
    , timeSinceLastFrame(sf::Time::Zero)
{}

void Animation::update(const sf::Time& delta)
{
    timeSinceLastFrame += delta;

    while (timeSinceLastFrame >= sf::milliseconds(100))
    {
        timeSinceLastFrame -= sf::milliseconds(100);
        nextFrame();
        applyCurrentFrame();
    }
}

void Animation::nextFrame()
{
    if (currentFrame < std::size(frames) - 1)
    {
        currentFrame++;
    }
    else
    {
        currentFrame = 0;
    }
}

AnimationFrame& Animation::getCurrentFrame()
{
    return frames[currentFrame];
}

void Animation::applyCurrentFrame()
{
    sprite.setTextureRect(getCurrentFrame());
}
