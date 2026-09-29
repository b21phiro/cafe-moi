#ifndef CAFEMOI_CAMERA_H
#define CAFEMOI_CAMERA_H

#include <SFML/Graphics/View.hpp>

namespace CafeMoi
{
    class Camera
    {
    public:

        explicit Camera(float x = 0.f, float y = 0.f, float width = 100.f, float height = 100.f, float zoom = 1.f);

        sf::View& getView();

        void setCenter(float x, float y);

        void setZoom(float factor);

        /**
         * Sets the center of a given grid position of the world.
         * Ex: { 0; 0 } multiplied by the tile size (32).
         */
        void setGridCenter(int x, int y);

        void update();

    private:

        bool needsUpdate;

        float zoom;

        sf::Vector2f center;

        sf::View view;

    };
}

#endif
