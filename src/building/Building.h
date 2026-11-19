#ifndef CAFEMOI_BUILDING_H
#define CAFEMOI_BUILDING_H

#include <string>
#include <vector>
#include "Floor.h"
#include "Wall.h"

class Building
{

    std::vector<Floor> m_floors;
    std::vector<Wall> m_walls;

    sf::Vector2f m_spawnPoint;

    int m_columns;
    int m_rows;

public:

    Building();

    explicit Building(const std::vector<std::vector<std::string>>& tilemap, AssetsManager& assets);

    std::vector<Floor>& getFloors();
    std::vector<Wall>& getWalls();

    void addFloor(Floor&& floor);
    void addWall(Wall&& wall);

    void setSpawn(const sf::Vector2i& tile);
    sf::Vector2f& getSpawn();

    sf::Vector2f getCenterPosition();

};

#endif
