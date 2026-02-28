#pragma once
#include "glm/glm.hpp"

class circle
{   
    private:
    glm::vec2 position_current;
    glm::vec2 position_previous;
    glm::vec2 acceleration;
    

    public:
    float radius = 10.0;
    // construct with an initial position (defaults to origin)
    circle(const glm::vec2& initPos);
    // convenience overload
    circle(float x, float y);

    circle();

    //--main code--
    glm::vec2 get_position_current() const;

    
    //adds acce1leration to the current position, then resets acceleration to zero
    void update_position(float deltaTime);

    void add_acceleration(const glm::vec2& accel);
};
