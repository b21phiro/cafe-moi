#include "ComponentManager.h"
#include "Logger.h"

CafeMoi::ComponentManager::ComponentManager()
{
    Logger::log("ComponentManager", "Instance created");
}

void CafeMoi::ComponentManager::registerEntity()
{
    Logger::log("ComponentManager", "Entity registered.");
}