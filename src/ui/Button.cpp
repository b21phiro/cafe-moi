#include "Button.h"

#include <iostream>

#include "../Logger.h"

CafeMoi::UI::Button::Button::Button(AssetsManager& assetsManager, const sf::Vector2f position)
    : state(Default)
    , position(position)
    , clickHandler(nullptr)
{
    Logger::log("Button", "Instance created");

    // Retrieves the button sprite(s).
    // Assigns the sprites to the correct states.
    stateTextureRegionMap[Default] = sf::IntRect({ 1008, 992 }, { 16, 16 });
    stateTextureRegionMap[Active] = sf::IntRect({ 1008, 1008 }, { 16, 16 });
    sprite = std::make_unique<sf::Sprite>(assetsManager.getTexture("sprite-sheet"), stateTextureRegionMap[Default]);
}

void CafeMoi::UI::Button::Button::setScale(const float factor)
{
    scale = factor;
}

void CafeMoi::UI::Button::Button::update()
{
    sprite->setTextureRect(stateTextureRegionMap[state]);
    sprite->setScale({ scale, scale });
    sprite->setPosition(position);
    if (icon != nullptr)
    {
        icon->setScale(sprite->getScale());
        icon->setPosition(sprite->getPosition());
    }
}

void CafeMoi::UI::Button::Button::draw(sf::RenderWindow &window)
{
    window.draw(*sprite);
    if (icon != nullptr)
    {
        window.draw(*icon);
    }
}


void CafeMoi::UI::Button::Button::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
}

float CafeMoi::UI::Button::Button::getWidth()
{
    return sprite->getLocalBounds().size.x;
}

float CafeMoi::UI::Button::Button::getHeight()
{
    return sprite->getLocalBounds().size.y;
}

float CafeMoi::UI::Button::Button::getScale()
{
    return scale;
}

void CafeMoi::UI::Button::Button::setIcon(sf::IntRect rect)
{
    icon = std::make_unique<sf::Sprite>(sprite->getTexture(), rect);
    icon->setScale({ scale, scale });
    icon->setPosition(position);
}

sf::FloatRect CafeMoi::UI::Button::Button::getGlobalBounds()
{
    return sprite->getGlobalBounds();
}

void CafeMoi::UI::Button::Button::handleMLBClick()
{
    if (clickHandler == nullptr) return;
    clickHandler();
}

void CafeMoi::UI::Button::Button::onClick(std::function<void()> callback)
{
    clickHandler = std::move(callback);
}
