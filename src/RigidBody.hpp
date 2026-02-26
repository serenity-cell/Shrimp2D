#pragma once
#include "glm/glm.hpp"

// including sfml headers
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class circle
{   
    private:
    glm::vec2 position_current;
    glm::vec2 position_previous;
    glm::vec2 acceleration;

    public:
    // construct with an initial position (defaults to origin)
    circle(const glm::vec2& initPos = glm::vec2(0.0f))
    {}
    // convenience overload
    circle(float x, float y)
    {}

    //--main code--
    glm::vec2 get_position_current() const
    {}

    //adds acce1leration to the current position, then resets acceleration to zero
    void update_position(float deltaTime)
    {}

    void add_acceleration(const glm::vec2& accel)
    {}
};
