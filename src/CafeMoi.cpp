#include "CafeMoi.h"
#include <SFML/Graphics.hpp>
#include <optional>

CafeMoi::CafeMoi()
    : current_state("MainMenu")
{}

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

std::string CafeMoi::get_current_state()
{
    return current_state;
}

void CafeMoi::set_state(std::string state)
{
    current_state = state;
}
