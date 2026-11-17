#ifndef CAFEMOI_FLOOR_H
#define CAFEMOI_FLOOR_H

#include "Tile.h"
#include "../graphics/Material.h"

struct Floor : Tile
{

    Material material;

    explicit Floor(Material&& material, sf::Vector2i position);

};

#endif
