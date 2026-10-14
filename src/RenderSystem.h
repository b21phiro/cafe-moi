#ifndef CAFEMOI_RENDERSYSTEM_H
#define CAFEMOI_RENDERSYSTEM_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "ComponentManager.h"
#include "EntityManager.h"

namespace CafeMoi
{
    class RenderSystem
    {
    public:

        RenderSystem();

        void process(
            sf::RenderWindow& window,
            const sf::Time& timeElapsed,
            EntityManager& entities,
            ComponentManager& components
        );

    };
}

#endif