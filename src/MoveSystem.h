#ifndef CAFEMOI_MOVE_SYSTEM_H
#define CAFEMOI_MOVE_SYSTEM_H

#include <SFML/System/Time.hpp>
#include "ComponentManager.h"
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
            ComponentManager& componentManager
        );

    };
}

#endif