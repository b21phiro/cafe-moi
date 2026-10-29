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
