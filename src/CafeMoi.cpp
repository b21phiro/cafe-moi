#include "CafeMoi.h"
#include <optional>
#include <SFML/Graphics/CircleShape.hpp>

CafeMoi::CafeMoi()
    : current_state("MainMenu")
{
    logging.set_logging_level("debug");
}

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
        draw(window);
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

    if (state == "InGame")
    {
        init_in_game();
    } else if (state == "MainMenu")
    {
        init_main_menu();
    } else
    {
        const std::string message = std::string("Error: Attempted to set unknown game-state.")
            + std::string("\nCurrent state: " + current_state)
            + std::string("\nUnknown state: " + state);

        logging.debug(message);
        return;
    }

    current_state = state;
}

Logging& CafeMoi::get_logging()
{
    return logging;
}

void CafeMoi::draw(sf::RenderWindow& window)
{
    if (get_current_state() == "InGame")
    {
        draw_in_game(window);
    } else if (get_current_state() == "MainMenu")
    {
        draw_main_menu(window);
    }
}

void CafeMoi::init_main_menu()
{
}

void CafeMoi::draw_main_menu(sf::RenderWindow& window)
{
}

void CafeMoi::init_in_game()
{
}

void CafeMoi::draw_in_game(sf::RenderWindow& window)
{
}
