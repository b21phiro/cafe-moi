#ifndef CAFEMOI_RENDER_SYSTEM_H
#define CAFEMOI_RENDER_SYSTEM_H

namespace sf { class RenderWindow; }
class ComponentManager;
class EntityManager;

class RenderSystem
{

public:

    RenderSystem();

    void process(sf::RenderWindow& window, EntityManager& entities, ComponentManager& components);

};

#endif