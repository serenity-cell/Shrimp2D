#pragma once
#include "glm/glm.hpp"

class circle
{   
    public:
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float mass;

    float radius = 10.0;
    // construct with an initial position (defaults to origin)
    circle(const glm::vec2& initPos);
    // convenience overload
    circle(float x, float y);

    circle();

    //--main code--
    glm::vec2 get_position() const;

    
    //adds acce1leration to the current position, then resets acceleration to zero
    void update_position(float deltaTime);

    void add_acceleration(const glm::vec2& accel);
};
