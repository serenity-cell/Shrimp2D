#include "rigidBody.hpp"
#include <glm/ext/vector_float2.hpp>

circleBody::circleBody(const glm::vec2 &initPos) : position(initPos) {}

// construct with an initial position (defaults to origin)

// convenience overload
circleBody::circleBody(float x, float y) : circleBody(glm::vec2(x, y)) {}

//--main code--
glm::vec2 circleBody::getPosition() const { return position; }

void circleBody::setPosition(const glm::vec2 &pos) { position = pos; }

void circleBody::add_acceleration(const glm::vec2 &accel) {
  acceleration += accel;
}

// updates velocity by acceleration, then updates position by velocity, and resets acceleration to zero
void circleBody::update_position(float deltaTime) {
  velocity += acceleration * deltaTime;
  position += velocity * deltaTime;

  acceleration = {};
}
