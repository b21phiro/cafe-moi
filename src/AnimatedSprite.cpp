#include "AnimatedSprite.h"

#include <iostream>

#include "Logger.h"

CafeMoi::AnimatedSprite::AnimatedSprite(
    const sf::Texture& texture,
    std::map<std::string, std::vector<sf::IntRect>>&& animations,
    std::map<std::string, std::vector<int>>&& timings
)
    : Sprite(texture, {{0, 0}, {0,0}})
    , elapsedTime(0)
    , animations(std::move(animations))
    , timings(std::move(timings))
    , animationFrameIndexMap({})
{
    setAnimation(this->animations.begin()->first);
}

void CafeMoi::AnimatedSprite::setAnimation(const std::string& name)
{
    if (animations.find(name) == animations.end())
    {
        Logger::error("AnimatedSprite : setAnimation", "There\'s no animation registered with the name \""+name+"\"");
        return;
    }
    resetCurrentAnimation();
    currentAnimation = name;
    animationFrameIndexMap[name] = 0;
}

void CafeMoi::AnimatedSprite::update(const sf::Time& timeElapsed)
{
    std::cout << elapsedTime << std::endl;
    const auto& frame = getCurrentFrame();
    setTextureRect(frame);
    if (const auto& frameDuration = getCurrentFrameTiming(); elapsedTime >= frameDuration)
    {
        nextFrame();
        elapsedTime = 0;
    }
    elapsedTime += timeElapsed.asMilliseconds();
}

sf::IntRect& CafeMoi::AnimatedSprite::getCurrentFrame()
{
    const int index = animationFrameIndexMap[currentAnimation];
    auto& frame = animations[currentAnimation][index];
    return frame;
}

void CafeMoi::AnimatedSprite::nextFrame()
{
    if (const int index = animationFrameIndexMap[currentAnimation];
        index >= animations[currentAnimation].size() - 1)
    {
        animationFrameIndexMap[currentAnimation] = 0;
    } else
    {
        animationFrameIndexMap[currentAnimation]++;
    }
}

int CafeMoi::AnimatedSprite::getCurrentFrameTiming()
{
    const int index = animationFrameIndexMap[currentAnimation];
    return timings[currentAnimation][index];
}

void CafeMoi::AnimatedSprite::resetCurrentAnimation()
{
    if (currentAnimation.empty()) return;
    animationFrameIndexMap[currentAnimation] = 0;
}
