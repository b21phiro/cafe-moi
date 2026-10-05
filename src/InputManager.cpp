#include "InputManager.h"
#include "Logger.h"
#include "SFML/Window/Event.hpp"

CafeMoi::InputManager::InputManager()
: keyPressedNow(sf::Keyboard::Key::Unknown)
, keyPressedBefore(keyPressedNow)
{
    Logger::log("InputManager", "Instance created");
}

void CafeMoi::InputManager::update()
{
    keyPressedBefore = keyPressedNow;
    keyPressedNow = sf::Keyboard::Key::Unknown;
    for (int keyCode = 0; keyCode < sf::Keyboard::KeyCount; keyCode++)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keyCode)))
        {
            keyPressedNow = static_cast<sf::Keyboard::Key>(keyCode);
        }
    }
}

bool CafeMoi::InputManager::isKeyDown(const sf::Keyboard::Key key)
{
    return keyPressedNow == key;
}

bool CafeMoi::InputManager::wasKeyJustPressed(const sf::Keyboard::Key key)
{
    return keyPressedBefore != key && key == keyPressedNow;
}

bool CafeMoi::InputManager::wasKeyJustReleased(const sf::Keyboard::Key key)
{
    return keyPressedBefore == key && keyPressedNow != key;
}
