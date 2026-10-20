#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Logging.h"

class CafeMoi
{
public:

    CafeMoi();

    void run();

    std::string get_current_state();

    void set_state(std::string state);

    Logging& get_logging();

private:

    Logging logging;

    std::string current_state;

    void draw(sf::RenderWindow& window);

    void init_main_menu();
    void draw_main_menu(sf::RenderWindow& window);

    void init_in_game();
    void draw_in_game(sf::RenderWindow& window);

};

#endif
