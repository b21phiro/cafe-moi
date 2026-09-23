#include "AssetsManager.h"

#include <algorithm>
#include <iostream>

#include "Logger.h"

CafeMoi::AssetsManager::AssetsManager()
{
    Logger::log("AssetsManager", "Instance created");
}

bool CafeMoi::AssetsManager::loadTexture(const std::string& name, const std::filesystem::path& filePath)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filePath))
    {
        Logger::error("AssetsManager", "Failed to load texture \"" + name + "\" at path \"" + filePath.string() + "\"");
        return false;
    }

    Logger::log("AssetsManager", "Loaded texture: " + name + " at path \"" + filePath.string() + "\"");
    textureRegistry[name] = std::move(texture);

    return true;

}

sf::Texture& CafeMoi::AssetsManager::getTexture(const std::string& name)
{
    if (textureRegistry.empty())
    {
        throw std::runtime_error("[ Fatal error ] AssetsManager: Texture registry is empty!");
    }
    if (textureRegistry.find(name) == textureRegistry.end())
    {
        throw std::runtime_error("[ Fatal error ] AssetsManager: Texture \"" + name + "\" not found!");
    }
    return textureRegistry.at(name);
}