#ifndef CAFEMOI_PLAY_H
#define CAFEMOI_PLAY_H

#include <map>
#include <stdexcept>
#include <vector>
#include "components/TagComponent.h"

namespace sf { class RenderWindow; }

class Cafemoi;

class Play
{

    Cafemoi& m_cafemoi;

    std::vector<int> m_entities;
    int m_nextEntityID;

    std::map<int, TagComponent> m_tags;

public:

    Play(Cafemoi& cafemoi);

    void update();

    void draw();

    int createEntity();

    template <typename T, typename ...Args>
    T& add(int entity, Args&& ...args);

    template <typename T>
    T& get(int entity);

};

template<typename T, typename ...Args>
T& Play::add(const int entity, Args&& ...args)
{

    if (std::find(m_entities.begin(), m_entities.end(), entity) == m_entities.end())
    {
        throw std::runtime_error("Error, the entity must exists if you want to add components to it.");
    }

    if (std::is_same_v<TagComponent, T>)
    {
        m_tags[entity] = T(std::forward<Args>(args)...);
        return m_tags[entity];
    } else
    {
        throw std::runtime_error("Error, attempted to add unknown component to entity");
    }

}

template<typename T>
T& Play::get(const int entity)
{
    if (std::find(m_entities.begin(), m_entities.end(), entity) == m_entities.end())
    {
        throw std::runtime_error("Error, the entity must exists if you want to add components to it.");
    }

    if (std::is_same_v<TagComponent, T>)
    {
        return m_tags[entity];
    } else
    {
        throw std::runtime_error("Error, attempted to add unknown component to entity");
    }
}

#endif
