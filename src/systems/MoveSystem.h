#ifndef CAFEMOI_MOVE_SYSTEM_H
#define CAFEMOI_MOVE_SYSTEM_H

#include <SFML/System/Time.hpp>

struct SpeedComponent;
class InputManager;
class ComponentManager;
class EntityManager;

class MoveSystem
{

    InputManager& m_input;

    void handlePlayerMovement(SpeedComponent& playerSpeed) const;

public:

    explicit MoveSystem(InputManager& input);

    void process(EntityManager& entities, ComponentManager& components, const sf::Time& delta = sf::Time::Zero) const;

};

#endif