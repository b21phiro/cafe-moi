#ifndef CAFEMOI_ASSETS_MANAGER_H
#define CAFEMOI_ASSETS_MANAGER_H

#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>

class AssetsManager
{

    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;

public:

    AssetsManager();

    bool loadTexture(const std::string &name, const std::filesystem::path &file);

    sf::Texture& getTexture(const std::string &name);

};

#endif
