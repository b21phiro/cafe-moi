#include "Cafemoi.h"

Cafemoi::Cafemoi()
    : m_settings()
    , m_state(MenuState)
    , m_version("Unknown version")
    , m_exit(false)
{
    loadAssets();
    m_window.create(sf::VideoMode(m_settings.getScreenSize()), "Cafe Moi", sf::Style::Close);
}

void Cafemoi::run()
{
    menu();
    sf::Clock clock;
    while (m_window.isOpen())
    {
        sf::Time delta = clock.restart();
        while (const std::optional event = m_window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                m_window.close();
            }
        }
        update(delta);
        draw();
    }
}

void Cafemoi::update(const sf::Time& delta)
{
    m_input.update(m_window);

    if (m_exit == true)
    {
        m_window.close();
        return;
    }

    if (m_state == MenuState)
    {
        m_menu->update();
    } else if (m_state == PlayState)
    {
        m_play->update(delta);
    }

}

void Cafemoi::draw()
{
    if (m_state == MenuState)
    {
        m_menu->draw();
    }
    else if (m_state == PlayState)
    {
        m_play->draw();
    }
    else
    {
        m_window.clear();
        m_window.display();
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
    if (m_play == nullptr)
    {
        m_play = std::make_unique<Play>(*this);
    }
    m_state = PlayState;
}

void Cafemoi::loadAssets()
{
    // Textures.
    m_assets.loadTexture("sprite-atlas", "resources/textures/cafemoi-sprite-atlas.png");
    m_assets.loadTexture("cafemoi-materials", "resources/textures/cafemoi-materials.png");

    // Fonts.
    m_assets.loadFont("cafemoi-regular", "resources/fonts/Cafemoi Regular.ttf");
}

AssetsManager& Cafemoi::getAssets()
{
    return m_assets;
}

sf::RenderWindow& Cafemoi::getWindow()
{
    return m_window;
}

std::string& Cafemoi::getVersion()
{
    return m_version;
}

void Cafemoi::setVersion(const std::string &version)
{
    m_version = version;
}

InputManager& Cafemoi::getInput()
{
    return m_input;
}

GameSettings& Cafemoi::getSettings()
{
    return m_settings;
}
