#pragma once
#include "glm/glm.hpp"

class circleBody 
{   
    public:
    // basic foundation for the circle
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float mass;
    float radius = 6.0;


    // construct with an initial position (defaults to origin)
    circleBody(const glm::vec2& initPos);
    // convenience overload
    circleBody(float x, float y);

    circleBody();

    //--main code--
    glm::vec2 get_position() const;

    
    //adds acce1leration to the current position, then resets acceleration to zero
    void update_position(float deltaTime);

    void add_acceleration(const glm::vec2& accel);
};
