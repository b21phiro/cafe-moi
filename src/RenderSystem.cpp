#include "RenderSystem.h"
#include "Logger.h"
#include "components/AnimatedSpriteComponent.h"
#include "components/PositionComponent.h"
#include "components/SpriteComponent.h"

CafeMoi::RenderSystem::RenderSystem()
{
    Logger::log("RenderSystem", "Instance created");
}

void CafeMoi::RenderSystem::process(
    sf::RenderWindow& window,
    const sf::Time& timeElapsed,
    EntityManager& entities,
    ComponentManager& componentManager
)
{

    for (const auto& entity : entities.getActiveEntities())
    {

        const bool hasPosition = componentManager.has<PositionComponent>(entity);

        if (componentManager.has<SpriteComponent>(entity))
        {
            auto& sprite = componentManager.get<SpriteComponent>(entity);
            if (hasPosition)
            {
                const auto& position = componentManager.get<PositionComponent>(entity);
                sprite.sprite.setPosition(position.value);
            }
            window.draw(sprite.sprite);
        } else if (componentManager.has<AnimatedSpriteComponent>(entity))
        {
            auto& animatedSprite = componentManager.get<AnimatedSpriteComponent>(entity);
            if (hasPosition)
            {
                const auto& position = componentManager.get<PositionComponent>(entity);
                animatedSprite.sprite.setPosition(position.value);
            }
            window.draw(animatedSprite.sprite);
            animatedSprite.update(timeElapsed);
        }
    }
}
