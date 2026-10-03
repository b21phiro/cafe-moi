#include "EntityManager.h"

#include "Logger.h"

CafeMoi::EntityManager::EntityManager()
: nextEntityID(0)
{}

int CafeMoi::EntityManager::createEntity()
{
    int entity = nextEntityID++;
    activeEntities.emplace_back(entity);
    Logger::log("EntityManager", "Created entity id: " + std::to_string(entity));
    return entity;
}

std::vector<int>& CafeMoi::EntityManager::getActiveEntities()
{
    return activeEntities;
}
