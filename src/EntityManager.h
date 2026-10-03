#ifndef CAFEMOI_ENTITY_MANAGER_H
#define CAFEMOI_ENTITY_MANAGER_H
#include <vector>

namespace CafeMoi
{
    class EntityManager
    {
    public:

        EntityManager();

        int createEntity();

        std::vector<int>& getActiveEntities();

    private:

        int nextEntityID;

        std::vector<int> activeEntities;

    };
}

#endif
