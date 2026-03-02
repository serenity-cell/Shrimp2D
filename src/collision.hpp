#pragma once
#include "rigidBody.hpp"
#include "glm/glm.hpp"
#include <cmath>          // for std::abs

class solver
{   
    private: 
    float epsilon = 1.0f;
    // implements gravity upon the rigidBody
    glm::vec2 gravity = glm::vec2(0.0f, -9.81f);


    public:

    void applyGravity(circle& body);
    
    // math formulas used for checking collision
    float dotProduct(const glm::vec2& objectA, const glm::vec2& objectB);

    float radiiSum(const int radiusA, const int radiusB);

    glm::vec2 collisionNormal(glm::vec2 objectA, glm::vec2 objectB);

    glm::vec2 relativeVelocity(glm::vec2 velocityA, glm::vec2 velocityB);

    float normalVelocity(glm::vec2 relativeVelocity, glm::vec2 normal);

    //gets the checks collision and if true, acts upon it accordingly
    bool isColliding(const glm::vec2& objectA, const glm::vec2& objectB, const int radiusA, const int radiusB);

    float impulse(float normalVelocity, float epsilon, float massA, float massB);

    void resolveCollision (circle& bodyA, circle& bodyB);

};