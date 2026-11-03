#ifndef CAFEMOI_PLAY_H
#define CAFEMOI_PLAY_H
#include "EntityManager.h"

namespace sf { class RenderWindow; }

class Cafemoi;

class Play
{

    Cafemoi& m_cafemoi;

    EntityManager m_entities;

public:

    Play(Cafemoi &cafemoi);

    void update();

    void draw();

};

#endif