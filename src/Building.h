#ifndef CAFEMOI_BUILDING_H
#define CAFEMOI_BUILDING_H
#include <string>

#include "Tilemap.h"

namespace CafeMoi
{
    class Building
    {

    public:

        std::string name;

        explicit Building(std::string name, Tilemap&& tilemap);

        explicit Building(AssetsManager& assets, std::filesystem::path xmlFile);

        void draw(sf::RenderWindow& window);

        sf::Vector2i getCenter();

    private:

        std::unique_ptr<Tilemap> tilemap;

    };
}

#endif
