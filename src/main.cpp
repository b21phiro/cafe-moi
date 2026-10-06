#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Building.h"
#include "Camera.h"
#include "InputManager.h"
#include "MoveSystem.h"
#include "RenderSystem.h"
#include "World.h"

int main()
{

	CafeMoi::AssetsManager assets;
	assets.loadTexture("sprite-sheet", "resources/cafemoi-sprite-sheet.png");

	CafeMoi::Building building(assets, "resources/building-1.xml");

	CafeMoi::World world(assets, building);

	CafeMoi::RenderSystem renderSystem;
	CafeMoi::MoveSystem moveSystem;

	CafeMoi::Camera camera(0.f, 0.f, 1280.f, 720.f);
	camera.setZoom(3.f);
	camera.setGridCenter(building.getCenter());

	CafeMoi::InputManager inputManager;

	sf::RenderWindow window( sf::VideoMode( { 1280u, 720u } ), "Cafe Moi - v.0.1.0" );

	sf::Clock clock;
	while ( window.isOpen() )
	{
		sf::Time timeElapsed = clock.restart();

		while ( const std::optional event = window.pollEvent() )
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		inputManager.update();
		moveSystem.process(
			timeElapsed,
			inputManager,
			world.getEntityManager(),
			world.getComponentManager().getSpeedComponents(),
			world.getComponentManager().getPositionComponents()
		);

		camera.update();

		window.clear();
		window.setView(camera.getView());
		building.draw(window);
		renderSystem.process(window, world.getEntityManager(), world.getComponentManager().getSpriteComponents(), world.getComponentManager().getPositionComponents());
		window.display();

	}

}
