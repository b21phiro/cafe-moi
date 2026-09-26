#ifndef CAFEMOI_TILEMAP_H
#define CAFEMOI_TILEMAP_H

#include "Tileset.h"
#include <map>

namespace CafeMoi
{
    /**
     *
     * A tilemap contains the map data. It contains each layer, what tile goes where, and the shape of the map.
     * Each tile represents different types: Floors, walls, etc. They're identified by their ID.
     * The texture of each tile is in the tilemap's tileset.
     *
     */
    class Tilemap
    {
    public:

        /**
         *
         * Creates a new tilemap using the XML-file.
         *
         * @param assets - The assets manager used for loading textures for the tileset.
         * @param xmlFile The XML file to load the tilemap from.
         *
         */
        explicit Tilemap(AssetsManager& assets, const std::filesystem::path& xmlFile);

    private:

        /**
         *
         * Pointer to tileset used by the tilemap.
         * Is a unique-pointer because a tilemap owns the tileset, and
         * before initiating is nullptr.
         *
         * By using a smart-pointer, I do not have to worry about dangling pointers
         * on destruction.
         *
         */
        std::unique_ptr<Tileset> tileset;

        /**
         *
         * The tile-layers in this tilemap. Is accessed by name.
         *
         * One layer holds a 2D-vector of chars, which represents all tile IDs and their
         * positions within the map.
         *
         * The tile ID can then be used in the tileset to get their sprite.
         *
         */
        std::map<std::string, std::vector<std::vector<int>>> layerMap;



    };
}

#endif