#include "Building.h"
#include <iostream>
#include "Logger.h"
#include "pugixml.hpp"

CafeMoi::Building::Building(std::string name, Tilemap&& tilemap)
: name(name)
, tilemap(std::make_unique<Tilemap>(std::move(tilemap)))
{
    Logger::log("Building", "Created a new building with name " + name);
}

CafeMoi::Building::Building(AssetsManager& assets, std::filesystem::path xmlFile)
: name("Unknown")
{

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlFile.string().c_str());

    if (!result)
    {
        throw std::runtime_error("[ Fatal error ] Tilemap: Failed to load XML file.\tFile:" + xmlFile.string());
    }

    name = doc.child("building").child_value("name");
    tilemap = std::make_unique<Tilemap>(assets, xmlFile);

    Logger::log("Building", "Created a new building with name " + name);
}

void CafeMoi::Building::draw(sf::RenderWindow& window)
{
    tilemap->draw(window);
}

sf::Vector2i CafeMoi::Building::getCenter()
{
    return tilemap->center;
}
