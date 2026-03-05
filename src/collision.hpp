#pragma once
#include "rigidBody.hpp"
#include <iostream>
#include <cmath>            // for std::abs
#include <glm/geometric.hpp>

class solver
{   
    private: 
    float epsilon = 0.5f;
    
    // implements gravity upon the rigidBody
    glm::vec2 gravity = glm::vec2(0.0f, 98.1f);

    // declerations for resolveCollision function
    glm::vec2 normal;
    glm::vec2 relVel;
    float normVel;
    float j;


    public:

    void applyGravity(circleBody& body);
    
    void resolveGround(circleBody& body, float groundY);

    // math formulas used for checking collision
    float dotProduct(const glm::vec2& objectA, const glm::vec2& objectB);

    float radiiSum(const int radiusA, const int radiusB);

    glm::vec2 collisionNormal(glm::vec2 objectA, glm::vec2 objectB);

    glm::vec2 relativeVelocity(glm::vec2 velocityA, glm::vec2 velocityB);

    float normalVelocity(glm::vec2 relativeVelocity, glm::vec2 normal);

    //gets the checks collision and if true, acts upon it accordingly
    bool isColliding(const glm::vec2& objectA, const glm::vec2& objectB, const int radiusA, const int radiusB);

    float impulse(float normalVelocity, float epsilon, float massA, float massB);

    void resolveCollision (circleBody& bodyA, circleBody& bodyB);

};