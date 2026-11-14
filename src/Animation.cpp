#include "Animation.h"
#include <SFML/Graphics/Sprite.hpp>

Animation::Animation(const std::string& name, sf::Sprite& sprite, std::vector<AnimationFrame>&& frames)
    : name(name)
    , isPlaying(true)
    , sprite(sprite)
    , frames(frames)
    , currentFrame(0)
    , timeSinceLastFrame(sf::Time::Zero)
{}

void Animation::update(const sf::Time& delta)
{
    if (!isPlaying)
    {

        return;
    }
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

void Animation::reset()
{
    currentFrame = 0;
    timeSinceLastFrame = sf::Time::Zero;
}

void Animation::pause()
{
    isPlaying = false;
}

void Animation::resume()
{
    isPlaying = true;
}

void Animation::stop()
{
    reset();
    applyCurrentFrame();
    isPlaying = false;
}

void Animation::start()
{
    reset();
    applyCurrentFrame();
    isPlaying = true;
}
