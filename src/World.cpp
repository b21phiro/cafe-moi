#include "World.h"
#include "AssetsManager.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

World::World(InputManager& input, AssetsManager& assets)
    : m_assets(assets)
    , m_moveSystem(input)
{

    const int flowerPot = m_entities.createEntity();
    add<TagComponent>(flowerPot, "Misc");

    const int player = m_entities.createEntity();
    add<TagComponent>(player, "Player");
    add<SpeedComponent>(player, sf::Vector2f(-1.f, 0.f));
    auto& playerSprite = add<AnimatedSpriteComponent>(player, sf::Sprite(assets.getTexture("sprite-atlas"), sf::IntRect({ 0, 0 }, { 16, 16 })));
    playerSprite.addAnimation("walking-south", std::vector{
        sf::IntRect({ 0, 0 }, { 16, 16 }),
        sf::IntRect({ 16, 0 }, { 16, 16 }),
        sf::IntRect({ 0, 0 }, { 16, 16 }),
        sf::IntRect({ 32, 0 }, { 16, 16 }),
    });

    m_camera.setZoom(4.5f);

}

void World::update(const sf::Time& delta)
{
    m_renderSystem.updateAnimations(m_entities, m_components, delta);
    m_moveSystem.process(m_entities, m_components, delta);
}

void World::draw(sf::RenderWindow& window)
{
    window.setView(m_camera.getView());
    m_renderSystem.process(window, m_entities, m_components);
}

void World::applyGameSettings(GameSettings& gameSettings)
{
    m_camera.applyGameSettings(gameSettings);
}
