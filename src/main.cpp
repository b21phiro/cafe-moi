#include <SFML/Graphics.hpp>

#include "AssetsManager.h"
#include "Tileset.h"

int main()
{

	CafeMoi::AssetsManager assets;
	assets.loadTexture("sprite-sheet", "resources/cafemoi-sprite-sheet.png");

	CafeMoi::Tileset tileset(assets, "resources/cafemoi-sprite-sheet.xml");

	sf::Sprite sprite1 = tileset.getTile(0);
	sf::Sprite sprite2 = tileset.getTile(1);
	sprite2.setPosition({ 32.f, 0.f });

	sf::RenderWindow window( sf::VideoMode( { 1280u, 720u } ), "Cafe Moi - v.0.1.0" );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		window.clear();
		window.draw(sprite1);
		window.draw(sprite2);
		window.display();

	}

}
