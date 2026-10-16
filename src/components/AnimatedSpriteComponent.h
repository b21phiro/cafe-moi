#ifndef CAFEMOI_ANIMATED_SPRITE_COMPONENT_H
#define CAFEMOI_ANIMATED_SPRITE_COMPONENT_H

#include "Component.h"
#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <vector>
#include <string>
#include <SFML/System/Time.hpp>


namespace CafeMoi
{

    struct AnimatedSpriteComponent : Component
    {

        sf::Sprite sprite;
        sf::Time elapsedTime;
        std::string currentAnimation;
        std::map<std::string, std::vector<sf::IntRect>> animations;
        std::map<std::string, std::vector<int>> timings;
        std::map<std::string, int> animationFrameIndexMap;

        AnimatedSpriteComponent(
            int entity,
            sf::Sprite&& sprite,
            std::map<std::string, std::vector<sf::IntRect>>&& animations,
            std::map<std::string, std::vector<int>>&& timings
        );


        sf::IntRect& getCurrentFrame();
        sf::Time getCurrentFrameTiming();
        void setAnimation(const std::string& name);
        void update(const sf::Time& timeElapsed);
        void nextFrame();
        void resetCurrentAnimation();

    };

}

#endif
