#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetsManager.h"
#include "InputManager.h"

namespace CafeMoi
{
    class CafeMoi
    {
    public:

        CafeMoi();

        void run();

    private:

        sf::RenderWindow window;

        AssetsManager assetsManager;
        InputManager inputManager;

        void loadContent();
        void exit();

    };
}

#endif