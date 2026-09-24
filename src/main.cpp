#include <SFML/Graphics.hpp>

#include "AssetsManager.h"
#include "Tileset.h"

int main()
{

	CafeMoi::AssetsManager assets;
	assets.loadTexture("sprite-sheet", "resources/cafemoi-sprite-sheet.png");

	CafeMoi::Tileset tileset(assets.getTexture("sprite-sheet"), 8, 8, 0, 32, 2);

	sf::Sprite sprite = tileset.getTile(0);

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
		window.draw(sprite);
		window.display();

	}

}
