#include "collision.hpp"


#pragma once
#include "rigidBody.hpp"
#include "glm/glm.hpp"
#include <cmath>          // for std::abs


void solver::applyGravity(circle& body)
{
    body.add_acceleration(gravity);
}

bool solver::isColliding(const glm::vec2& a, const glm::vec2& b, const int radiusA, const int radiusB)
{
    return radiiSum(radiusA, radiusB) >= pow(2, b.x - a.x) + pow(2, b.y - a.y); // we are chckin the radii sum to the distance 
}

float solver::dotProduct(const glm::vec2& a, const glm::vec2& b)
{
    return a.x * b.x + a.y * b.y;
}

float solver::radiiSum(const int radiusA, const int radiusB)
{
    return radiusA + radiusB;
}

glm::vec2 solver::collisionNormal(glm::vec2 objectA, glm::vec2 objectB)
{
    return glm::normalize(objectA - objectB);
}

float solver::relativeVelocity(float velocityA, float velocityB)
{
    return velocityB - velocityA;
}

glm::vec2 solver::normalVelocity(float relativeVelocity, glm::vec2 normal)
{
    return relativeVelocity * normal;
}

glm::vec2 solver::impulse(glm::vec2 normalVelocity, float epsilon, float massA, float massB)
{
    return -(1 + epsilon) * normalVelocity / (1 / massA + 1 / massB);
}

float solver::resolveCollision (circle& bodyA, circle& bodyB)
{
    
}



