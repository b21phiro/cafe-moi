#include "Play.h"
#include "Cafemoi.h"

Play::Play(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
{
    int flowerPot = m_entities.createEntity();
    add<TagComponent>(flowerPot, "Misc");

    int player = m_entities.createEntity();
    add<TagComponent>(player, "Player");
    add<SpriteComponent>(player, sf::Sprite(m_cafemoi.getAssets().getTexture("sprite-atlas"), sf::IntRect({0, 0}, {16, 16})));

}

void Play::update()
{
}

void Play::draw()
{
    auto& window = m_cafemoi.getWindow();
    window.clear();
    window.draw(*get<SpriteComponent>(1).sprite);
    window.display();
}