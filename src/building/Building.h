#ifndef CAFEMOI_BUILDING_H
#define CAFEMOI_BUILDING_H

#include <string>
#include <vector>
#include "Floor.h"

class Building
{

    std::vector<Floor> m_floor;

    int m_columns;
    int m_rows;

public:

    Building();

    explicit Building(const std::vector<std::vector<std::string>>& tilemap, AssetsManager& assets);

    std::vector<Floor>& getFloor();

    sf::Vector2f getCenterPosition();

};

#endif