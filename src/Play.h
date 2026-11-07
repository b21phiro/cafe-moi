#ifndef CAFEMOI_PLAY_H
#define CAFEMOI_PLAY_H

#include "ComponentsManager.h"
#include "EntityManager.h"

namespace sf { class RenderWindow; }

class Cafemoi;

class Play
{

    Cafemoi& m_cafemoi;

    EntityManager m_entities;
    ComponentsManager m_components;

    void loadEntities();

public:

    Play(Cafemoi &cafemoi);

    void update();

    void draw();

};

#endif