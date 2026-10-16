#ifndef CAFEMOI_COMPONENTS_MANAGER_H
#define CAFEMOI_COMPONENTS_MANAGER_H

#include <map>
#include <memory>
#include <string>
#include <typeindex>
#include <utility>
#include <vector>
#include "components/Component.h"

namespace CafeMoi
{

    class ComponentManager
    {
    public:

        ComponentManager();

        void registerEntity();

        template <typename T, typename ...Args>
        T& set(Args&& ...args)
        {

            auto component = std::make_unique<T>(std::forward<Args>(args)...);
            T* ptr = component.get();
            components.emplace_back(std::move(component));

            const int entity = ptr->entity;
            const std::string type = std::type_index(typeid(T)).name();
            const size_t index = components.size() - 1;

            componentToEntityMap[index] = entity;
            entityToComponentsMap[entity][type] = index;

            return *ptr;
        }

        template <typename T>
        T& get(const int entity)
        {
            const std::string type = std::type_index(typeid(T)).name();
            const size_t componentIndex = entityToComponentsMap.at(entity).at(type);
            return static_cast<T&>(*components.at(componentIndex));
        }

        template <typename T>
        bool has(const int entity) const
        {
            const std::string type = std::type_index(typeid(T)).name();
            auto it = entityToComponentsMap.find(entity);
            if (it == entityToComponentsMap.end()) return false;
            else if (it->second.find(type) == it->second.end()) return false;
            else return true;
        }

    private:

        std::vector<std::unique_ptr<Component>> components;
        std::map<size_t, int> componentToEntityMap;
        std::map<int, std::map<std::string, size_t>> entityToComponentsMap;

    };
}

#endif