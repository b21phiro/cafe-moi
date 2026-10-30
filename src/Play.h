#ifndef CAFEMOI_PLAY_H
#define CAFEMOI_PLAY_H

namespace sf { class RenderWindow; }

class Cafemoi;

class Play
{

    Cafemoi& m_cafemoi;

public:

    Play(Cafemoi &cafemoi);

    void update();

    void draw();

};

#endif