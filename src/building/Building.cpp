#include "Building.h"

Building::Building()
    : m_columns(0)
    , m_rows(0)
{}

Building::Building(const std::vector<std::vector<std::string>>& tilemap, AssetsManager& assets)
    : m_columns(0)
    , m_rows(0)
{
    int y = 0;
    for (auto& rows : tilemap)
    {
        int x = 0;
        for (std::string id : rows)
        {
            Material material = Material::create(UnknownMaterialType, UnknownTextureType, assets);
            if (id[1] == 'w')
            {
                material = Material::create(Wood, Planks_0, assets);
            } else if (id[1] == 's')
            {
                material = Material::create(Stone, Tiled_0, assets);
            } else if (id[1] == 'b')
            {
                material = Material::create(Brick, Brick_0, assets);
            } else if (id[1] == 'p')
            {
                if (id[2] == '1')
                {
                    material = Material::create(Wallpaper, Wallpaper_1, assets);
                } else
                {
                    material = Material::create(Wallpaper, Wallpaper_0, assets);
                }
            }

            sf::Vector2i position(x, y);

            if (id == "0") x++;
            if (id[0] == 'f') // Floor type
            {
                addFloor(Floor(std::move(material), position));
            }
            else if (id[0] == 'w') // Wall type
            {
                addWall(Wall(std::move(material), position));
            }
            x++;
            if (y == 0)
            {
                m_columns++;
            }
        }
        y++;
        m_rows++;
    }
}

sf::Vector2f Building::getCenterPosition()
{
    return {
        16.f * static_cast<float>(m_columns) / 2.f,
        16.f * static_cast<float>(m_rows) / 2.f
    };
}

std::vector<Floor>& Building::getFloors()
{
    return m_floors;
}

std::vector<Wall>& Building::getWalls()
{
    return m_walls;
}

void Building::addFloor(Floor&& floor)
{
    m_floors.emplace_back(std::move(floor));
}

void Building::addWall(Wall&& wall)
{
    m_walls.emplace_back(std::move(wall));
}

void Building::setSpawn(const sf::Vector2i& tile)
{
    m_spawnPoint = sf::Vector2f(static_cast<float>(tile.x) * (Tile::width / 2.f), static_cast<float>(tile.y) * (Tile::height / 2.f));
}

sf::Vector2f& Building::getSpawn()
{
    return m_spawnPoint;
}
