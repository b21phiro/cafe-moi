#ifndef CAFEMOI_ENTITY_MANAGER_H
#define CAFEMOI_ENTITY_MANAGER_H
#include <map>
#include <string>
#include <vector>

namespace CafeMoi
{
    class EntityManager
    {
    public:

        EntityManager();

        int createEntity();

        std::vector<int>& getActiveEntities();

        void setTag(int entity, std::string tag);

        std::vector<int> getEntitiesWithTag(const std::string& tag);

    private:

        int nextEntityID;

        std::vector<int> activeEntities;
        std::map<int, std::string> entityToTagMap;

    };
}

#endif
