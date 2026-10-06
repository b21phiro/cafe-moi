#include "MoveSystem.h"

#include <iostream>

#include "Logger.h"

CafeMoi::MoveSystem::MoveSystem()
{
    Logger::log("MoveSystem", "Created instance");
}

void CafeMoi::MoveSystem::process(
    sf::Time& timeElapsed,
    InputManager& inputManager,
    EntityManager& entityManager,
    std::vector<std::unique_ptr<sf::Vector2f>>& speedComponents,
    std::vector<std::unique_ptr<sf::Vector2f>>& positionComponents
)
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
        auto& playerSpeed = speedComponents[player];
        auto& playerPosition = positionComponents[player];
        if (playerSpeed == nullptr || playerPosition == nullptr) continue;

        playerSpeed->x = 0;
        playerSpeed->y = 0;

        if (isPlayerMovingRight)
        {
            playerSpeed->x = 1;
        }
        if (isPlayerMovingLeft)
        {
            playerSpeed->x = -1;
        }
        if (isPlayerMovingDown)
        {
            playerSpeed->y = 1;
        }
        if (isPlayerMovingUp)
        {
            playerSpeed->y = -1;
        }

        playerPosition->x += playerSpeed->x * timeElapsed.asSeconds() * 100.f;
        playerPosition->y += playerSpeed->y * timeElapsed.asSeconds() * 100.f;

    }

}
