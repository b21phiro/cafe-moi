#include "CafeMoi.h"
#include <SFML/Graphics.hpp>
#include <optional>

void CafeMoi::run()
{

    sf::RenderWindow window( sf::VideoMode( { 1920, 1080 } ), "Cafe moi - v.0.1.0" );
    sf::CircleShape shape( 100.f );
    shape.setFillColor( sf::Color::Red );

    while ( window.isOpen() )
    {
        while ( const std::optional event = window.pollEvent() )
        {
            if ( event->is<sf::Event::Closed>() )
                window.close();
        }

        window.clear();
        window.draw( shape );
        window.display();
    }

}
