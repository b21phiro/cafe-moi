#ifndef CAFEMOI_MOVE_SYSTEM_H
#define CAFEMOI_MOVE_SYSTEM_H

#include <memory>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include "EntityManager.h"
#include "InputManager.h"

namespace CafeMoi
{
    class MoveSystem
    {
    public:

        MoveSystem();

        void process(
            sf::Time& timeElapsed,
            InputManager& inputManager,
            EntityManager& entityManager,
            std::vector<std::unique_ptr<sf::Vector2f>>& speedComponents,
            std::vector<std::unique_ptr<sf::Vector2f>>& positionComponents
        );

    };
}

#endif