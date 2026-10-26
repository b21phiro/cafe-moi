#include "AssetsManager.h"
#include <iostream>

AssetsManager::AssetsManager()
{

}

bool AssetsManager::loadTexture(const std::string &name, const std::filesystem::path &file)
{
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    if (!texture->loadFromFile(file))
    {
        std::cerr << "*** ERROR *** Failed to load texture!"
                  << "\n\tPath: " << file
                  << "\n\tName: " << name
                  << "\n";
        texture.reset();
        return false;
    }
    m_textures[name] = std::move(texture);
    return true;
}

sf::Texture& AssetsManager::getTexture(const std::string &name)
{
    if (m_textures.find(name) == m_textures.end())
    {
        throw std::runtime_error("*** FATAL *** Texture not found.\n\tName: "+name);
    }
    return *m_textures.at(name);
}
