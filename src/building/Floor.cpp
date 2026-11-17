#include "Floor.h"

Floor::Floor(Material&& material, const sf::Vector2i position)
    : Tile(position)
    , material(std::move(material))
{
    this->material.sprite.setPosition(sf::Vector2f(this->position));
}
