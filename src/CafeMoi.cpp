#include "CafeMoi.h"

#include <iostream>

#include "Building.h"
#include "Camera.h"
#include "Logger.h"
#include "MoveSystem.h"
#include "RenderSystem.h"
#include "World.h"
#include "ui/Button.h"

CafeMoi::CafeMoi::CafeMoi()
    : window(sf::VideoMode({ 1280u, 720u }), "Cafe Moi - v.0.1.0")
    , inputManager(window)
    , uiManager(0, 0, 1280u, 720u, 4.f)
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

    initInGameUI();

    Logger::log("CafeMoi", "Initiated runtime successfully!");

    sf::Clock clock;
    while ( window.isOpen() )
    {
        sf::Time timeElapsed = clock.restart();

        // Captures input.

        while ( const std::optional event = window.pollEvent() )
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // I need the window to update the
        // mouse position properly.
        inputManager.update(window);
        uiManager.input(inputManager);

        // Update.

        uiManager.update();

        moveSystem.process(
            timeElapsed,
            inputManager,
            world.getEntityManager(),
            world.getComponentManager().getSpeedComponents(),
            world.getComponentManager().getPositionComponents()
        );

        camera.update();

        // Draw.

        // Clears the screen for next paint.
        window.clear();

        // Draws the UI.
        uiManager.draw(window);

        // Draws the game from camera-view.
        window.setView(camera.getView());

        // Draws the building.
        building.draw(window);

        // Draws entities.
        renderSystem.process(window, world.getEntityManager(), world.getComponentManager().getSpriteComponents(), world.getComponentManager().getPositionComponents());

        // Finally renders on the screen.
        window.display();

    }

    exit();

}

void CafeMoi::CafeMoi::loadContent()
{
    Logger::log("CafeMoi", "Loading content...");

    assetsManager.loadTexture("sprite-sheet", "resources/sprite-sheet.png");

    Logger::log("CafeMoi", "Loading content completed!");
}

void CafeMoi::CafeMoi::exit()
{
    Logger::log("CafeMoi", "Exiting game...");
    Logger::log("CafeMoi", "Bye!");
}

void CafeMoi::CafeMoi::initInGameUI()
{
    Logger::log("UI Manager", "Initializing in-game UI...");

    // Build mode button.
    auto& buildButton = uiManager.createButton(UI::Button::Button(assetsManager));
    buildButton.onClick([this]() { enableBuildMode(); });
    buildButton.setIcon(sf::IntRect({ 992, 992 }, { 16, 16 }));
    buildButton.setScale(4.f);
    buildButton.setPosition(sf::Vector2f(
        window.getSize().x - (buildButton.getWidth() * buildButton.getScale()) - 8.f,
        window.getSize().y - (buildButton.getHeight() * buildButton.getScale()) - 8.f));

    Logger::log("UI Manager", "Initiated in-game UI successfully!");
}

void CafeMoi::CafeMoi::enableBuildMode()
{
    std::cout << "Build mode activated" << std::endl;
}
