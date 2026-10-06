#include "World.h"

#include "Building.h"
#include "Logger.h"

CafeMoi::World::World(AssetsManager& assets, Building& building)
{
    Logger::log("World", "Created instance");

    const int player = createEntity();
    entityManager.setTag(player, "Player");
    addSpriteComponent(player, sf::Sprite(assets.getTexture("sprite-sheet"), sf::IntRect({ 0 * 32, 4 * 32 }, { 32, 35 })));
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
