#include "rigidBody.hpp"
#include <cmath> // for std::abs
#include <glm/geometric.hpp>

#ifndef COLLISION_HPP
#define COLLISION_HPP
class solver {
private:
  float epsilon = 0.65f;
  // implements gravity upon the rigidBody
  glm::vec2 gravity = glm::vec2(0.0f, 98.1f);

  // penetration correction variables
  glm::vec2 difference;
  float distance;

  // declerations for resolveCollision function
  glm::vec2 normal;
  glm::vec2 relVel;
  float normVel;
  float j;

  // constants for penetration
  float slop;
  float percent;
  
public:

  void applyGravity(circleBody &body);

  // collision correction onto the borders of the window
  void resolveGround(circleBody &body, float groundY);
  void resolveWall(circleBody &body, float groundX);

  // collision formulas
  float dotProduct(const glm::vec2 &objectA, const glm::vec2 &objectB);
  float radiiSum(const float radiusA, const float radiusB);
  glm::vec2 collisionNormal(glm::vec2 objectA, glm::vec2 objectB);
  glm::vec2 relativeVelocity(glm::vec2 velocityA, glm::vec2 velocityB);
  float normalVelocity(glm::vec2 relativeVelocity, glm::vec2 normal);

  // formulas for penetration upon a circle collision
  float invSum (float invMassA, float invMassB);
  void penetrationDepth(const glm::vec2 bodyA, const glm::vec2 bodyB, float radiusA, float radiusB);
  void penetrationCorrection(const glm::vec2 bodyA, const glm::vec2 bodyB, float radiusA, float radiusB); 

  // collision checks
  bool isColliding(const glm::vec2 &objectA, const glm::vec2 &objectB, const float radiusA, const float radiusB);
  float impulse(float normalVelocity, float epsilon, float massA, float massB);
  void resolveCollision(circleBody &bodyA, circleBody &bodyB);
};

#endif