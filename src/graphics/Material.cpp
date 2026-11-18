#include "Material.h"

std::map<TextureType, sf::IntRect> Material::materialTextureMap = {
    { Planks_0, sf::IntRect({ 0, 0 }, { 16, 16 }) },
    { Tiled_0, sf::IntRect({ 16, 0 }, { 16, 16 }) }
};

Material::Material(const MaterialType type, sf::Sprite&& sprite, sf::Shader&& shader)
    : type(type)
    , sprite(std::move(sprite))
    , shader(std::move(shader))
{
    shader.setUniform("u_texture", sf::Shader::CurrentTexture);
}

void Material::setColor1(const float r, const float g, const float b)
{
    shader.setUniform("u_color1", sf::Glsl::Vec4(r / 255.f, g / 255.f, b / 255.f, 1.f));
}

void Material::setColor2(const float r, const float g, const float b)
{
    shader.setUniform("u_color2", sf::Glsl::Vec4(r / 255.f, g / 255.f, b / 255.f, 1.f));
}

Material Material::create(MaterialType materialType, TextureType textureType, AssetsManager& assets)
{
    sf::Texture& texture = assets.getTexture("cafemoi-materials");
    sf::Shader shader = sf::Shader();
    if (!shader.loadFromFile("resources/shaders/color.frag", sf::Shader::Type::Fragment))
    {
        throw std::runtime_error("Failed to load fragment shader resources/shaders/color.frag");
    }
    sf::Sprite sprite = sf::Sprite(texture, materialTextureMap[textureType]);

    Material material(materialType, std::move(sprite), (std::move(shader)));

    if (textureType == Planks_0)
    {
        material.setColor1(161.f, 88.f, 55.f);
        material.setColor2(184.f, 114.f, 78.f);
    } else if (textureType == Tiled_0)
    {
        material.setColor1(146.f, 149.f, 155.f);
        material.setColor2(170.f, 173.f, 178.f);
    }

    return material;
}
