#include "RenderSystem.h"
#include "Logger.h"

CafeMoi::RenderSystem::RenderSystem()
{
    Logger::log("RenderSystem", "Instance created");
}

void CafeMoi::RenderSystem::process(
    sf::RenderWindow& window,
    const sf::Time& timeElapsed,
    EntityManager& entities,
    ComponentManager& components
)
{
    const auto& spriteComponents = components.getSpriteComponents();
    const auto& animatedSpriteComponents = components.getAnimatedSpriteComponents();
    const auto& positionComponents = components.getPositionComponents();

    for (const auto& entity : entities.getActiveEntities())
    {
        auto& sprite = spriteComponents[entity];
        auto& animatedSprite = animatedSpriteComponents[entity];
        if (sprite == nullptr && animatedSprite == nullptr) continue;

        if (auto& position = positionComponents[entity]; position != nullptr)
        {
            if (sprite) sprite->setPosition(*position);
            else if (animatedSprite) animatedSprite->setPosition(*position);
        }

        if (sprite) window.draw(*sprite);
        else if (animatedSprite)
        {
            animatedSprite->update(timeElapsed);
            window.draw(*animatedSprite);
        }

    }
}
