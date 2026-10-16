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

        EntityManager& getEntityManager();
        ComponentManager& getComponentManager();

    private:

        EntityManager entityManager;
        ComponentManager componentManager;

    };
}

#endif
