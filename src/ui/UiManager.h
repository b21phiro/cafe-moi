#ifndef CAFEMOI_UI_MANAGER_H
#define CAFEMOI_UI_MANAGER_H

#include <vector>

#include "Button.h"
#include "Element.h"
#include "../AssetsManager.h"
#include "../InputManager.h"

namespace CafeMoi
{

    class UiManager
    {
    public:

        explicit UiManager(float x = 0.f, float y = 0.f, float width = 100.f, float height = 100.f, float zoom = 1.f);

        void input(InputManager& inputManager);

        void update();

        void draw(sf::RenderWindow& window);

        UI::Button::Button& createButton(UI::Button::Button&& button);

    private:

        float zoom;
        std::vector<std::unique_ptr<UI::Element>> elements;
        sf::View view;

    };
}

#endif