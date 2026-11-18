#include "MoveSystem.h"

#include <iostream>

#include "../ComponentManager.h"
#include "../EntityManager.h"
#include "../InputManager.h"
#include "../components/SpeedComponent.h"
#include "../components/TagComponent.h"
#include "../components/SpriteComponent.h"
#include "../components/AnimatedSpriteComponent.h"

MoveSystem::MoveSystem() = default;

void MoveSystem::input(InputManager &input, EntityManager &entities, ComponentManager &components)
{
    for (const Entity entity : entities.getAll())
    {
        if (
            !components.has<TagComponent>(entity) ||
            components.get<TagComponent>(entity).value != "Player" ||
            !components.has<AnimatedSpriteComponent>(entity) ||
            !components.has<SpeedComponent>(entity)
        ) continue;
        auto& speed = components.get<SpeedComponent>(entity);
        auto& sprite = components.get<AnimatedSpriteComponent>(entity);
        handlePlayerMovement(input, speed, sprite);
    }
}

void MoveSystem::process(EntityManager& entities, ComponentManager& components, const sf::Time& delta)
{
    for (const Entity entity : entities.getAll())
    {
        if (
            !components.has<TagComponent>(entity) ||
            components.get<TagComponent>(entity).value != "Player" ||
            !components.has<AnimatedSpriteComponent>(entity) ||
            !components.has<SpeedComponent>(entity)
        ) continue;

        auto& speed = components.get<SpeedComponent>(entity);
        normalizeSpeed(speed);
        speed.setCurrent(speed.current * delta.asSeconds() * 100.f);

        if (components.has<SpriteComponent>(entity))
        {
            components.get<SpriteComponent>(entity).sprite->move(speed.current);
        }
        if (components.has<AnimatedSpriteComponent>(entity))
        {
            components.get<AnimatedSpriteComponent>(entity).sprite->move(speed.current);
        }

        speed.setCurrent(sf::Vector2f(0.f, 0.f));

    }
}

void MoveSystem::handlePlayerMovement(InputManager& input, SpeedComponent& playerSpeed, AnimatedSpriteComponent& playerSprite)
{
    if (input.isKeyDown(sf::Keyboard::Key::D) || input.isKeyDown(sf::Keyboard::Key::Right))
    {
        playerSpeed.setCurrentX(1.f);
    }
    if (input.isKeyDown(sf::Keyboard::Key::A) || input.isKeyDown(sf::Keyboard::Key::Left))
    {
        playerSpeed.setCurrentX(-1.f);
    }
    if (input.isKeyDown(sf::Keyboard::Key::W) || input.isKeyDown(sf::Keyboard::Key::Up))
    {
        playerSpeed.setCurrentY(-1.f);
    }
    if (input.isKeyDown(sf::Keyboard::Key::S) || input.isKeyDown(sf::Keyboard::Key::Down))
    {
        playerSpeed.setCurrentY(1.f);
    }
    if (playerSpeed.current == sf::Vector2f(0.f, 0.f))
    {
        if (playerSpeed.previous.x > 0)
        {
            playerSprite.stop("player-move-right");
        }
        else if (playerSpeed.previous.x < 0)
        {
            playerSprite.stop("player-move-left");
        }
        else if (playerSpeed.previous.y > 0)
        {
            playerSprite.stop("player-move-down");
        }
        else if (playerSpeed.previous.y < 0)
        {
            playerSprite.stop("player-move-up");
        }
    } else
    {
        if (playerSpeed.current.x > 0)
        {
            playerSprite.play("player-move-right");
        } else if (playerSpeed.current.x < 0)
        {
            playerSprite.play("player-move-left");
        } else if (playerSpeed.current.y > 0) {
            playerSprite.play("player-move-down");
        } else if (playerSpeed.current.y < 0)
        {
            playerSprite.play("player-move-up");
        }
    }
}

void MoveSystem::normalizeSpeed(SpeedComponent& speed)
{
    if (speed.current.x == 0 || speed.current.y == 0) return;
    speed.current.x *= 1.f / std::sqrt(2.f);
    speed.current.y *= 1.f / std::sqrt(2.f);
}
