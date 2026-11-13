#include "Play.h"
#include "Cafemoi.h"

Play::Play(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
    , m_world(cafemoi.getAssets())
{
    m_world.applyGameSettings(m_cafemoi.getSettings());
}

void Play::update()
{
    m_world.update();
}

void Play::draw()
{
    auto& window = m_cafemoi.getWindow();
    window.clear();
    m_world.draw(window);
    window.display();
}