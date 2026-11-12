#ifndef CAFEMOI_COMPONENT_MANAGER_H
#define CAFEMOI_COMPONENT_MANAGER_H

#include <map>
#include <stdexcept>
#include "components/SpriteComponent.h"
#include "components/TagComponent.h"

class ComponentManager
{

    std::map<int, TagComponent> m_tags;
    std::map<int, SpriteComponent> m_sprites;

public:

    ComponentManager();

    template <typename T, typename ...Args>
    T& add(int entity, Args&& ...args);

    template <typename T>
    T& get(int entity);

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
    }
    else
    {
        throw std::runtime_error("Error, attempted to add unknown component to entity");
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
    } else
    {
        throw std::runtime_error("Error, attempted to add unknown component to entity");
    }
}

#endif