#pragma once
#include <cassert>
#include <cfloat>
#include <climits>
#include <glm/vec2.hpp>

#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP
class circleBody {
public:
  // basic foundation for the circle
  glm::vec2 position = glm::vec2(0.0, 0.0);
  glm::vec2 velocity = glm::vec2(0.0, 0.0);
  glm::vec2 acceleration = glm::vec2(0.0, 0.0);
  float mass = 0.0;

  // radius
  float radius = 6.0f;

  // construct with an initial position (defaults to origin)
  circleBody(const glm::vec2 &initPos = glm::vec2(0.0, 0.0));
  // convenience overload
  circleBody(float x, float y);

  //--main code--
  glm::vec2 getPosition() const;

  void setPosition(const glm::vec2 &pos);

  // adds acce1leration to the current position, then resets acceleration to
  // zero
  void update_position(float deltaTime);

  void add_acceleration(const glm::vec2 &accel);
};
#endif
