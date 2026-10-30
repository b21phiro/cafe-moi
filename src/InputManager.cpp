#include "InputManager.h"

#include "SFML/Window/Mouse.hpp"

InputManager::InputManager()
{

}

void InputManager::update(const sf::WindowBase &window)
{
    updateKeyboardInfo();
    updateMouseInfo(window);
}

void InputManager::updateKeyboardInfo()
{
    m_previousKeys = m_currentKeys;
    m_currentKeys.clear();
    for (int i = 0; i < sf::Keyboard::KeyCount; i++)
    {
        if (auto key = static_cast<sf::Keyboard::Key>(i); sf::Keyboard::isKeyPressed(key))
        {
            m_currentKeys.push_back(key);
        }
    }
}

bool InputManager::isKeyDown(const sf::Keyboard::Key key) const
{
    return std::find(m_currentKeys.begin(), m_currentKeys.end(), key) != m_currentKeys.end();
}

bool InputManager::wasKeyDown(const sf::Keyboard::Key key) const
{
    return std::find(m_previousKeys.begin(), m_previousKeys.end(), key) != m_previousKeys.end();
}

bool InputManager::wasKeyJustPressed(const sf::Keyboard::Key key) const
{
    return isKeyDown(key) && !wasKeyDown(key);
}

bool InputManager::wasKeyJustReleased(const sf::Keyboard::Key key) const
{
    return !isKeyDown(key) && wasKeyDown(key);
}

void InputManager::updateMouseInfo(const sf::WindowBase& window)
{
    m_mouse = sf::Mouse::getPosition(window);

    m_previousMouseButtons = m_currentMouseButtons;
    m_currentMouseButtons.clear();

    for (int i = 0; i < sf::Mouse::ButtonCount; i++)
    {
        if (auto btn = static_cast<sf::Mouse::Button>(i); sf::Mouse::isButtonPressed(btn))
        {
            m_currentMouseButtons.push_back(btn);
        }
    }

}

sf::Vector2i &InputManager::getMouse()
{
    return m_mouse;
}

bool InputManager::isMouseButtonDown(const sf::Mouse::Button btn) const
{
    return std::find(m_currentMouseButtons.begin(), m_currentMouseButtons.end(), btn) != m_currentMouseButtons.end();
}

bool InputManager::wasMouseButtonDown(const sf::Mouse::Button btn) const
{
    return std::find(m_previousMouseButtons.begin(), m_previousMouseButtons.end(), btn) != m_previousMouseButtons.end();
}

bool InputManager::wasMouseButtonJustPressed(const sf::Mouse::Button btn) const
{
    return isMouseButtonDown(btn) && !wasMouseButtonDown(btn);
}

bool InputManager::wasMouseButtonJustReleased(const sf::Mouse::Button btn) const
{
    return !isMouseButtonDown(btn) && wasMouseButtonDown(btn);
}
