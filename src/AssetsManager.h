#ifndef CAFEMOI_ASSETS_MANAGER_H
#define CAFEMOI_ASSETS_MANAGER_H

#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class AssetsManager
{

    std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
    std::map<std::string, std::unique_ptr<sf::Font>> m_fonts;

public:

    AssetsManager();

    void loadTexture(const std::string& name, const std::filesystem::path &path);
    sf::Texture& getTexture(const std::string &name);

    void loadFont(const std::string& name, const std::filesystem::path &path);
    sf::Font& getFont(const std::string &name);
};

#endif
