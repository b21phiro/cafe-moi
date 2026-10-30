#include "Play.h"

#include "Cafemoi.h"

Play::Play(Cafemoi &cafemoi)
    : m_cafemoi(cafemoi)
{

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
