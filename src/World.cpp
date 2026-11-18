#include "World.h"
#include "AssetsManager.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "building/Building.h"

World::World(AssetsManager& assets)
    : m_assets(assets)
{

    const int flowerPot = m_entities.createEntity();
    add<TagComponent>(flowerPot, "Misc");

    const int player = m_entities.createEntity();
    add<TagComponent>(player, "Player");
    add<SpeedComponent>(player, sf::Vector2f(0.f, 0.f));

    auto& playerSprite = add<AnimatedSpriteComponent>(player, sf::Sprite(assets.getTexture("sprite-atlas"), sf::IntRect({ 0, 0 }, { 16, 16 })));
    playerSprite.addAnimation("player-move-down", std::vector{
        sf::IntRect({ 0, 0 }, { 16, 16 }),
        sf::IntRect({ 16, 0 }, { 16, 16 }),
        sf::IntRect({ 0, 0 }, { 16, 16 }),
        sf::IntRect({ 32, 0 }, { 16, 16 }),
    });

    playerSprite.addAnimation("player-move-right", std::vector{
        sf::IntRect({ 0, 32 }, { 16, 16 }),
        sf::IntRect({ 16, 32 }, { 16, 16 }),
        sf::IntRect({ 0, 32 }, { 16, 16 }),
        sf::IntRect({ 32, 32 }, { 16, 16 }),
    });

    playerSprite.addAnimation("player-move-left", std::vector{
        sf::IntRect({ 0, 48 }, { 16, 16 }),
        sf::IntRect({ 16, 48 }, { 16, 16 }),
        sf::IntRect({ 0, 48 }, { 16, 16 }),
        sf::IntRect({ 32, 48 }, { 16, 16 }),
    });

    playerSprite.addAnimation("player-move-up", std::vector{
        sf::IntRect({ 0, 16 }, { 16, 16 }),
        sf::IntRect({ 16, 16 }, { 16, 16 }),
        sf::IntRect({ 0, 16 }, { 16, 16 }),
        sf::IntRect({ 32, 16 }, { 16, 16 }),
    });

    m_building = Building({
        { "fw0", "fs0", "fs0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
        { "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0", "fw0" },
    }, assets);

    m_camera.setZoom(4.f);
    m_camera.setPosition(m_building.getCenterPosition());

}

void World::input(InputManager& input)
{
    m_moveSystem.input(input, m_entities, m_components);
    m_camera.input(input);
}

void World::update(const sf::Time& delta)
{
    m_renderSystem.updateAnimations(m_entities, m_components, delta);
    m_moveSystem.process(m_entities, m_components, delta);
}

void World::draw(sf::RenderWindow& window)
{
    window.setView(m_camera.getView());
    m_renderSystem.process(window, m_entities, m_components, m_building);
    m_camera.draw(window);
}

void World::applyGameSettings(GameSettings& gameSettings)
{
    m_camera.applyGameSettings(gameSettings);
}
