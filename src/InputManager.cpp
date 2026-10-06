#include "InputManager.h"

#include <algorithm>
#include <iostream>

#include "Logger.h"
#include "SFML/Window/Event.hpp"

CafeMoi::InputManager::InputManager()
{
    Logger::log("InputManager", "Instance created");
}

void CafeMoi::InputManager::update()
{
    keysPressedBefore = keysPressedNow;
    keysPressedNow.clear();
    for (int keyCode = 0; keyCode < sf::Keyboard::KeyCount; keyCode++)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keyCode)))
        {
            keysPressedNow.push_back(static_cast<sf::Keyboard::Key>(keyCode));
        }
    }
}

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
