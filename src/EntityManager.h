#ifndef CAFEMOI_ENTITY_MANAGER_H
#define CAFEMOI_ENTITY_MANAGER_H

#include <vector>

using Entity = int;

class EntityManager
{

    Entity m_nextEntityID;
    std::vector<Entity> m_entities;

public:

    EntityManager();

    Entity createEntity();

    std::vector<Entity>& getAll();

    bool hasEntity(Entity entity);

};

#endif