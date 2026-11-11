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

}

void Play::update()
{
}

void Play::draw()
{
    auto& window = m_cafemoi.getWindow();
    window.clear();
    window.display();
}

int Play::createEntity()
{
    const int entity = m_nextEntityID;
    m_entities.push_back(entity);
    m_nextEntityID++;
    return entity;
}
