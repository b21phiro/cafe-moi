#ifndef CAFEMOI_BUTTON_H
#define CAFEMOI_BUTTON_H

#include <functional>
#include <map>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

#include "Element.h"
#include "../AssetsManager.h"

namespace CafeMoi::UI::Button
{

    enum State
    {
        Default,
        Active
    };

    class Button : public Element
    {

    public:

        explicit Button(AssetsManager& assetsManager, sf::Vector2f position = sf::Vector2f());

        void update() override;

        void draw(sf::RenderWindow &window) override;

        void setScale(float factor) override;
        float getScale() override;

        void setPosition(sf::Vector2f thePosition);

        float getWidth();

        float getHeight();

        void setIcon(sf::IntRect rect);

        sf::FloatRect getGlobalBounds() override;

        void handleMLBClick() override;

        void onClick(std::function<void()> callback);

    private:

        State state;

        sf::Vector2f position;

        float scale;

        std::function<void()> clickHandler;

        std::unique_ptr<sf::Sprite> sprite;
        std::map<State, sf::IntRect> stateTextureRegionMap;
        std::unique_ptr<sf::Sprite> icon;

    };

}

#endif