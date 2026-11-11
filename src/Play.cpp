#include "Play.h"
#include "Cafemoi.h"

Play::Play(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
    , m_nextEntityID(0)
{
    int flowerPot = createEntity();
    add<TagComponent>(flowerPot, "Misc");

    int player = createEntity();
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

int Play::createEntity()
{
    const int entity = m_nextEntityID;
    m_entities.push_back(entity);
    m_nextEntityID++;
    return entity;
}
