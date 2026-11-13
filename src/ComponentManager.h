#ifndef CAFEMOI_COMPONENT_MANAGER_H
#define CAFEMOI_COMPONENT_MANAGER_H

#include <map>
#include <stdexcept>
#include <vector>

#include "components/SpeedComponent.h"
#include "components/SpriteComponent.h"
#include "components/TagComponent.h"

class ComponentManager
{

    std::map<int, TagComponent> m_tags;
    std::map<int, SpriteComponent> m_sprites;
    std::map<int, SpeedComponent> m_speeds;

public:

    ComponentManager();

    template <typename T, typename ...Args>
    T& add(int entity, Args&& ...args);

    template <typename T>
    bool has(int entity);

    template <typename T>
    T& get(int entity);

    template <typename T>
    std::map<int, T>& getAll();

};

template<typename T, typename ...Args>
T& ComponentManager::add(const int entity, Args&& ...args)
{
    if constexpr (std::is_same_v<T, TagComponent>)
    {
        m_tags[entity] = T(std::forward<Args>(args)...);
        return m_tags[entity];
    } else if constexpr (std::is_same_v<T, SpriteComponent>)
    {
        m_sprites[entity] = T(std::forward<Args>(args)...);
        return m_sprites[entity];
    } else if constexpr (std::is_same_v<T, SpeedComponent>)
    {
        m_speeds[entity] = T(std::forward<Args>(args)...);
        return m_speeds[entity];
    }
    else
    {
        throw std::runtime_error("Error, attempted to add unknown component to entity");
    }
}

template<typename T>
bool ComponentManager::has(const int entity)
{
    if constexpr (std::is_same_v<TagComponent, T>)
    {
        return m_tags.find(entity) != m_tags.end();
    }
    else if constexpr (std::is_same_v<SpriteComponent, T>)
    {
        return m_sprites.find(entity) != m_sprites.end();
    } else if constexpr (std::is_same_v<SpeedComponent, T>)
    {
        return m_speeds.find(entity) != m_speeds.end();
    } else
    {
        return false;
    }
}

template<typename T>
T& ComponentManager::get(const int entity)
{
    if constexpr (std::is_same_v<TagComponent, T>)
    {
        return m_tags[entity];
    }
    else if constexpr (std::is_same_v<SpriteComponent, T>)
    {
        return m_sprites[entity];
    } else if constexpr (std::is_same_v<SpeedComponent, T>)
    {
        return m_speeds[entity];
    } else
    {
        throw std::runtime_error("Error, attempted to add unknown component to entity");
    }
}

template<typename T>
std::map<int, T>& ComponentManager::getAll()
{
    if constexpr (std::is_same_v<TagComponent, T>)
    {
        return m_tags;
    }
    else if constexpr (std::is_same_v<SpriteComponent, T>)
    {
        return m_sprites;
    } else if constexpr (std::is_same_v<SpeedComponent, T>)
    {
        return m_speeds;
    } else
    {
        throw std::runtime_error("Error, attempted to retrieve unknown components");
    }
}

#endif
