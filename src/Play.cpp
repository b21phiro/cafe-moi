#include "Play.h"
#include "Cafemoi.h"
#include "Color.h"
#include "graphics/Material.h"

Play::Play(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
    , m_world(cafemoi.getAssets())
{
    m_world.applyGameSettings(m_cafemoi.getSettings());
}

void Play::input(InputManager& input)
{
    m_world.input(input);
}

void Play::update(const sf::Time& delta)
{
    m_world.update(delta);
}

void Play::draw()
{
    auto& window = m_cafemoi.getWindow();
    window.clear(SkyBlue);
    m_world.draw(window);
    window.display();
}