#ifndef CAFEMOI_WALL_H
#define CAFEMOI_WALL_H

#include "Tile.h"
#include "../graphics/Material.h"

struct Wall : Tile
{

    Material material;

    explicit Wall(Material&& material, sf::Vector2i position);

};

#endif
