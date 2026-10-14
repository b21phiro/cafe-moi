#include "World.h"
#include "Building.h"
#include "Logger.h"
#include <map>
#include <utility>
#include <vector>

CafeMoi::World::World(AssetsManager& assets, Building& building)
{
    Logger::log("World", "Created instance");

    const int player = createEntity();
    entityManager.setTag(player, "Player");
    auto& animation = addAnimatedSpriteComponent(player, { assets.getTexture("sprite-sheet"), {
        {
            "idle-right", {{{ 0, 128 }, { 32, 35 }}, {{ 32, 128 }, { 32, 35 }}}
        },
        {
            "walk-right", {{{ 0, 128 }, { 32, 35 }}, {{ 160, 128 }, { 32, 35 }}, {{ 0, 128 }, { 32, 35 }}, {{ 192, 128 }, { 32, 35 }}}
        }
    }, {
        {
            "idle-right", { 3500, 200 }
        },
        {
            "walk-right", { 200, 200, 200, 200 }
        }
    }});
    //animation.setAnimation("walk-right");
    addSpeedComponent(player, sf::Vector2f(0.f, 0.f));
    addPositionComponent(player, sf::Vector2f((float)building.getCenter().x * 32.f, (float)building.getCenter().y * 32.f));

}

int CafeMoi::World::createEntity()
{
    const int entity = entityManager.createEntity();
    componentManager.registerEntity();
    Logger::log("World", "Created entity " + std::to_string(entity));
    return entity;
}

sf::Sprite& CafeMoi::World::addSpriteComponent(const int entity, sf::Sprite&& sprite)
{
    Logger::log("World", "Added sprite component to entity " + std::to_string(entity));
    return componentManager.addSpriteComponent(entity, std::move(sprite));
}

CafeMoi::AnimatedSprite& CafeMoi::World::addAnimatedSpriteComponent(const int entity, AnimatedSprite&& animatedSprite)
{
    Logger::log("World", "Added animated sprite component to entity " + std::to_string(entity));
    return componentManager.addAnimatedSpriteComponent(entity, std::move(animatedSprite));
}

sf::Vector2f &CafeMoi::World::addPositionComponent(const int entity, sf::Vector2f&& position)
{
    Logger::log("World", "Added position component to entity " + std::to_string(entity));
    return componentManager.addPositionComponent(entity, std::move(position));
}

sf::Vector2f &CafeMoi::World::addSpeedComponent(const int entity, sf::Vector2f&& speed)
{
    Logger::log("World", "Added speed component to entity " + std::to_string(entity));
    return componentManager.addSpeedComponent(entity, std::move(speed));
}

CafeMoi::EntityManager& CafeMoi::World::getEntityManager()
{
    return entityManager;
}

CafeMoi::ComponentManager& CafeMoi::World::getComponentManager()
{
    return componentManager;
}
