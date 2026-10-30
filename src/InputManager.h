#ifndef CAFEMOI_INPUT_MANAGER_H
#define CAFEMOI_INPUT_MANAGER_H
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/WindowBase.hpp"

namespace sf { class Window; }

class InputManager
{

    std::vector<sf::Keyboard::Key> m_currentKeys;
    std::vector<sf::Keyboard::Key> m_previousKeys;
    void updateKeyboardInfo();

    sf::Vector2i m_mouse;
    std::vector<sf::Mouse::Button> m_currentMouseButtons;
    std::vector<sf::Mouse::Button> m_previousMouseButtons;
    void updateMouseInfo(const sf::WindowBase& window);

public:

    InputManager();

    void update(const sf::WindowBase &window);

    bool isKeyDown(sf::Keyboard::Key key) const;
    bool wasKeyDown(sf::Keyboard::Key key) const;
    bool wasKeyJustPressed(sf::Keyboard::Key key) const;
    bool wasKeyJustReleased(sf::Keyboard::Key key) const;

    sf::Vector2i &getMouse();
    bool isMouseButtonDown(sf::Mouse::Button btn) const;
    bool wasMouseButtonDown(sf::Mouse::Button btn) const;
    bool wasMouseButtonJustPressed(sf::Mouse::Button btn) const;
    bool wasMouseButtonJustReleased(sf::Mouse::Button btn) const;

};

#endif

