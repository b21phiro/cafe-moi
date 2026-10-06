#ifndef CAFEMOI_INPUT_MANAGER_H
#define CAFEMOI_INPUT_MANAGER_H

#include <vector>
#include <SFML/Window/Keyboard.hpp>

namespace CafeMoi
{
    class InputManager
    {
    public:

        InputManager();

        void update();

        bool isKeyDown(sf::Keyboard::Key key);

        bool wasKeyDown(sf::Keyboard::Key key);

        bool wasKeyJustPressed(sf::Keyboard::Key key);

        bool wasKeyJustReleased(sf::Keyboard::Key key);


    private:

        std::vector<sf::Keyboard::Key> keysPressedNow;
        std::vector<sf::Keyboard::Key> keysPressedBefore;

    };
}

#endif
