#include <SFML/Graphics.hpp>

#include "AssetsManager.h"
#include "Tilemap.h"
#include "Tileset.h"

int main()
{

	CafeMoi::AssetsManager assets;
	assets.loadTexture("sprite-sheet", "resources/cafemoi-sprite-sheet.png");

	CafeMoi::Tilemap tilemap(assets, "resources/building-1.xml");

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
		window.display();

	}

}
