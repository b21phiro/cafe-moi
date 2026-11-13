#include "MoveSystem.h"
#include "../ComponentManager.h"
#include "../EntityManager.h"
#include "../InputManager.h"
#include "../components/SpeedComponent.h"
#include "../components/TagComponent.h"
#include "../components/SpriteComponent.h"
#include "../components/AnimatedSpriteComponent.h"

MoveSystem::MoveSystem(InputManager& input)
    : m_input(input)
{}

void MoveSystem::process(EntityManager& entities, ComponentManager& components, const sf::Time& delta) const
{
    for (const Entity entity : entities.getAll())
    {
        if (!components.has<SpeedComponent>(entity)) continue;
        auto& speed = components.get<SpeedComponent>(entity);
        speed.current = sf::Vector2f(0.f, 0.f);

        if (components.has<TagComponent>(entity) && components.get<TagComponent>(entity).value == "Player")
        {
            handlePlayerMovement(speed);
        }

        speed.current *= delta.asSeconds() * 100.f;

        if (components.has<SpriteComponent>(entity))
        {
            components.get<SpriteComponent>(entity).sprite->move(speed.current);
        }
        if (components.has<AnimatedSpriteComponent>(entity))
        {
            components.get<AnimatedSpriteComponent>(entity).sprite->move(speed.current);
        }
    }
}

void MoveSystem::handlePlayerMovement(SpeedComponent& playerSpeed) const
{
    if (m_input.isKeyDown(sf::Keyboard::Key::D) || m_input.isKeyDown(sf::Keyboard::Key::Right))
    {
        playerSpeed.current.x = 1.f;
    }
    if (m_input.isKeyDown(sf::Keyboard::Key::A) || m_input.isKeyDown(sf::Keyboard::Key::Left))
    {
        playerSpeed.current.x = -1.f;
    }
    if (m_input.isKeyDown(sf::Keyboard::Key::W) || m_input.isKeyDown(sf::Keyboard::Key::Up))
    {
        playerSpeed.current.y = -1.f;
    }
    if (m_input.isKeyDown(sf::Keyboard::Key::S) || m_input.isKeyDown(sf::Keyboard::Key::Down))
    {
        playerSpeed.current.y = 1.f;
    }
}
