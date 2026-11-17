#ifndef CAFEMOI_WORLD_H
#define CAFEMOI_WORLD_H

#include "Camera.h"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "building/Floor.h"
#include "systems/MoveSystem.h"
#include "systems/RenderSystem.h"

class AssetsManager;

class World
{

    EntityManager m_entities;
    ComponentManager m_components;

    AssetsManager& m_assets;
    Camera m_camera;

    MoveSystem m_moveSystem;
    RenderSystem m_renderSystem;

    std::vector<Floor> m_floor;

    template <typename T, typename ...Args>
    T& add(int entity, Args&& ...args);

    template <typename T>
    T& get(int entity);

public:

    explicit World(InputManager& input, AssetsManager& assets);

    void update(const sf::Time& delta = sf::Time::Zero);
    void draw(sf::RenderWindow& window);

    void applyGameSettings(GameSettings& gameSettings);

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
