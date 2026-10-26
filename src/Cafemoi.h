#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <SFML/Graphics/RenderWindow.hpp>

class Cafemoi
{
public:

    Cafemoi();

    void run();

    void draw(sf::RenderWindow &window);

    void update();

};


#endif
