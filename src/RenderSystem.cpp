#include "RenderSystem.h"
#include "Logger.h"

CafeMoi::RenderSystem::RenderSystem()
{
    Logger::log("RenderSystem", "Instance created");
}

void CafeMoi::RenderSystem::process(
    sf::RenderWindow& window,
    EntityManager& entities,
    std::vector<std::unique_ptr<sf::Sprite>>& spriteComponents,
    std::vector<std::unique_ptr<sf::Vector2f>>& positionComponents)
{
    for (auto& entity : entities.getActiveEntities())
    {
        auto& sprite = spriteComponents[entity];
        if (sprite == nullptr) continue;

        if (auto& position = positionComponents[entity]; position != nullptr)
        {
            sprite->setPosition(*position);
        }

        window.draw(*sprite);

    }
}
