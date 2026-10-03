#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Building.h"
#include "Camera.h"
#include "ComponentManager.h"
#include "EntityManager.h"
#include "RenderSystem.h"

int main()
{

	CafeMoi::AssetsManager assets;
	assets.loadTexture("sprite-sheet", "resources/cafemoi-sprite-sheet.png");

	CafeMoi::Building building(assets, "resources/building-1.xml");

	CafeMoi::ComponentManager components;

	CafeMoi::EntityManager entities;

	const int player = entities.createEntity();
	components.registerEntity();
	components.addSpriteComponent(player, sf::Sprite(assets.getTexture("sprite-sheet"), sf::IntRect({ 0 * 32, 4 * 32 }, { 32, 35 })));
	components.addPositionComponent(player, sf::Vector2f(
		(float)building.getCenter().x * 32.f,
		(float)building.getCenter().y * 32.f));

	CafeMoi::RenderSystem renderSystem;

	CafeMoi::Camera camera(0.f, 0.f, 1280.f, 720.f);
	camera.setZoom(3.f);
	camera.setGridCenter(building.getCenter());

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

		camera.update();

		window.clear();
		window.setView(camera.getView());
		building.draw(window);
		renderSystem.process(window, entities, components.getSpriteComponents(), components.getPositionComponents());
		window.display();

	}

}
