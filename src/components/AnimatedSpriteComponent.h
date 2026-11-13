#ifndef CAFEMOI_ANIMATED_SPRITE_COMPONENT_H
#define CAFEMOI_ANIMATED_SPRITE_COMPONENT_H

#include <map>
#include <string>
#include "SpriteComponent.h"
#include "../Animation.h"

struct AnimatedSpriteComponent : SpriteComponent
{

    std::map<std::string, Animation> animations;
    Animation* animation;

    AnimatedSpriteComponent();

    explicit AnimatedSpriteComponent(const sf::Sprite &sprite);

    void addAnimation(const std::string& name, std::vector<AnimationFrame>&& frames);

    void play(const std::string& animationName);

    void update(const sf::Time& delta);

    void playTheFirstAnimation();

};

#endif