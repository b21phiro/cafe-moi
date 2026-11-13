#include "Play.h"
#include "Cafemoi.h"

Play::Play(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
    , m_world(cafemoi.getInput(), cafemoi.getAssets())
{
    m_world.applyGameSettings(m_cafemoi.getSettings());
}

void Play::update(const sf::Time& delta)
{
    m_world.update(delta);
}

void Play::draw()
{
    auto& window = m_cafemoi.getWindow();
    window.clear();
    m_world.draw(window);
    window.display();
}