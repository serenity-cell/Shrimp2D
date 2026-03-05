#pragma once
#include <glm/vec2.hpp>
#include <climits>
#include <cfloat>
#include <cassert>

class circleBody 
{   
    public:
    // basic foundation for the circle
    glm::vec2 position;
    glm::vec2 velocity = glm::vec2(0.f);
    glm::vec2 acceleration;
    float mass;

    // radius
    float radius = 6.0f;


    // construct with an initial position (defaults to origin)
    circleBody(const glm::vec2& initPos = glm::vec2(0.0f));
    // convenience overload
    circleBody(float x, float y);

    circleBody();

    //--main code--
    glm::vec2 getPosition() const;

    void setPosition(const glm::vec2& pos);

    //adds acce1leration to the current position, then resets acceleration to zero
    void update_position(float deltaTime);

    void add_acceleration(const glm::vec2& accel);
};
