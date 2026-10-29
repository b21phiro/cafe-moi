#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "State.h"
#include "Menu.h"

class Cafemoi
{

    sf::RenderWindow m_window;

    State m_state;

    std::unique_ptr<Menu> m_menu;

    bool m_exit;

public:

    Cafemoi();

    void update();

    void draw();

    void run();

    void exit();

    void menu();

    void play();

};

#endif
