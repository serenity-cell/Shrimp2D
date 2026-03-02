#include "rigidBody.hpp"

circle::circle(){}

// construct with an initial position (defaults to origin)
circle::circle(const glm::vec2& initPos = glm::vec2(0.0f))
    : position(initPos),
        acceleration(0.0f){}

// convenience overload
circle::circle(float x, float y)
    : circle(glm::vec2(x, y))
{}

//--main code--
glm::vec2 circle::get_position() const
{
    return position;
}

//adds acce1leration to the current position, then resets acceleration to zero
void circle::update_position(float deltaTime)
{
    const glm::vec2 velocity = position * deltaTime;
    position = position;
    position += velocity + acceleration * deltaTime * deltaTime;

    acceleration = {};
}

void circle::add_acceleration(const glm::vec2& accel)
{   
    acceleration += accel;
}