#include "EntityManager.h"

EntityManager::EntityManager()
    : m_nextEntityID(0)
{
}

int EntityManager::createEntity()
{
    const int entity = m_nextEntityID;
    m_entities.push_back(entity);
    m_nextEntityID++;
    return entity;
}

std::vector<Entity>& EntityManager::getAll()
{
    return m_entities;
}

bool EntityManager::hasEntity(const Entity entity)
{
    return std::find(m_entities.begin(), m_entities.end(), entity) != m_entities.end();
}
