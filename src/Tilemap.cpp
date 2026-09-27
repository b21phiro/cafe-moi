#include "Tilemap.h"
#include <iostream>

#include "CSV.h"
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

    for (pugi::xml_node layer = tilemap.child("layers").first_child();
                        layer; layer = layer.next_sibling())
    {

        std::string layerName = layer.child_value("name");
        layerMap[layerName] = std::vector<std::vector<int>>();

        CSV layerData = CSV(layer.child_value("data"));
        for (int row = 0; row < layerData.getRows(); row++)
        {
            layerMap[layerName].resize(row + 1);
            for (int col = 0; col < layerData.getColumns(); col++)
            {

                // I store the tile numbers e.g. "00", "10", "21" because
                // I like that the CSV data is square and easy to read.
                // Therefore, I split the extra padded 0 from numbers below 10.
                std::string token = layerData.getTokenAt(row, col);
                if (token[0] == '0')
                {
                    token = token.substr(1);
                }

                layerMap[layerName][row].push_back(std::stoi(token));

            }
        }
    }

    Logger::log("Tilemap", "Instance created from XML file.\tXML-file: " + xmlFile.string());

}