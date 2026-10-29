#include "AssetsManager.h"

AssetsManager::AssetsManager()
{

}

void AssetsManager::loadTexture(const std::string& name, const std::filesystem::path &path)
{
    sf::Texture texture;
    if (texture.loadFromFile(path) == false)
    {
        throw std::runtime_error("Failed to load texture: " + name);
    }
    m_textures[name] = std::make_unique<sf::Texture>(std::move(texture));
}

sf::Texture &AssetsManager::getTexture(const std::string &name)
{
    if (m_textures.find(name) == m_textures.end())
    {
        throw std::runtime_error("Texture not found" + name);
    }
    return *m_textures[name];
}

void AssetsManager::loadFont(const std::string &name, const std::filesystem::path &path)
{
    sf::Font font;
    if (font.openFromFile(path) == false)
    {
        throw std::runtime_error("Failed to load font: " + name);
    }
    m_fonts[name] = std::make_unique<sf::Font>(std::move(font));
}

sf::Font &AssetsManager::getFont(const std::string &name)
{
    if (m_fonts.find(name) == m_fonts.end())
    {
        throw std::runtime_error("Font not found" + name);
    }
    return *m_fonts[name];
}
