#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetsManager.h"
#include "InputManager.h"
#include "State.h"
#include "Menu.h"
#include "Play.h"

class Cafemoi
{

    sf::RenderWindow m_window;

    State m_state;

    std::unique_ptr<Menu> m_menu;
    std::unique_ptr<Play> m_play;

    AssetsManager m_assets;

    InputManager m_input;

    std::string m_version;

    bool m_exit;

    void loadAssets();

public:

    Cafemoi();

    void update();

    void draw();

    void run();

    void exit();

    void menu();

    void play();

    sf::RenderWindow &getWindow();

    AssetsManager &getAssets();
    InputManager &getInput();

    void setVersion(const std::string &version);
    std::string &getVersion();

};

#endif
