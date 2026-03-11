#include "collision.hpp"
#include <cmath>

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
  // Normal points from A -> B (so impulse pushes them apart with current sign convention)
  return glm::normalize(objectB - objectA);
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

void solver::penetrationCorrection(circleBody &bodyA, circleBody &bodyB) {
  // Simple positional correction (prevents sinking/merging).
  // Based on "slop + percent" style correction:
  //   correction = max(penetration - slop, 0) / (invMassA + invMassB) * percent * normal
  constexpr float percent = 0.8f; // 0..1 (higher = more aggressive separation)
  constexpr float slop = 0.01f;   // small overlap allowed (prevents jitter)

  const glm::vec2 delta = bodyB.position - bodyA.position;
  const float dist2 = glm::dot(delta, delta);
  if (dist2 <= 0.0f) {
    return;
  }

  const float dist = std::sqrt(dist2);
  const float penetration = (bodyA.radius + bodyB.radius) - dist;
  if (penetration <= 0.0f) {
    return;
  }

  const float invMassA = (bodyA.mass > 0.0f) ? (1.0f / bodyA.mass) : 0.0f;
  const float invMassB = (bodyB.mass > 0.0f) ? (1.0f / bodyB.mass) : 0.0f;
  const float invMassSum = invMassA + invMassB;
  if (invMassSum <= 0.0f) {
    return;
  }

  const glm::vec2 n = delta / dist; // A -> B
  const float correctionMag = (std::max(penetration - slop, 0.0f) / invMassSum) * percent;
  const glm::vec2 correction = correctionMag * n;

  bodyA.position -= correction * invMassA;
  bodyB.position += correction * invMassB;
}

// collision check used between two circles (ONLY THIS NEEDS TO BE USED)
void solver::resolveCollision(circleBody &bodyA, circleBody &bodyB) {
    normal = collisionNormal(bodyA.position, bodyB.position);
    relVel = relativeVelocity(bodyA.velocity, bodyB.velocity);
    float normVel = normalVelocity(relVel, normal);

    // Always fix overlap, even if they're already separating.
    penetrationCorrection(bodyA, bodyB);

    // If separating, don't apply impulse (but overlap is already corrected above).
    if (normVel > 0) {
      return;
    }

    // the impulse effect on both colliding bodies
    j = impulse(normVel, epsilon, bodyA.mass, bodyB.mass);
    bodyA.velocity -= (j / bodyA.mass) * normal;
    bodyB.velocity += (j / bodyB.mass) * normal;
}
