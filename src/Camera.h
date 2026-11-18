#ifndef CAFEMOI_CAMERA_H
#define CAFEMOI_CAMERA_H

#include <SFML/Graphics/View.hpp>
#include "GameSettings.h"
#include "InputManager.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Camera
{

    sf::View m_view;

    float m_zoom;

    sf::RectangleShape m_cameraHelper;
    bool m_showCameraHelper;

    void initCameraHelper();

public:

    Camera();

    explicit Camera(sf::View&& view);

    sf::View& getView();

    void applyGameSettings(GameSettings& gameSettings);

    void setZoom(float factor);

    void setPosition(const sf::Vector2f& position);

    void draw(sf::RenderWindow& window);

    void showHelper();

    void hideHelper();

    void input(const InputManager& input);

};

#endif
