#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetsManager.h"
#include "InputManager.h"
#include "ui/UiManager.h"

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
        UiManager uiManager;

        

        void loadContent();
        void exit();

        void initInGameUI();

        void enableBuildMode();



    };
}

#endif