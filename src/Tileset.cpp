#include "Tileset.h"

#include <iostream>

#include "Logger.h"
#include "pugixml.hpp"

CafeMoi::Tileset::Tileset(sf::Texture& texture, int columns, int rows, int firstTileID, int tileSize, int fallbackTileID)
: tileAmount(columns * rows)
, firstTileID(firstTileID)
, columns(columns)
, rows(rows)
, tileSize(tileSize)
, fallbackTileID(fallbackTileID)
, texturePtr(&texture)
{

    Logger::log("Tileset", "Instance created.\tTiles: " + std::to_string(tileAmount));

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int tileX = column * tileSize;
            int tileY = row    * tileSize;
            sf::Sprite sprite(*texturePtr, sf::IntRect(
                {  tileX,       tileY    },
                  { tileSize, tileSize }));

            tiles.emplace_back(sprite);
        }
    }

}

CafeMoi::Tileset::Tileset(AssetsManager& assets, const std::filesystem::path& xmlFile)
: tileAmount(0)
, firstTileID(0)
, columns(0)
, rows(0)
, tileSize(0)
, fallbackTileID(-1)
, texturePtr(nullptr)
{

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlFile.string().c_str());

    if (!result)
    {
        throw std::runtime_error("[ Fatal error ] Tileset: Failed to load XML file.\tFile:" + xmlFile.string());
    }

    pugi::xml_node tilesetNode          = doc.child("tileset");
    pugi::xml_node tilesetImage         = tilesetNode.child("image");
    std::string    tilesetImageSource   = tilesetImage.child_value("source");
    std::string    tilesetImageName     = tilesetImage.child_value("name");

    texturePtr                          = &assets.getTexture(tilesetImageName);
    columns                             = std::stoi(tilesetNode.child_value("columns"));
    rows                                = std::stoi(tilesetNode.child_value("rows"));
    tileSize                            = std::stoi(tilesetNode.child_value("tilesize"));
    tileAmount                          = columns * rows;
    fallbackTileID                      = std::stoi(tilesetNode.child_value("fallbackID"));

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int tileX = column * tileSize;
            int tileY = row    * tileSize;
            sf::Sprite sprite(*texturePtr, sf::IntRect(
                {  tileX,       tileY    },
                  { tileSize, tileSize }));

            tiles.emplace_back(sprite);
        }
    }

    Logger::log("Tileset", "Instance created from XML file.\tXML-file: " + xmlFile.string() + "\tTiles: " + std::to_string(tileAmount));
}

sf::Sprite CafeMoi::Tileset::getTile(int id)
{
    if (tileAmount == 0 || id > tileAmount || id < firstTileID)
    {
        Logger::error("Tileset", "Tile ID " + std::to_string(id) + " is out of bounds!");
        if (fallbackTileID == -1)
        {
            throw std::runtime_error("[ Fatal error ] Tileset: Tile is out of bounds.\nGiven tile ID: " + std::to_string(id) + "\nAmount of tiles: " + std::to_string(tileAmount));
        }
        return getTile(fallbackTileID);
    }
    return tiles[id - firstTileID];
}