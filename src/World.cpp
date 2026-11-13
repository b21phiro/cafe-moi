#include "World.h"

World::World(InputManager& input, AssetsManager& assets)
    : m_assets(assets)
    , m_moveSystem(input)
{

    const int flowerPot = m_entities.createEntity();
    add<TagComponent>(flowerPot, "Misc");

    const int player = m_entities.createEntity();
    add<TagComponent>(player, "Player");
    add<SpriteComponent>(player, sf::Sprite(assets.getTexture("sprite-atlas"), sf::IntRect({ 0, 0 }, { 16, 16 })));
    add<SpeedComponent>(player, sf::Vector2f(-1.f, 0.f));

    m_camera.setZoom(4.5f);

}

void World::update(const sf::Time& delta)
{
    m_moveSystem.process(m_entities.getAll(), m_components, delta);
}

void World::draw(sf::RenderWindow& window)
{
    window.setView(m_camera.getView());
    window.draw(*m_components.get<SpriteComponent>(1).sprite);
}

void World::applyGameSettings(GameSettings& gameSettings)
{
    m_camera.applyGameSettings(gameSettings);
}
