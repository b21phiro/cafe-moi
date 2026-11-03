#include "EntityManager.h"

EntityManager::EntityManager(const int maxAmountOfEntities)
    : m_maxAmountOfEntities(maxAmountOfEntities)
    , m_nextID(0)
    , m_entities(maxAmountOfEntities)
    , m_entityPos(0)
{
    reset();
}

std::vector<int> &EntityManager::getAll()
{
    return m_entities;
}

Entity EntityManager::createEntity()
{
    const Entity entity = m_nextID;
    m_nextID++;
    return entity;
}

void EntityManager::addEntity(const Entity entity)
{
    const auto it = std::find_if(m_entities.begin(), m_entities.end(), [](const int m_pos)
    {
        return (m_pos == -1);
    });
    if (it == m_entities.end())
    {
        reset();
        addEntity(entity);
        return;
    }
    *it = entity;
}

Entity EntityManager::getEntity(Entity entity)
{
    const auto it = std::find_if(m_entities.begin(), m_entities.end(), [entity](const Entity m_entity)
    {
        return (m_entity == entity);
    });
    if (it == m_entities.end())
    {
        return -1;
    } else
    {
        return *it;
    }
}

void EntityManager::removeEntity(Entity entity)
{
    const auto it = std::find_if(m_entities.begin(), m_entities.end(), [entity](const Entity m_entity)
    {
        return (m_entity == entity);
    });
    *it = -1;
}

void EntityManager::addEntities(std::vector<Entity> entities)
{
    for (int i = 0; i < std::size(entities); i++)
    {
        addEntity(entities[i]);
    }
}

void EntityManager::reset()
{
    for (int i = 0; i < m_maxAmountOfEntities; i++) { m_entities[i] = -1; };
}
