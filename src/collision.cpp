#include "collision.hpp"
#include <cmath>

float slop = 0 ;

void solver::applyGravity(circleBody &body) {
  body.add_acceleration(gravity); 
}

// collision check and resolution on ground
void solver::resolveGround(circleBody &body, float groundY) {
  if (body.position.y + body.radius >= groundY) {
    body.position.y = groundY - body.radius;
    body.velocity.y *= -epsilon;
  }
}

void solver::resolveWall(circleBody &body, float groundX) {
  if (body.position.x + body.radius >= groundX) {
    body.position.x = groundX - body.radius;
    body.velocity.x *= -epsilon;
  }
  if (body.position.x + body.radius <= 6.0) {
    body.position.x = 6.0 - body.radius;
    body.velocity.x *= -epsilon;
  }
}



bool solver::isColliding(const glm::vec2 &a, const glm::vec2 &b, const float radiusA, const float radiusB) {
  sumX = b.x - a.x;
  sumY = b.y - a.y;
  radius_sum = radiiSum(radiusA, radiusB);
  return radius_sum * radius_sum >= sumX * sumX + sumY * sumY;
}

float solver::checkDistance(const glm::vec2 &objectA, const glm::vec2 &objectB,  float radiusA,  float radiusB) {
  sumX = objectB.x - objectA.x;
  sumY = objectB.y - objectA.y;
  return std::sqrt(sumX * sumX + sumY * sumY);
}



float solver::dotProduct(const glm::vec2 &a, const glm::vec2 &b) {
  return a.x * b.x + a.y * b.y;
}

float solver::radiiSum(float radiusA, float radiusB) {
  return radiusA + radiusB;
}

glm::vec2 solver::collisionNormal(glm::vec2 objectA, glm::vec2 objectB) {
  return glm::normalize(objectA - objectB);
}

glm::vec2 solver::relativeVelocity(glm::vec2 velocityA, glm::vec2 velocityB) {
  return velocityB - velocityA;
}

// input returns into noremalVel
float solver::normalVelocity(glm::vec2 relativeVelocity, glm::vec2 normal) {
  return glm::dot(relativeVelocity, normal);
}

float solver::impulse(float normalVelocity, float epsilon, float massA, float massB) {
  return -(1 + epsilon) * normalVelocity / (1 / massA + 1 / massB);
}

// collision check used between two circles (ONLY THIS NEEDS TO BE USED)
void solver::resolveCollision(circleBody &bodyA, circleBody &bodyB) {
    normal = collisionNormal(bodyA.position, bodyB.position);
    relVel = relativeVelocity(bodyA.velocity, bodyB.velocity);
    float normVel = normalVelocity(relVel, normal);

    
    // the penetration correction on both colliding bodies
     if (normVel > 0) {  
     return;
     }

    // the impulse effect on both colliding bodies
    j = impulse(normVel, epsilon, bodyA.mass, bodyB.mass);
    bodyA.velocity -= (j / bodyA.mass) * normal;
    bodyB.velocity += (j / bodyB.mass) * normal;
}
