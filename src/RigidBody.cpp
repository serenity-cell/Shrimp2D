#include "RigidBody.hpp"



// construct with an initial position (defaults to origin)
circle::circle(const glm::vec2& initPos = glm::vec2(0.0f))
    : position_current(initPos),
        position_previous(initPos),
        acceleration(0.0f){}

// convenience overload
circle::circle(float x, float y)
    : circle(glm::vec2(x, y))
{}

//--main code--
glm::vec2 circle::get_position_current() const
{
    return position_current;
}

//adds acce1leration to the current position, then resets acceleration to zero
void circle::update_position(float deltaTime)
{
    const glm::vec2 velocity = position_current - position_previous;
    position_previous = position_current;
    position_current += velocity + acceleration * deltaTime * deltaTime;

    acceleration = {};
}

void circle::add_acceleration(const glm::vec2& accel)
{   
    acceleration += accel;
}