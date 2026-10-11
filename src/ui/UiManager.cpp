#include "UiManager.h"

#include <iostream>

#include "Button.h"
#include "../InputManager.h"
#include "../Logger.h"

CafeMoi::UiManager::UiManager(float x, float y, float width, float height, float zoom)
    : zoom(zoom)
    , view(sf::FloatRect({ x, y }, { width, height }))
{
    Logger::log("UI Manager", "Instance created!");
}

void CafeMoi::UiManager::input(InputManager& inputManager)
{
    if (inputManager.wasLeftMouseButtonJustPressed())
    {
        const auto& mouse = inputManager.getMousePosition();
        for (const auto& element : elements)
        {
            if (!element->getGlobalBounds().contains(sf::Vector2<float>(mouse))) continue;
            element->handleMLBClick();
        }
    }
}

void CafeMoi::UiManager::update()
{
    for (const std::unique_ptr<UI::Element>& element : elements)
    {
        element->update();
    }
}

void CafeMoi::UiManager::draw(sf::RenderWindow &window)
{

    window.setView(view);

    for (const std::unique_ptr<UI::Element>& element : elements)
    {
        element->draw(window);
    }
}

CafeMoi::UI::Button::Button& CafeMoi::UiManager::createButton(UI::Button::Button&& button)
{
    auto ptr = std::make_unique<UI::Button::Button>(std::move(button));
    auto& addr = *ptr;
    elements.emplace_back(std::move(ptr));
    return addr;
}
