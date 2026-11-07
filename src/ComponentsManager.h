#ifndef CAFEMOI_COMPONENTS_MANAGER_H
#define CAFEMOI_COMPONENTS_MANAGER_H

#include <map>
#include <memory>
#include <vector>
#include "components/Tag.h"

class ComponentsManager
{

    std::vector<std::unique_ptr<Tag>> m_tags;
    std::map<int, size_t> m_entityToTagsMap;

public:

    ComponentsManager();

    Tag& addTag(int entity, const std::string& value);

    Tag& getTag(int entity);

    void removeEntity(int entity);

    void update();

    bool hasTag(int entity);

};

#endif
