#include "Building.h"

Building::Building()
    : m_columns(0), m_rows(0)
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
            if (id == "0") x++;
            if (id[0] == 'f') // Is floor type
            {
                if (id[1] == 'w') // Wood.
                {
                    m_floor.emplace_back(Material::create(Wood, Planks_0, assets), sf::Vector2i(x, y));
                } else if (id[1] == 's') // Stone.
                {
                    m_floor.emplace_back(Material::create(Stone, Tiled_0, assets), sf::Vector2i(x, y));
                }
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

std::vector<Floor>& Building::getFloor()
{
    return m_floor;
}

sf::Vector2f Building::getCenterPosition()
{
    return {
        16.f * static_cast<float>(m_columns) / 2.f,
        16.f * static_cast<float>(m_rows) / 2.f
    };
}