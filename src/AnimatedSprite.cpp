#include "AnimatedSprite.h"

#include "Logger.h"

CafeMoi::AnimatedSprite::AnimatedSprite(
    const sf::Texture& texture,
    std::map<std::string, std::vector<sf::IntRect>>&& animations,
    std::map<std::string, std::vector<int>>&& timings
)
    : Sprite(texture, {{0, 0}, {0,0}})
    , elapsedTime(sf::Time::Zero)
    , animations(std::move(animations))
    , timings(std::move(timings))
    , animationFrameIndexMap({})
{
    setAnimation(this->animations.begin()->first);
}

void CafeMoi::AnimatedSprite::setAnimation(const std::string& name)
{
    if (currentAnimation == name) return;
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
    elapsedTime += timeElapsed;

    while (elapsedTime >= getCurrentFrameTiming())
    {
        elapsedTime -= getCurrentFrameTiming();
        nextFrame();
    }

    setTextureRect(getCurrentFrame());
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

sf::Time CafeMoi::AnimatedSprite::getCurrentFrameTiming()
{
    const int index = animationFrameIndexMap[currentAnimation];
    return sf::milliseconds(timings[currentAnimation][index]);
}

void CafeMoi::AnimatedSprite::resetCurrentAnimation()
{
    if (currentAnimation.empty()) return;
    animationFrameIndexMap[currentAnimation] = 0;
}
