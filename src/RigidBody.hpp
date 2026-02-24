#pragma once
#include "glm/glm.hpp"

struct rigid_body
{
    glm::vec2 position_current;
    glm::vec2 position_previous;
    glm::vec2 acceleration;

    void update_position(float deltaTime)
    {
        const glm::vec2 velocity = position_current - position_previous;
        position_previous = position_current;
        position_current += velocity + acceleration * deltaTime * deltaTime;

        acceleration = {};
    }

    void acceleration ( const glm::vec2& accel )
    {
        acceleration += accel;
    }
};