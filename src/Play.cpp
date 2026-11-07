#include "Play.h"

#include <iostream>

#include "Cafemoi.h"

Play::Play(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
    , m_entities(3000)
{
    loadEntities();
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

void Play::loadEntities()
{
    const Entity player = m_entities.createEntity();
    Tag& playerTag = m_components.addTag(player, "Player");

    const Entity flowerPot = m_entities.createEntity();
    Tag& flowerPotTag = m_components.addTag(flowerPot, "Flower pot");

}
