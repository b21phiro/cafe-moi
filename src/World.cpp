#include "World.h"
#include "AssetsManager.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "building/Floor.h"

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

    m_camera.setZoom(4.5f);

    m_floor.emplace_back(Material::create(Wood, Planks_0, assets), sf::Vector2i(0, 0));
    m_floor.emplace_back(Material::create(Stone, Tiled_0, assets), sf::Vector2i(1, 0));

}

void World::update(const sf::Time& delta)
{
    m_renderSystem.updateAnimations(m_entities, m_components, delta);
    m_moveSystem.process(m_entities, m_components, delta);
}

void World::draw(sf::RenderWindow& window)
{
    window.setView(m_camera.getView());
    m_renderSystem.process(window, m_entities, m_components, m_floor);
}

void World::applyGameSettings(GameSettings& gameSettings)
{
    m_camera.applyGameSettings(gameSettings);
}
