#ifndef CAFEMOI_WORLD_H
#define CAFEMOI_WORLD_H

#include "AssetsManager.h"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "SFML/Graphics/RenderWindow.hpp"

class World
{

    EntityManager m_entities;
    ComponentManager m_components;

    AssetsManager& m_assets;

    template <typename T, typename ...Args>
    T& add(int entity, Args&& ...args);

    template <typename T>
    T& get(int entity);

public:

    explicit World(AssetsManager& assets);

    void update();
    void draw(sf::RenderWindow& window);

};

template<typename T, typename ...Args>
T& World::add(const int entity, Args&& ...args)
{
    if (!m_entities.hasEntity(entity))
    {
        throw std::runtime_error("Error, the entity must exists if you want to add components to it.");
    }
    return m_components.add<T>(entity, std::forward<Args>(args)...);
}

template<typename T>
T& World::get(const int entity)
{
    if (!m_entities.hasEntity(entity))
    {
        throw std::runtime_error("Error, the entity must exists if you want to add components to it.");
    }

    return m_components.get<T>(entity);

}

#endif
