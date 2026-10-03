#ifndef CAFEMOI_COMPONENTS_MANAGER_H
#define CAFEMOI_COMPONENTS_MANAGER_H

#include <memory>
#include <vector>

#include "SFML/Graphics/Sprite.hpp"

namespace CafeMoi
{
    class ComponentManager
    {
    public:

        ComponentManager();

        void registerEntity();

        sf::Sprite& addSpriteComponent(int entity, sf::Sprite&& sprite);
        sf::Vector2f& addPositionComponent(int entity, sf::Vector2f&& position);

        std::vector<std::unique_ptr<sf::Sprite>>& getSpriteComponents();
        std::vector<std::unique_ptr<sf::Vector2f>>& getPositionComponents();

    private:

        std::vector<std::unique_ptr<sf::Sprite>> spriteComponents;

        std::vector<std::unique_ptr<sf::Vector2f>> positionComponents;

    };
}

#endif