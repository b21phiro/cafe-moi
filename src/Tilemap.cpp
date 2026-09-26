#include "Tilemap.h"
#include <iostream>
#include "Logger.h"
#include "pugixml.hpp"


CafeMoi::Tilemap::Tilemap(AssetsManager& assets, const std::filesystem::path& xmlFile)
{

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlFile.string().c_str());

    if (!result)
    {
        throw std::runtime_error("[ Fatal error ] Tilemap: Failed to load XML file.\tFile:" + xmlFile.string());
    }

    pugi::xml_node tilemap = doc.child("building").child("tilemap");

    tileset = std::make_unique<Tileset>(
        assets.getTexture(tilemap.child("tileset").child("image").child_value("name")),
        std::stoi(tilemap.child("tileset").child_value("columns")),
        std::stoi(tilemap.child("tileset").child_value("rows")),
        std::stoi(tilemap.child("tileset").child_value("tilesize")),
        std::stoi(tilemap.child("tileset").child_value("fallbackID")));

    for (pugi::xml_node layer = tilemap.child("layers").child("layer").first_child();
                        layer; layer = layer.next_sibling())
    {
        std::string layerName = layer.child_value("name");

    }


    Logger::log("Tilemap", "Instance created from XML file.\tXML-file: " + xmlFile.string());

}
