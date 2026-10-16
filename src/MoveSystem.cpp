#include "MoveSystem.h"

#include <iostream>

#include "Logger.h"
#include "components/AnimatedSpriteComponent.h"
#include "components/PositionComponent.h"
#include "components/SpeedComponent.h"

CafeMoi::MoveSystem::MoveSystem()
{
    Logger::log("MoveSystem", "Created instance");
}

void CafeMoi::MoveSystem::process(
    sf::Time& timeElapsed,
    InputManager& inputManager,
    EntityManager& entityManager,
    ComponentManager& componentManager)
{

    bool isPlayerMovingRight = false;
    bool isPlayerMovingLeft = false;
    bool isPlayerMovingDown = false;
    bool isPlayerMovingUp = false;

    if (inputManager.isKeyDown(sf::Keyboard::Key::D) || inputManager.isKeyDown(sf::Keyboard::Key::Right))
    {
        isPlayerMovingRight = true;
    }
    if (inputManager.isKeyDown(sf::Keyboard::Key::A) || inputManager.isKeyDown(sf::Keyboard::Key::Left))
    {
        isPlayerMovingLeft = true;
    }
    if (inputManager.isKeyDown(sf::Keyboard::Key::W) || inputManager.isKeyDown(sf::Keyboard::Key::Up))
    {
       isPlayerMovingUp = true;
    }
    if (inputManager.isKeyDown(sf::Keyboard::Key::S) || inputManager.isKeyDown(sf::Keyboard::Key::Down))
    {
        isPlayerMovingDown = true;
    }

    for (const int player : entityManager.getEntitiesWithTag("Player"))
    {

        if (!componentManager.has<SpeedComponent>(player) ||
            !componentManager.has<PositionComponent>(player) ||
            !componentManager.has<AnimatedSpriteComponent>(player)) continue;

        auto& speed = componentManager.get<SpeedComponent>(player);
        auto& position = componentManager.get<PositionComponent>(player);
        auto& animatedSprite = componentManager.get<AnimatedSpriteComponent>(player);

        if (!isPlayerMovingRight && speed.value.x > 0)
        {
            animatedSprite.setAnimation("idle-right");
        }
        if (!isPlayerMovingLeft && speed.value.x < 0)
        {
            animatedSprite.setAnimation("idle-left");
        }

        speed.value.x = 0;
        speed.value.y = 0;

        if (isPlayerMovingRight)
        {
            speed.value.x = 1;
            animatedSprite.setAnimation("move-right");
        }
        if (isPlayerMovingLeft)
        {
            speed.value.x = -1;
            animatedSprite.setAnimation("move-left");
        }
        if (isPlayerMovingDown)
        {
            speed.value.y = 1;
        }
        if (isPlayerMovingUp)
        {
            speed.value.y = -1;
        }

        position.value.x += speed.value.x * timeElapsed.asSeconds() * 100.f;
        position.value.y += speed.value.y * timeElapsed.asSeconds() * 100.f;

    }

}
