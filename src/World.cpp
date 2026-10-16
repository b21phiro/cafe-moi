#include "World.h"
#include "Building.h"
#include "Logger.h"
#include <map>
#include <vector>
#include "components/AnimatedSpriteComponent.h"
#include "components/PositionComponent.h"
#include "components/SpeedComponent.h"

CafeMoi::World::World(AssetsManager& assets, Building& building)
{
    Logger::log("World", "Created instance");

    const int player = createEntity();
    entityManager.setTag(player, "Player");

    componentManager.set<AnimatedSpriteComponent>(
        player,
        sf::Sprite(assets.getTexture("sprite-sheet"), sf::IntRect({ 0, 128 }, { 32, 35 })),
        std::map<std::string, std::vector<sf::IntRect>>({
             {
                "idle-right",
                {
                    {{ 0, 128 }, { 32, 35 }},
                    {{ 32, 128 }, { 32, 35 }},
                },
            },
            {
                "move-right",
                {
                    {{ 0, 128   }, { 32, 35 }},
                    {{ 160, 128 }, { 32, 35 }},
                    {{ 0, 128 }, { 32, 35 }},
                    {{ 192, 128 }, { 32, 35 }},
                },
            },
            {
                "idle-left",
                {
                    {{ 64, 128 }, { 32, 35 }},
                    {{ 96, 128 }, { 32, 35 }},
                },
            },
            {
                "move-left",
                {
                    {{ 64, 128   }, { 32, 35 }},
                    {{ 320, 128 }, { 32, 35 }},
                    {{ 64, 128 }, { 32, 35 }},
                    {{ 288, 128 }, { 32, 35 }},
                },
            },
        }),
        std::map<std::string, std::vector<int>>({
            {
                "idle-right",
                {
                    { 3500, 200 }
                },
            },
            {
                "move-right",
                {
                    { 200, 200, 200, 200 }
                },
            },
            {
                "idle-left",
                {
                    { 3500, 200 }
                },
            },
            {
                "move-left",
                {
                    { 200, 200, 200, 200 }
                },
            },
        }));
    componentManager.set<SpeedComponent>(player, sf::Vector2f());
    componentManager.set<PositionComponent>(player, sf::Vector2f((float)building.getCenter().x * 32.f, (float)building.getCenter().y * 32.f));


}

int CafeMoi::World::createEntity()
{
    const int entity = entityManager.createEntity();
    componentManager.registerEntity();
    Logger::log("World", "Created entity " + std::to_string(entity));
    return entity;
}

CafeMoi::EntityManager& CafeMoi::World::getEntityManager()
{
    return entityManager;
}

CafeMoi::ComponentManager& CafeMoi::World::getComponentManager()
{
    return componentManager;
}
