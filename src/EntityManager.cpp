#include "EntityManager.h"

#include <algorithm>
#include <iostream>
#include <utility>

#include "Logger.h"

CafeMoi::EntityManager::EntityManager()
: nextEntityID(0)
{}

int CafeMoi::EntityManager::createEntity()
{
    int entity = nextEntityID++;
    activeEntities.emplace_back(entity);
    Logger::log("EntityManager", "Created entity id: " + std::to_string(entity));
    setTag(entity, "Unknown");
    return entity;
}

std::vector<int>& CafeMoi::EntityManager::getActiveEntities()
{
    return activeEntities;
}

void CafeMoi::EntityManager::setTag(const int entity, std::string tag)
{
    entityToTagMap[entity] = std::move(tag);
    Logger::log("EntityManager : setTag", "Entity \"" + std::to_string(entity) + "\" now has the tag \"" + entityToTagMap[entity] + "\"" );
}

std::vector<int> CafeMoi::EntityManager::getEntitiesWithTag(const std::string& tag)
{
    std::vector<int> result;
    for (int entity : activeEntities)
    {
        if (entityToTagMap.find(entity) != entityToTagMap.end())
        {
            if (entityToTagMap[entity] == tag)
            {
                result.push_back(entity);
            }
        }
    }
    return result;
}
