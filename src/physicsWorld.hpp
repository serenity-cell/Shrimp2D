#include "collision.hpp"
#include "rigidBody.hpp"

// SFML types used by physicsWorld
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// extra libraries
#include <map>
#include <vector>

#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP
class physicsWorld {
protected:
  sf::RenderWindow *window;
  sf::Event sfEvent;

  // dt or delta time keeps track of how long it takes
  // to render a frame
  sf::Clock deltaTimeInnit;
  sf::Time dtSeconds;
  float deltaTime = 0.f;
  std::map<std::string, int> supportedKeys;

  // initializing the window and states
  void initWindow();

  circleBody circlePosition = circleBody(0.0, 0.0);
  solver physics;
  static sf::CircleShape circle;

  const unsigned int maxWidth = 800;
  const unsigned int maxHeight = 600;

public:
  int totalCircles; // quantitiy of circles to render
  // renders multiple circles
  std::vector<sf::CircleShape> circleDrawn;
  std::vector<circleBody> circleDrawnPosition;

  void initCircles();
  void updateGravity();
  void updateWindowCollision();
  void updateCircleCollision();
  void checkCollision();
  // reseting dt on PhysicsWorld loop
  void updateDeltaTime();
  // updating SFML on PhysicsWorld loop
  void updateSFMLEvents();
  void update();
  void render();
  // running PhysicsWorld
  void run();
};

#endif