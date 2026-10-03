#ifndef CAFEMOI_RENDERSYSTEM_H
#define CAFEMOI_RENDERSYSTEM_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "EntityManager.h"

namespace CafeMoi
{
    class RenderSystem
    {
    public:

        RenderSystem();

        void process(
            sf::RenderWindow& window,
            EntityManager& entities,
            std::vector<std::unique_ptr<sf::Sprite>>& spriteComponents,
            std::vector<std::unique_ptr<sf::Vector2f>>& positionComponents);

    };
}

#endif