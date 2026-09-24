#include "Tileset.h"

#include "Logger.h"

CafeMoi::Tileset::Tileset(sf::Texture& texture, int columns, int rows, int firstTileID, int tileSize, int fallbackTileID)
: texturePtr(&texture)
, columns(columns)
, rows(rows)
, firstTileID(firstTileID)
, tileSize(tileSize)
, tileAmount(columns * rows)
, fallbackTileID(fallbackTileID)
{
    Logger::log("Tileset", "Instance created with " + std::to_string(columns * rows) + " tiles");

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int tileX = column * tileSize;
            int tileY = row * tileSize;
            sf::Sprite sprite(*texturePtr, sf::IntRect({ tileX, tileY }, { tileSize, tileSize }));
            tiles.emplace_back(sprite);
        }
    }

}

sf::Sprite CafeMoi::Tileset::getTile(int id)
{
    if (id > tileAmount || id < firstTileID)
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