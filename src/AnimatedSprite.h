#ifndef CAFEMOI_ANIMATED_SPRITE_H
#define CAFEMOI_ANIMATED_SPRITE_H

#include <map>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/System/Time.hpp>

namespace CafeMoi
{

    class AnimatedSprite : public sf::Sprite
    {
    public:

        AnimatedSprite(
            const sf::Texture& texture,
            std::map<std::string, std::vector<sf::IntRect>>&& animations,
            std::map<std::string, std::vector<int>>&& timings
        );

        void setAnimation(const std::string& name);

        void update(const sf::Time& timeElapsed);

    private:

        int elapsedTime;

        std::string currentAnimation;
        std::map<std::string, std::vector<sf::IntRect>> animations;
        std::map<std::string, std::vector<int>> timings;

        // Determines where in the animation we're at for each animation.
        std::map<std::string, int> animationFrameIndexMap;

        sf::IntRect& getCurrentFrame();
        int getCurrentFrameTiming();

        void nextFrame();

        void resetCurrentAnimation();

    };

}

#endif
