#ifndef CAFEMOI_TILESET_H
#define CAFEMOI_TILESET_H

#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "AssetsManager.h"

namespace CafeMoi
{
    /**
     *
     * Represents a tileset.
     *
     * A tileset is a collection of tiles within a sprite sheet. Imagine it as
     * a grid of squares cutout from one image. An ID then
     * identifies each of these tiles.
     *
     * The advantage of using a tileset is that we can reuse these tiles
     * and create maps much quicker, with fewer images.
     *
     */
    class Tileset
    {
    public:

        /**
         *
         * Creates a new tileset.
         *
         * @param texture - The texture source in which the tileset is using. The tileset stores a pointer to the texture.
         * @param columns - The number of columns in the tileset.
         * @param rows - The number of rows in the tileset.
         * @param tileSize - The size of each tile in the tileset. Defaults to 32.
         * @param fallbackTileID - The ID of the fallback tile to use when an invalid ID is provided. Defaults to -1.
         * 
         */
        explicit Tileset(sf::Texture& texture, int columns, int rows, int tileSize = 32, int fallbackTileID = -1);

        /**
         * 
         * Creates a new tileset, using an XML file and the `AssetsManager`.
         * 
         * @param assets - Uses the assets-manager with loaded textures necessary to create the tileset.
         * @param xmlFile - Path to an XML file containing the data.
         * 
         */
        explicit Tileset(AssetsManager& assets, const std::filesystem::path& xmlFile);
        
        /**
         *
         * Returns a copy of a tile rather than a reference.
         *
         * The reason is if I give you a reference to each tile,
         * then any modifications you do to the tile will affect the entire tileset.
         *
         * @param id - Tile.
         * @return - A sprite of the tile.
         *
         */
        sf::Sprite getTile(int id);
        


    private:

        /**
         * The amount of tiles within the tileset.
         */
        int tileAmount;

        /**
         * The number of columns in the tileset.
         */
        int columns;

        /**
         * The number of rows in the tileset.
         */
        int rows;

        /**
         * The size of the tiles in pixels.
         */
        int tileSize;

        /**
         * A tile to fallback on in case a given tile ID is invalid or missing.
         * It is optional, but if set, it will prevent a crash.
         */
        int fallbackTileID;

        /**
         * Each tile stored as a sprite.
         */
        std::vector<sf::Sprite> tiles;

        /**
         * The texture sourced used by the tileset.
         * I store the address of the texture rather than the entire copy of it.
         */
        sf::Texture* texturePtr;

    };
}

#endif
