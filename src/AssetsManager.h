#ifndef CAFEMOI_ASSETS_MANAGER_H
#define CAFEMOI_ASSETS_MANAGER_H

#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>

namespace CafeMoi
{

    class AssetsManager
    {
    public:

        AssetsManager();

        /**
         *
         * Loads and stores a texture in a registry with the given name as the key.
         * Returns false if the texture could not be loaded.
         *
         * @param name - The name of the texture.
         * @param filePath - The path to the texture file.
         *
         * @return True/False - If the texture was loaded successfully.
         *
         */
        bool loadTexture(const std::string& name, const std::filesystem::path& filePath);

        /**
         *
         * Retrieves the reference to a registered texture.
         * If no texture was found, an exception is thrown.
         *
         * @param name - The name of the texture.
         * @return The texture.
         *
         */
        sf::Texture& getTexture(const std::string& name);

    private:

        std::unordered_map<std::string, sf::Texture> textureRegistry;

    };

}

#endif
