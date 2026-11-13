#ifndef CAFEMOI_MOVE_SYSTEM_H
#define CAFEMOI_MOVE_SYSTEM_H

#include "../ComponentManager.h"
#include "../EntityManager.h"
#include "../InputManager.h"

class MoveSystem
{

    InputManager& m_input;

    void handlePlayerMovement(SpeedComponent& playerSpeed) const;

public:

    explicit MoveSystem(InputManager& input);

    void process(const std::vector<Entity>& entities, ComponentManager& components, const sf::Time& delta = sf::Time::Zero) const;

};

#endif