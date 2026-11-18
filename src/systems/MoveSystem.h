#ifndef CAFEMOI_MOVE_SYSTEM_H
#define CAFEMOI_MOVE_SYSTEM_H

#include <SFML/System/Time.hpp>

struct AnimatedSpriteComponent;
struct SpeedComponent;
class InputManager;
class ComponentManager;
class EntityManager;

class MoveSystem
{

    void handlePlayerMovement(InputManager& input, SpeedComponent& playerSpeed, AnimatedSpriteComponent& playerSprite);

    void normalizeSpeed(SpeedComponent& speed);

public:

    MoveSystem();

    void input(InputManager& input, EntityManager& entities, ComponentManager& components);

    void process(EntityManager& entities, ComponentManager& components, const sf::Time& delta = sf::Time::Zero);

};

#endif