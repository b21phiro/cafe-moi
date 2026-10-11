#include "InputManager.h"
#include <algorithm>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "Logger.h"

CafeMoi::InputManager::InputManager(sf::RenderWindow& window)
    : mouseLeftButtonPressedBefore(false)
    , mouseLeftButtonPressedNow(false)
    , mouseRightButtonPressedBefore(false)
    , mouseRightButtonPressedNow(false)
    , mousePosition(sf::Mouse::getPosition(window))
{
    Logger::log("InputManager", "Instance created");
}

void CafeMoi::InputManager::update(sf::RenderWindow& window)
{

    // Update keyboard info.

    keysPressedBefore = keysPressedNow;
    keysPressedNow.clear();
    for (int keyCode = 0; keyCode < sf::Keyboard::KeyCount; keyCode++)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keyCode)))
        {
            keysPressedNow.push_back(static_cast<sf::Keyboard::Key>(keyCode));
        }
    }

    // Update mouse info.
    mouseLeftButtonPressedBefore = mouseLeftButtonPressedNow;
    mouseLeftButtonPressedNow =  sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    mouseRightButtonPressedBefore = mouseRightButtonPressedNow;
    mouseRightButtonPressedNow = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);

    mousePosition = sf::Mouse::getPosition(window);

}

// KEYBOARD

bool CafeMoi::InputManager::isKeyDown(const sf::Keyboard::Key key)
{
    return std::find_if(keysPressedNow.begin(), keysPressedNow.end(), [&key](const sf::Keyboard::Key keyDown)
    {
        return keyDown == key;
    }) != keysPressedNow.end();
}

bool CafeMoi::InputManager::wasKeyDown(sf::Keyboard::Key key)
{
    return std::find_if(keysPressedBefore.begin(), keysPressedBefore.end(), [&key](const sf::Keyboard::Key keyDown)
    {
        return keyDown == key;
    }) != keysPressedBefore.end();
}

bool CafeMoi::InputManager::wasKeyJustPressed(const sf::Keyboard::Key key)
{
    return !wasKeyDown(key) && isKeyDown(key);
}

bool CafeMoi::InputManager::wasKeyJustReleased(const sf::Keyboard::Key key)
{
    return wasKeyDown(key) && !isKeyDown(key);
}

// LMB

bool CafeMoi::InputManager::isLeftMouseButtonDown()
{
    return mouseLeftButtonPressedNow;
}

bool CafeMoi::InputManager::wasLeftMouseButtonJustPressed()
{
    return mouseLeftButtonPressedNow && !mouseLeftButtonPressedBefore;
}

bool CafeMoi::InputManager::wasLeftMouseButtonJustReleased()
{
    return !mouseLeftButtonPressedNow && mouseLeftButtonPressedBefore;
}

// RMB

bool CafeMoi::InputManager::isRightMouseButtonDown()
{
    return mouseRightButtonPressedNow;
}

bool CafeMoi::InputManager::wasRightMouseButtonJustPressed()
{
    return mouseRightButtonPressedNow && !mouseRightButtonPressedBefore;
}

bool CafeMoi::InputManager::wasRightMouseButtonJustReleased()
{
    return !mouseRightButtonPressedNow && mouseRightButtonPressedBefore;
}

sf::Vector2i &CafeMoi::InputManager::getMousePosition()
{
    return mousePosition;
}

