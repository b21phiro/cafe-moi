#ifndef CAFEMOI_RENDER_SYSTEM_H
#define CAFEMOI_RENDER_SYSTEM_H

namespace sf { class RenderWindow; }
class ComponentManager;
class EntityManager;
struct Floor;
class Building;

class RenderSystem
{

public:

    RenderSystem();

    void updateAnimations(EntityManager& entities, ComponentManager& components, const sf::Time& delta);

    void process(
        sf::RenderWindow& window,
        EntityManager& entities,
        ComponentManager& components,
        Building& building
    );

};

#endif