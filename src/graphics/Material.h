#ifndef CAFEMOI_MATERIAL_H
#define CAFEMOI_MATERIAL_H

#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../AssetsManager.h"

enum MaterialType
{
    Wood,
    Unknown,
};

struct Material
{

    MaterialType type;

    sf::Sprite sprite;
    sf::Shader& shader;

    explicit Material(MaterialType type, sf::Sprite&& sprite, sf::Shader& shader);

    void setColor1(float r, float g, float b) const;
    void setColor2(float r, float g, float b) const;

    static Material create(MaterialType type, AssetsManager& assets);

};

#endif