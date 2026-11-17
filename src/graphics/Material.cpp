#include "Material.h"

Material::Material(const MaterialType type, sf::Sprite&& sprite, sf::Shader& shader)
    : type(type)
    , sprite(std::move(sprite))
    , shader(shader)
{
    shader.setUniform("u_texture", sf::Shader::CurrentTexture);
}

void Material::setColor1(const float r, const float g, const float b) const
{
    shader.setUniform("u_color1", sf::Glsl::Vec4(r / 255.f, g / 255.f, b / 255.f, 1.f));
}

void Material::setColor2(const float r, const float g, const float b) const
{
    shader.setUniform("u_color2", sf::Glsl::Vec4(r / 255.f, g / 255.f, b / 255.f, 1.f));
}

Material Material::create(MaterialType type, AssetsManager& assets)
{
    sf::Texture& texture = assets.getTexture("cafemoi-materials");
    sf::Shader& shader = assets.getShader("color-frag");
    sf::IntRect rect = sf::IntRect({ 0, 0 }, { 16, 16 });
    sf::Sprite sprite = sf::Sprite(texture, rect);

    Material material(type, std::move(sprite), shader);

    if (type == Wood)
    {
        material.setColor1(161.f, 88.f, 55.f);
        material.setColor2(184.f, 114.f, 78.f);
    }

    return material;
}
