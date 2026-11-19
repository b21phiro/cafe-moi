#include "SpawnSystem.h"

#include <iostream>

#include "../ComponentManager.h"
#include "../EntityManager.h"
#include "../building/Building.h"

SpawnSystem::SpawnSystem()
    : m_isFirstTick(true)
{}

void SpawnSystem::process(Building& building, EntityManager& entities, ComponentManager& components)
{
    if (!m_isFirstTick) return;
    for (const auto& entity : entities.getAll())
    {
        if (!components.has<TagComponent>(entity) ||
            components.get<TagComponent>(entity).value != "Player" ||
            !components.has<AnimatedSpriteComponent>(entity)
        ) continue;

        const auto& sprite = components.get<AnimatedSpriteComponent>(entity);
        sprite.sprite->setPosition(building.getSpawn());
        std::cout << "Spawned player" << std::endl;
    }
    m_isFirstTick = false;
}
