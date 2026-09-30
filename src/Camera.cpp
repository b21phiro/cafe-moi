#include "Camera.h"

#include "Logger.h"

CafeMoi::Camera::Camera(float x, float y, float width, float height, float zoom)
: needsUpdate(true)
, zoom(zoom)
, view(sf::FloatRect({ x, y }, { width, height }))
{
    center = sf::Vector2f(view.getCenter());
    view.zoom(zoom);
    Logger::log("Camera", "Created a new camera");
}

sf::View& CafeMoi::Camera::getView()
{
    return view;
}

void CafeMoi::Camera::update()
{
    if (!needsUpdate)
    {
        return;
    }
    view.setCenter(center);
    view.zoom(zoom);
    needsUpdate = false;
}

void CafeMoi::Camera::setCenter(float x, float y)
{
    center = sf::Vector2f(x, y);
    needsUpdate = true;
}

void CafeMoi::Camera::setZoom(float factor)
{
    if (factor == 0)
    {
        Logger::error("Camera", "Can't zoom by a factor of 0");
        return;
    }
    zoom = 1.f / factor;
    needsUpdate = true;
}

void CafeMoi::Camera::setGridCenter(int x, int y)
{
    const float tileSize = 32.f;
    const float fX = static_cast<float>(x);
    const float fY = static_cast<float>(y);
    center = sf::Vector2f(fX * tileSize + (tileSize * 0.5f), fY * tileSize + (tileSize * 0.5f));
    needsUpdate = true;
}

void CafeMoi::Camera::setGridCenter(sf::Vector2i position)
{
    setGridCenter(position.x, position.y);
}