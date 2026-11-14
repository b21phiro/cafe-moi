#ifndef CAFEMOI_ANIMATION_H
#define CAFEMOI_ANIMATION_H

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>

using AnimationFrame = sf::IntRect;

namespace sf { class Time; class Sprite; }

struct Animation
{

    std::string name;

    bool isPlaying;

    sf::Sprite& sprite;

    std::vector<AnimationFrame> frames;

    int currentFrame;

    sf::Time timeSinceLastFrame;

    explicit Animation(const std::string& name, sf::Sprite& sprite, std::vector<AnimationFrame>&& frames = {});

    void update(const sf::Time& delta);

    void nextFrame();

    void applyCurrentFrame();

    void reset();

    void pause();

    void resume();

    void stop();

    void start();

    AnimationFrame& getCurrentFrame();

};

#endif
