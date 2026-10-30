#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetsManager.h"
#include "State.h"
#include "Menu.h"

class Cafemoi
{

    sf::RenderWindow m_window;

    State m_state;

    std::unique_ptr<Menu> m_menu;

    AssetsManager m_assets;

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

    void setVersion(const std::string &version);
    std::string &getVersion();

};

#endif
