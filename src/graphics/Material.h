#ifndef CAFEMOI_MATERIAL_H
#define CAFEMOI_MATERIAL_H

#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../AssetsManager.h"

enum MaterialType
{
    Wood,
    Stone,
    Unknown,
};

enum TextureType
{
    Planks_0,
    Tiled_0,
};

struct Material
{

    MaterialType type;

    sf::Sprite sprite;
    sf::Shader shader;

    static std::map<TextureType, sf::IntRect> materialTextureMap;

    explicit Material(MaterialType type, sf::Sprite&& sprite, sf::Shader&& shader);

    void setColor1(float r, float g, float b);
    void setColor2(float r, float g, float b);

    static Material create(MaterialType materialType, TextureType textureType, AssetsManager& assets);

};

#endif