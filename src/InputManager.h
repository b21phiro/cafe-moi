#ifndef CAFEMOI_INPUT_MANAGER_H
#define CAFEMOI_INPUT_MANAGER_H

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace CafeMoi
{
    class InputManager
    {
    public:

        explicit InputManager(sf::RenderWindow& window);

        void update(sf::RenderWindow& window);

        bool isKeyDown(sf::Keyboard::Key key);
        bool wasKeyDown(sf::Keyboard::Key key);
        bool wasKeyJustPressed(sf::Keyboard::Key key);
        bool wasKeyJustReleased(sf::Keyboard::Key key);

        bool isLeftMouseButtonDown();
        bool wasLeftMouseButtonJustPressed();
        bool wasLeftMouseButtonJustReleased();

        bool isRightMouseButtonDown();
        bool wasRightMouseButtonJustPressed();
        bool wasRightMouseButtonJustReleased();

        sf::Vector2i& getMousePosition();


    private:

        // Keyboard info

        std::vector<sf::Keyboard::Key> keysPressedNow;
        std::vector<sf::Keyboard::Key> keysPressedBefore;

        // Mouse info
        bool mouseLeftButtonPressedBefore;
        bool mouseLeftButtonPressedNow;
        bool mouseRightButtonPressedBefore;
        bool mouseRightButtonPressedNow;
        sf::Vector2i mousePosition;

    };
}

#endif
