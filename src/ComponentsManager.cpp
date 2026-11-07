#include "ComponentsManager.h"

ComponentsManager::ComponentsManager() = default;

Tag& ComponentsManager::addTag(const int entity, const std::string& value)
{
    const size_t n = m_tags.size();
    m_tags.emplace_back(std::make_unique<Tag>(value));
    m_entityToTagsMap[entity] = n;
    return *m_tags[n];
}

bool ComponentsManager::hasTag(const int entity)
{
    return m_entityToTagsMap.find(entity) != m_entityToTagsMap.end();
}

Tag& ComponentsManager::getTag(const int entity)
{
    return *m_tags[m_entityToTagsMap[entity]];
}

void ComponentsManager::removeEntity(const int entity)
{
    if (!hasTag(entity)) return;
    getTag(entity).remove = true;
}

void ComponentsManager::update()
{
    int index = 0;
    for (auto it = m_tags.begin(); it != m_tags.end();)
    {
        if (it->get()->remove == true)
        {
            it = m_tags.erase(it);
            m_entityToTagsMap.erase(index);
        } else
        {
            ++it;
            ++index;
        }
    }
}
