#pragma once
#include "glm/glm.hpp"

class rigid_body
{   
    private:
    glm::vec2 position_current;
    glm::vec2 position_previous;
    glm::vec2 acceleration;
    public:
    // construct with an initial position (defaults to origin)
    rigid_body(const glm::vec2& initPos = glm::vec2(0.0f))
        : position_current(initPos),
          position_previous(initPos),
          acceleration(0.0f)
    {}
    // convenience overload
    rigid_body(float x, float y)
        : rigid_body(glm::vec2(x, y))
    {}

    
    glm::vec2 get_position_current() const
    {
        return position_current;
    }

    //adds acce1leration to the current position, then resets acceleration to zero
    void update_position(float deltaTime)
    {
        const glm::vec2 velocity = position_current - position_previous;
        position_previous = position_current;
        position_current += velocity + acceleration * deltaTime * deltaTime;

        acceleration = {};
    }


    void add_acceleration(const glm::vec2& accel)
    {   
        acceleration += accel;
    }
};

struct circle
{
    glm::vec2 center;
    float radius;
};