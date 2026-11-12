#include "World.h"

World::World(AssetsManager& assets)
    : m_assets(assets)
{

    int flowerPot = m_entities.createEntity();
    add<TagComponent>(flowerPot, "Misc");

    int player = m_entities.createEntity();
    add<TagComponent>(player, "Player");
    add<SpriteComponent>(player, sf::Sprite(assets.getTexture("sprite-atlas"), sf::IntRect({0, 0}, {16, 16})));

}

void World::update()
{
}

void World::draw(sf::RenderWindow& window)
{
    window.draw(*m_components.get<SpriteComponent>(1).sprite);
}
