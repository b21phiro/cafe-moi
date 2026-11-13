#ifndef CAFEMOI_PLAY_H
#define CAFEMOI_PLAY_H

#include "World.h"

namespace sf { class RenderWindow; }

class Cafemoi;

class Play
{
    Cafemoi& m_cafemoi;

    World m_world;

public:

    explicit Play(Cafemoi& cafemoi);

    void update(const sf::Time& delta = sf::Time::Zero);

    void draw();

};

#endif
