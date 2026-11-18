#include "Camera.h"

#include <iostream>

Camera::Camera()
    : m_zoom(1.f)
    , m_showCameraHelper(false)
{
    initCameraHelper();
}

Camera::Camera(sf::View&& view)
    : m_view(view)
    , m_zoom(1.f)
    , m_showCameraHelper(false)
{
    initCameraHelper();
}

sf::View& Camera::getView()
{
    return m_view;
}

void Camera::applyGameSettings(GameSettings& gameSettings)
{
    m_view.setSize(static_cast<sf::Vector2f>(gameSettings.getScreenSize()));
    m_view.setCenter(m_view.getCenter());
    m_cameraHelper.setPosition(m_view.getCenter());
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

void Camera::setPosition(const sf::Vector2f& position)
{
    m_view.setCenter(position);
    m_cameraHelper.setPosition(m_view.getCenter());
}

void Camera::initCameraHelper()
{
    m_cameraHelper.setSize({ 1.f, 1.f });
    m_cameraHelper.setFillColor(sf::Color::Red);
    m_cameraHelper.setPosition(m_view.getCenter());
}

void Camera::draw(sf::RenderWindow& window)
{
    if (!m_showCameraHelper) return;
    window.draw(m_cameraHelper);
}

void Camera::showHelper()
{
    m_showCameraHelper = true;
}

void Camera::hideHelper()
{
    m_showCameraHelper = false;
}

void Camera::input(const InputManager& input)
{
    if (input.wasKeyJustReleased(sf::Keyboard::Key::F1))
    {
        if (m_showCameraHelper == true) hideHelper();
        else showHelper();
    }
}
