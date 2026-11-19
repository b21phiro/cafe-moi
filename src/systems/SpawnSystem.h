#ifndef CAFEMOI_SPAWN_SYSTEM_H
#define CAFEMOI_SPAWN_SYSTEM_H

class Building;
class EntityManager;
class ComponentManager;

class SpawnSystem
{

    bool m_isFirstTick;

public:

    SpawnSystem();

    void process(Building& building, EntityManager& entities, ComponentManager& components);

};

#endif

