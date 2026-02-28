#pragma once
#include "rigidBody.hpp"
#include "glm/glm.hpp"
#include <cmath>          // for std::abs

struct solver
{
    glm::vec2 gravity = glm::vec2(0.0f, -9.81f);

    bool isColliding(const glm::vec2& a, const glm::vec2& b, const int radiusA, const int radiusB)
    {
        return radiiSum(radiusA, radiusB) >= dotProduct(a, b);
    }

    void applyGravity(circle& body)
    {
        body.add_acceleration(gravity);
    }

    float dotProduct(const glm::vec2& a, const glm::vec2& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    float radiiSum(const int radiusA, const int radiusB)
    {
        return pow(2, (radiusA + radiusB));
    }

    glm::vec2 collisionNormal(glm::vec2 objectA, glm::vec2 objectB)
    {
        return (objectA - objectB) / abs(objectA - objectB);
    }

    float relativeVelocity(float velocityA, float velocityB)
    {
        return velocityB - velocityA;
    }

    glm::vec2 normalVelocity(float relativeVelocity, glm::vec2 normal)
    {
        return relativeVelocity * normal;
    }

    glm::vec2 impulse(glm::vec2 normalVelocity, float mass, float epsilon)
    {
        
    }

    void resolveCollision (circle& body, glm::vec2 objectA, glm::vec2 objectB);

};