#include "Tile.h"

Tile::Tile(const sf::Vector2i position)
    : position({ position.x * width, position.y * height })
{}