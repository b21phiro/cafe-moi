#include "Camera.h"

#include <iostream>

Camera::Camera()
    : m_zoom(1.f)
{}

Camera::Camera(sf::View&& view)
    : m_view(view)
    , m_zoom(1.f)
{}

sf::View& Camera::getView()
{
    return m_view;
}

void Camera::applyGameSettings(GameSettings& gameSettings)
{
    m_view.setSize(static_cast<sf::Vector2f>(gameSettings.getScreenSize()));
    m_view.setCenter(sf::Vector2f(0.f, 0.f));
    setZoom(m_zoom);
}

void Camera::setZoom(const float factor)
{
    if (factor == 0.f)
    {
        std::cerr << "*Error* Can not apply a zoom factor of 0.f to the camera!\n";
    }
    m_zoom = factor;
    m_view.zoom(1 / m_zoom);
}