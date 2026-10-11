#ifndef CAFEMOI_UI_ELEMENT_H
#define CAFEMOI_UI_ELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace CafeMoi { class InputManager; }

namespace CafeMoi::UI
{
    class Element
    {
    public:

        virtual ~Element() = default;

        virtual void update()=0;

        virtual void draw(sf::RenderWindow& window)=0;

        virtual void setScale(float factor)=0;

        virtual float getScale()=0;

        virtual sf::FloatRect getGlobalBounds()=0;

        virtual void handleMLBClick()=0;

    };
}

#endif
