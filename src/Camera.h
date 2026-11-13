#ifndef CAFEMOI_CAMERA_H
#define CAFEMOI_CAMERA_H

#include <SFML/Graphics/View.hpp>
#include "GameSettings.h"

class Camera
{

    sf::View m_view;

    float m_zoom;

public:

    Camera();

    explicit Camera(sf::View&& view);

    sf::View& getView();

    void applyGameSettings(GameSettings& gameSettings);

    void setZoom(float factor);

};

#endif
