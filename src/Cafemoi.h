#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetsManager.h"

class Cafemoi
{

    void loadAssets(AssetsManager& assets);

public:

    Cafemoi();

    void run();

    void draw(sf::RenderWindow &window);

    void update();

};


#endif
