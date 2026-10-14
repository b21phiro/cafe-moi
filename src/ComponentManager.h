#ifndef CAFEMOI_COMPONENTS_MANAGER_H
#define CAFEMOI_COMPONENTS_MANAGER_H

#include <memory>
#include <vector>

#include "AnimatedSprite.h"
#include "SFML/Graphics/Sprite.hpp"

namespace CafeMoi
{
    class ComponentManager
    {
    public:

        ComponentManager();

        void registerEntity();

        sf::Sprite& addSpriteComponent(int entity, sf::Sprite&& sprite);
        AnimatedSprite& addAnimatedSpriteComponent(int entity, AnimatedSprite&& animatedSprite);
        sf::Vector2f& addPositionComponent(int entity, sf::Vector2f&& position);
        sf::Vector2f& addSpeedComponent(int entity, sf::Vector2f&& speed);

        std::vector<std::unique_ptr<sf::Sprite>>& getSpriteComponents();
        std::vector<std::unique_ptr<AnimatedSprite>>& getAnimatedSpriteComponents();
        std::vector<std::unique_ptr<sf::Vector2f>>& getPositionComponents();
        std::vector<std::unique_ptr<sf::Vector2f>>& getSpeedComponents();

    private:

        std::vector<std::unique_ptr<sf::Sprite>> spriteComponents;
        std::vector<std::unique_ptr<AnimatedSprite>> animatedSpriteComponents;
        std::vector<std::unique_ptr<sf::Vector2f>> positionComponents;
        std::vector<std::unique_ptr<sf::Vector2f>> speedComponents;

    };
}

#endif