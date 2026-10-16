#include "AnimatedSpriteComponent.h"
#include "../Logger.h"

CafeMoi::AnimatedSpriteComponent::AnimatedSpriteComponent(
    const int entity,
    sf::Sprite&& sprite,
    std::map<std::string, std::vector<sf::IntRect>>&& animations,
    std::map<std::string, std::vector<int>>&& timings
)
    : Component(entity)
    , sprite(sprite)
    , elapsedTime(sf::Time::Zero)
    , animations(std::move(animations))
    , timings(std::move(timings))
    , animationFrameIndexMap({})
{
    setAnimation(this->animations.begin()->first);
}

void CafeMoi::AnimatedSpriteComponent::setAnimation(const std::string& name)
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

void CafeMoi::AnimatedSpriteComponent::update(const sf::Time& timeElapsed)
{
    elapsedTime += timeElapsed;

    while (elapsedTime >= getCurrentFrameTiming())
    {
        elapsedTime -= getCurrentFrameTiming();
        nextFrame();
    }

    sprite.setTextureRect(getCurrentFrame());
}

sf::IntRect& CafeMoi::AnimatedSpriteComponent::getCurrentFrame()
{
    const int index = animationFrameIndexMap[currentAnimation];
    auto& frame = animations[currentAnimation][index];
    return frame;
}

void CafeMoi::AnimatedSpriteComponent::nextFrame()
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

sf::Time CafeMoi::AnimatedSpriteComponent::getCurrentFrameTiming()
{
    const int index = animationFrameIndexMap[currentAnimation];
    return sf::milliseconds(timings[currentAnimation][index]);
}

void CafeMoi::AnimatedSpriteComponent::resetCurrentAnimation()
{
    if (currentAnimation.empty()) return;
    animationFrameIndexMap[currentAnimation] = 0;
}
