#include <SFML/Graphics.hpp>

#include "AssetsManager.h"

int main()
{

	CafeMoi::AssetsManager assets;
	assets.loadTexture("sprite-sheet", "resources/cafemoi-sprite-sheet.png");

	sf::RenderWindow window( sf::VideoMode( { 1280u, 720u } ), "Cafe Moi - v.0.1.0" );

	sf::Sprite sprite(assets.getTexture("sprite-sheet"));

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
