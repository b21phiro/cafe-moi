#include "ComponentManager.h"
#include "Logger.h"

CafeMoi::ComponentManager::ComponentManager()
{
    Logger::log("ComponentManager", "Instance created");
}

void CafeMoi::ComponentManager::registerEntity()
{
    spriteComponents.emplace_back(nullptr);
    animatedSpriteComponents.emplace_back(nullptr);
    positionComponents.emplace_back(nullptr);
    speedComponents.emplace_back(nullptr);
    Logger::log("ComponentManager", "Entity registered.");
}

// Sprite Component

sf::Sprite& CafeMoi::ComponentManager::addSpriteComponent(int entity, sf::Sprite&& sprite)
{
    spriteComponents[entity] = std::make_unique<sf::Sprite>(std::move(sprite));
    Logger::log("ComponentManager", "Added sprite component to entity: " + std::to_string(entity));
    return *spriteComponents[entity];
}

std::vector<std::unique_ptr<sf::Sprite>>& CafeMoi::ComponentManager::getSpriteComponents()
{
    return spriteComponents;
}

// Animated sprite component

CafeMoi::AnimatedSprite& CafeMoi::ComponentManager::addAnimatedSpriteComponent(int entity, AnimatedSprite&& animatedSprite)
{
    animatedSpriteComponents[entity] = std::make_unique<AnimatedSprite>(std::move(animatedSprite));
    Logger::log("ComponentManager", "Added animated sprite component to entity: " + std::to_string(entity));
    return *animatedSpriteComponents[entity];
}

std::vector<std::unique_ptr<CafeMoi::AnimatedSprite>>& CafeMoi::ComponentManager::getAnimatedSpriteComponents()
{
    return animatedSpriteComponents;
}


// Position component

sf::Vector2f& CafeMoi::ComponentManager::addPositionComponent(int entity, sf::Vector2f&& position)
{
    positionComponents[entity] = std::make_unique<sf::Vector2f>(position);
    Logger::log("ComponentManager", "Added position component to entity: " + std::to_string(entity));
    return *positionComponents[entity];
}

std::vector<std::unique_ptr<sf::Vector2f> > &CafeMoi::ComponentManager::getPositionComponents()
{
    return positionComponents;
}

// Speed component

sf::Vector2f& CafeMoi::ComponentManager::addSpeedComponent(int entity, sf::Vector2f&& speed)
{
    speedComponents[entity] = std::make_unique<sf::Vector2f>(speed);
    Logger::log("ComponentManager", "Added speed component to entity: " + std::to_string(entity));
    return *speedComponents[entity];
}

std::vector<std::unique_ptr<sf::Vector2f> > &CafeMoi::ComponentManager::getSpeedComponents()
{
    return speedComponents;
}
