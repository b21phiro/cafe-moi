#ifndef CAFEMOI_WORLD_H
#define CAFEMOI_WORLD_H

#include "AssetsManager.h"
#include "Building.h"
#include "ComponentManager.h"
#include "EntityManager.h"

namespace CafeMoi
{
    class World
    {
    public:

        World(AssetsManager& assets, Building& building);

        int createEntity();

        sf::Sprite& addSpriteComponent(int entity, sf::Sprite&& sprite);

        sf::Vector2f& addPositionComponent(int entity, sf::Vector2f&& position);

        EntityManager& getEntityManager();

        ComponentManager& getComponentManager();

    private:

        EntityManager entityManager;

        ComponentManager componentManager;

    };
}

#endif
