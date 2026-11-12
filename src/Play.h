#ifndef CAFEMOI_PLAY_H
#define CAFEMOI_PLAY_H

#include <map>
#include <stdexcept>
#include <vector>

#include "EntityManager.h"
#include "components/SpriteComponent.h"
#include "components/TagComponent.h"

namespace sf { class RenderWindow; }

class Cafemoi;

class Play
{
    Cafemoi& m_cafemoi;

    std::map<int, TagComponent> m_tags;
    std::map<int, SpriteComponent> m_sprites;

    EntityManager m_entities;

public:

    Play(Cafemoi& cafemoi);

    void update();

    void draw();

    template <typename T, typename ...Args>
    T& add(int entity, Args&& ...args);

    template <typename T>
    T& get(int entity);

};

template<typename T, typename ...Args>
T& Play::add(const int entity, Args&& ...args)
{

    if (!m_entities.hasEntity(entity))
    {
        throw std::runtime_error("Error, the entity must exists if you want to add components to it.");
    }

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
T& Play::get(const int entity)
{
    if (!m_entities.hasEntity(entity))
    {
        throw std::runtime_error("Error, the entity must exists if you want to add components to it.");
    }

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
