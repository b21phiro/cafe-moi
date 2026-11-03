#ifndef CAFEMOI_ENTITYMANAGER_H
#define CAFEMOI_ENTITYMANAGER_H

#include <vector>

using Entity = int;

class EntityManager
{

    int m_maxAmountOfEntities;

    Entity m_nextID;

    int m_entityPos;
    std::vector<Entity> m_entities;

    void reset();

public:

    EntityManager(int maxAmountOfEntities = 1000);

    std::vector<Entity>& getAll();

    Entity createEntity();

    void addEntity(Entity entity);
    void addEntities(std::vector<Entity> entities);

    void removeEntity(Entity entity);

    Entity getEntity(Entity entity);

};

#endif