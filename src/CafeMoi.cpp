#include "CafeMoi.h"
#include "Building.h"
#include "Camera.h"
#include "Logger.h"
#include "MoveSystem.h"
#include "RenderSystem.h"
#include "World.h"

CafeMoi::CafeMoi::CafeMoi()
    : window(sf::VideoMode({ 1280u, 720u }), "Cafe Moi - v.0.1.0")
{
    Logger::log("CafeMoi", "Instance created");
    loadContent();
}

void CafeMoi::CafeMoi::run()
{

    Logger::log("CafeMoi", "Initiating runtime...");

    // Building.
    Building building(assetsManager, "resources/building-1.xml");

    // World.
    World world(assetsManager, building);

    // Systems.
    RenderSystem renderSystem;
    MoveSystem moveSystem;

    // Camera.
    Camera camera(0.f, 0.f, 1280.f, 720.f);
    camera.setZoom(3.f);
    camera.setGridCenter(building.getCenter());

    Logger::log("CafeMoi", "Initiated runtime successfully!");

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

    exit();

}

void CafeMoi::CafeMoi::loadContent()
{
    Logger::log("CafeMoi", "Loading content...");

    assetsManager.loadTexture("sprite-sheet", "resources/cafemoi-sprite-sheet.png");

    Logger::log("CafeMoi", "Loading content completed!");
}

void CafeMoi::CafeMoi::exit()
{
    Logger::log("CafeMoi", "Exiting game...");
    Logger::log("CafeMoi", "Bye!");
}
