#ifndef CAFEMOI_ASSETS_MANAGER_H
#define CAFEMOI_ASSETS_MANAGER_H

#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>

class AssetsManager
{

    std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;

public:

    AssetsManager();

    void loadTexture(const std::string& name, const std::filesystem::path &path);

    sf::Texture& getTexture(const std::string &name);

};

#endif
