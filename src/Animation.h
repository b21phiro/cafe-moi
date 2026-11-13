#ifndef CAFEMOI_ANIMATION_H
#define CAFEMOI_ANIMATION_H

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>

using AnimationFrame = sf::IntRect;

namespace sf { class Time; class Sprite; }

struct Animation
{

    sf::Sprite& sprite;

    std::vector<AnimationFrame> frames;

    int currentFrame;

    sf::Time timeSinceLastFrame;

    explicit Animation(sf::Sprite& sprite, std::vector<AnimationFrame>&& frames = {});

    void update(const sf::Time& delta);

    void nextFrame();

    void applyCurrentFrame();

    AnimationFrame& getCurrentFrame();

};

#endif
