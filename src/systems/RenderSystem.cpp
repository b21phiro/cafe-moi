#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "RenderSystem.h"
#include "../ComponentManager.h"
#include "../EntityManager.h"
#include "../components/SpriteComponent.h"
#include "../components/AnimatedSpriteComponent.h"
#include "../building/Floor.h"

RenderSystem::RenderSystem() = default;

void RenderSystem::process(
    sf::RenderWindow& window,
    EntityManager& entities,
    ComponentManager& components,
    std::vector<Floor>& floor
)
{

    std::vector<sf::Sprite> sprites{};

    for (const Entity entity : entities.getAll())
    {
        if (components.has<SpriteComponent>(entity))
        {
            sprites.push_back(*components.get<SpriteComponent>(entity).sprite);
        }
        if (components.has<AnimatedSpriteComponent>(entity))
        {
            sprites.push_back(*components.get<AnimatedSpriteComponent>(entity).sprite);
        }
    }

    for (Floor& tile : floor)
    {
        window.draw(tile.material.sprite, &tile.material.shader);
    }

    for (sf::Sprite& sprite : sprites)
    {
        window.draw(sprite);
    }

}

void RenderSystem::updateAnimations(EntityManager& entities, ComponentManager& components, const sf::Time& delta)
{
    for (const Entity entity : entities.getAll())
    {
        if (!components.has<AnimatedSpriteComponent>(entity)) continue;
        auto& sprite = components.get<AnimatedSpriteComponent>(entity);
        sprite.update(delta);
    }
}
