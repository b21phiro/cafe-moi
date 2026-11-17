#ifndef CAFEMOI_TILE_H
#define CAFEMOI_TILE_H

#include <SFML/System/Vector2.hpp>

struct Tile
{

    constexpr static int width = 16;
    constexpr static int height = 16;

    sf::Vector2i position;

    explicit Tile(sf::Vector2i position);

};

#endif
