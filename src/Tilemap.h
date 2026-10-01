#ifndef CAFEMOI_TILEMAP_H
#define CAFEMOI_TILEMAP_H

#include "Tileset.h"
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>

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
         * The center coordinate of the tilemap.
         *
         * ```xml
         * <object>
         *       <name>Center</name>
         *       <position>
         *           <x>0</x>
         *           <y>0</y>
         *       </position>
         *   </object>
         * ```
         */
        sf::Vector2i center;

        /**
         *
         * Creates a new tilemap using the XML-file.
         *
         * @param assets - The assets manager used for loading textures for the tileset.
         * @param xmlFile The XML file to load the tilemap from.
         *
         */
        explicit Tilemap(AssetsManager& assets, const std::filesystem::path& xmlFile);

        /**
         * Draws the tilemap to the window.
         */
        void draw(sf::RenderWindow& window);

    private:

        /**
         * Number of columns in the tilemap.
         */
        int columns;

        /**
         * Number of rows in the tilemap.
         */
        int rows;

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

        /**
         *
         * Draws a layer individually
         *
         * @param window - The window to draw on.
         * @param layer - Name of the layer.
         *
         */
        void drawLayer(sf::RenderWindow& window, std::string name);

    };
}

#endif