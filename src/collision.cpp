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
    float sumX = b.x - a.x;
    float sumY = b.y - a.y;
    float r = radiiSum(radiusA, radiusB);
    return r * r >= sumX*sumX + sumY*sumY; // we are chckin the radii sum to the distance 
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

glm::vec2 solver::relativeVelocity(glm::vec2 velocityA, glm::vec2 velocityB)
{
    return velocityB - velocityA;
}

float solver::normalVelocity(glm::vec2 relativeVelocity, glm::vec2 normal)
{
    return glm::dot(relativeVelocity, normal);
}

float solver::impulse(float normalVelocity, float epsilon, float massA, float massB)
{
    return -(1 + epsilon) * normalVelocity / (1 / massA + 1 / massB);
}

void solver::resolveCollision (circle& bodyA, circle& bodyB)
{
    glm::vec2 normal = collisionNormal(bodyA.position, bodyB.position);
    glm::vec2 relVel = relativeVelocity(bodyA.velocity, bodyB.velocity);
    float normVel = normalVelocity(relVel, normal);

    if (normVel > 0) return; // already separating

    float j = impulse(normVel, epsilon, bodyA.mass, bodyB.mass);
    bodyA.velocity -= (j / bodyA.mass) * normal;
    bodyB.velocity += (j / bodyB.mass) * normal;
}



