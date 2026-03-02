#pragma once
#include "rigidBody.hpp"
#include "glm/glm.hpp"
#include <cmath>          // for std::abs

class solver
{
    // implements gravity upon the rigidBody
    glm::vec2 gravity = glm::vec2(0.0f, -9.81f);
    void applyGravity(circle& body);
    
    // math formulas used for checking collision
    float dotProduct(const glm::vec2& a, const glm::vec2& b);
    float radiiSum(const int radiusA, const int radiusB);
    glm::vec2 collisionNormal(glm::vec2 objectA, glm::vec2 objectB);
    float relativeVelocity(float velocityA, float velocityB);
    glm::vec2 normalVelocity(float relativeVelocity, glm::vec2 normal);

    //gets the checks collision and if true, acts upon it accordingly
    bool isColliding(const glm::vec2& a, const glm::vec2& b, const int radiusA, const int radiusB);
    glm::vec2 impulse(glm::vec2 normalVelocity, float epsilon, float massA, float massB);
    float resolveCollision (circle& body, glm::vec2 objectA, glm::vec2 objectB);

};