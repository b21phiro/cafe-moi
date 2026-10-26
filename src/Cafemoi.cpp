#include "Cafemoi.h"

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

#include "AssetsManager.h"

Cafemoi::Cafemoi()
{

}

void Cafemoi::run()
{
    sf::RenderWindow window(sf::VideoMode({ 1920u, 1080u }), "Cafe moi | v.0.1.0");

    AssetsManager assets;
    loadAssets(assets);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        update();

        draw(window);

    }

}

void Cafemoi::draw(sf::RenderWindow &window)
{
    window.clear();
    window.display();
}

void Cafemoi::update()
{
}

void Cafemoi::loadAssets(AssetsManager& assets)
{
    assets.loadTexture("sprite-atlas", "resources/cafemoi-sprite-atlas.png");
}