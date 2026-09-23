#include <SFML/Graphics.hpp>

#include "AssetsManager.h"

int main()
{

	CafeMoi::AssetsManager assets;
	assets.loadTexture("Test", "resources/cafemoi-sprite-sheet.png");

	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );

	sf::Sprite sprite(assets.getTexture("Test"));

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
