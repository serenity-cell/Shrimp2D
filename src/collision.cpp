#include "collision.hpp"

void solver::applyGravity(circleBody &body) { body.add_acceleration(gravity); }

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

bool solver::isColliding(const glm::vec2 &a, const glm::vec2 &b, float radiusA, float radiusB) {
  float sumX = b.x - a.x;
  float sumY = b.y - a.y;
  float r = radiiSum(radiusA, radiusB);
  return r * r >= sumX * sumX + sumY * sumY;
}

float solver::dotProduct(const glm::vec2 &a, const glm::vec2 &b) {
  return a.x * b.x + a.y * b.y;
}

float solver::radiiSum(float radiusA, float radiusB) {
  return radiusA + radiusB;
}

// use this two first
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

float solver::impulse(float normalVelocity, float epsilon, float massA,
                      float massB) {
  return -(1 + epsilon) * normalVelocity / (1 / massA + 1 / massB);
}

// collision check used between two circles (ONLY THIS NEEDS TO BE USED)
void solver::resolveCollision(circleBody &bodyA, circleBody &bodyB) {
    normal = collisionNormal(bodyA.position, bodyB.position);
    relVel = relativeVelocity(bodyA.velocity, bodyB.velocity);
    float normVel = normalVelocity(relVel, normal);

    // if (normVel > 0)
    // return;

    j = impulse(normVel, epsilon, bodyA.mass, bodyB.mass);
    bodyA.velocity -= (j / bodyA.mass) * normal;
    bodyB.velocity += (j / bodyB.mass) * normal;
}
