#include "Cafemoi.h"

Cafemoi::Cafemoi()
    : m_state(MenuState)
    , m_exit(false)
{
    m_window.create(sf::VideoMode({ 1280u, 720u }), "Cafe Moi - v.0.0.1");
}

void Cafemoi::run()
{

    menu();

    while (m_window.isOpen())
    {
        while (const std::optional event = m_window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                m_window.close();
            }
        }
        update();
        draw();
    }
}

void Cafemoi::update()
{
    if (m_exit == true)
    {
        m_window.close();
        return;
    }
}

void Cafemoi::draw()
{
    if (m_state == MenuState)
    {
        m_menu->draw(m_window);
    }
}

void Cafemoi::exit()
{
    m_exit = true;
}

void Cafemoi::menu()
{
    if (m_menu == nullptr)
    {
        m_menu = std::make_unique<Menu>(*this);
    }
    m_state = MenuState;
}

void Cafemoi::play()
{
    m_state = PlayState;
}
