#include "MoveSystem.h"

MoveSystem::MoveSystem(InputManager& input)
    : m_input(input)
{}

void MoveSystem::process(const std::vector<Entity>& entities, ComponentManager& components, const sf::Time& delta) const
{
    for (const Entity entity : entities)
    {
        if (!components.has<SpeedComponent>(entity)) continue;
        auto& speed = components.get<SpeedComponent>(entity);
        speed.current = sf::Vector2f(0.f, 0.f);

        if (components.has<TagComponent>(entity) && components.get<TagComponent>(entity).value == "Player")
        {
            handlePlayerMovement(speed);
        }

        if (!components.has<SpriteComponent>(entity)) continue;
        const auto& sprite = components.get<SpriteComponent>(entity);
        sprite.sprite->move(speed.current * delta.asSeconds() * 100.f);

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
