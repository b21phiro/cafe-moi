#include "Cafemoi.h"

Cafemoi::Cafemoi()
{
    m_window.create(sf::VideoMode({ 1280u, 720u }), "Cafe Moi - v.0.0.1");
}

void Cafemoi::run()
{
    while (m_window.isOpen())
    {
        while (const std::optional event = m_window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                m_window.close();
            }
        }
        m_window.clear();
        m_window.display();
    }
}
