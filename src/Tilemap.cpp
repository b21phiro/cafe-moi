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
        std::stoi(tilemap.child("tileset").child_value("fallbackid")),
        std::stoi(tilemap.child("tileset").child_value("firsttileid")));

    for (pugi::xml_node layer = tilemap.child("layers").first_child();
                        layer; layer = layer.next_sibling())
    {

        std::string layerName = layer.child_value("name");
        layerMap[layerName]   = std::vector<std::vector<int>>();

        CSV layerData         = CSV(layer.child_value("data"));
        columns               = layerData.getColumns();
        rows                  = layerData.getRows();

        layerMap[layerName].resize(rows);

        for (int row = 0; row < layerData.getRows(); row++)
        {

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

    for (pugi::xml_node object = tilemap.child("objects").first_child();
                        object; object = object.next_sibling("object"))
    {
        std::string objectName = object.child_value("name");
        if (objectName == "Center")
        {
            center = sf::Vector2i(
                std::stoi(object.child("position").child_value("x")),
                std::stoi(object.child("position").child_value("y"))
            );
        }
    }

    Logger::log("Tilemap", "Instance created from XML file.\tXML-file: " + xmlFile.string());

}

void CafeMoi::Tilemap::draw(sf::RenderWindow& window)
{
    drawLayer(window, "Terrain");
    drawLayer(window, "Structure");
}

void CafeMoi::Tilemap::drawLayer(sf::RenderWindow& window, std::string name)
{
    auto& layer = layerMap[name];
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int tileID = layer[row][column];

            if (tileID == 0)
            {
                continue;
            }

            sf::Sprite sprite = tileset->getTile(tileID);
            sprite.setPosition(sf::Vector2f(
                (float)column * (float)tileset->getTileSize(),
                (float)row    * (float)tileset->getTileSize()));

            window.draw(sprite);

        }
    }
}
