#include "physicsWorld.hpp"
#include <SFML/System/Vector2.hpp>
//#include <iostream>

void physicsWorld::run() {
  totalCircles = 40; // quantitiy of circles to render
  this->initWindow();
  this->initCircles();

  // main loop for every updating factor
  while (this->window->isOpen()) {
    this->update();
    // render the current state
    this->window->clear();
    this->render();
    this->window->display();
  }
}

// updates any input made by the user
void physicsWorld::updateSFMLEvents() {
  while (this->window->pollEvent(sfEvent)) {
    // Close window: exit
    if (sfEvent.type == sf::Event::Closed)
      this->window->close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      this->window->close();
  }
}

// restarts and re-initializes the deltaTime
void physicsWorld::updateDeltaTime() {
  // update the deltaTime variable with the time it takes to render a frame
  dtSeconds = deltaTimeInnit.restart();
  deltaTime = dtSeconds.asSeconds();
}

// initites the window at a resolution of 800, 600
void physicsWorld::initWindow() {
  this->window =
      new sf::RenderWindow(sf::VideoMode({maxWidth, maxHeight}), "Shrimp2D");
}

// renders the bodies onto the window
void physicsWorld::render() {
  for (int i = 0; i < totalCircles; i++) {
    circleDrawn[i].setRadius(circleDrawnPosition[i].radius);
    circleDrawn[i].setPosition(circleDrawnPosition[i].getPosition().x,
                               circleDrawnPosition[i].getPosition().y);
  }
  // renders multiple circleDrawn
  circleDrawn.resize(totalCircles);
  for (auto &c : circleDrawn) {
    this->window->draw(c);
  };
}

// gives each individual body its own physics
void physicsWorld::updateGravity() {
  // resolving the physics of every individuL
  for (int i = 0; i < totalCircles; i++) {
    circleDrawnPosition[i].update_position(deltaTime);
    physics.applyGravity(circleDrawnPosition[i]);
    // std::cout << i << " pos: " << circleDrawnPosition[i].getPosition().x << "
    // | "<<circleDrawnPosition[i].getPosition().y << " vel: " <<
    // circleDrawnPosition[i].velocity.y << " dt: " << deltaTime << std::endl;

    // checks ground collision and implements ground resolution
    if (circleDrawnPosition[i].getPosition().y +
            circleDrawnPosition[i].radius >=
        maxHeight - 6) {
      physics.resolveGround(circleDrawnPosition[i], maxHeight - 6);
    }
  }
}

void physicsWorld::updateCollisionOnWindow() {
  // resolving the physics of every individuL
  for (int i = 0; i < totalCircles; i++) {
    circleDrawnPosition[i].update_position(deltaTime);
    physics.applyGravity(circleDrawnPosition[i]);
    // checks ground collision and implements ground resolution
    if (circleDrawnPosition[i].getPosition().y +
            circleDrawnPosition[i].radius >=
        maxHeight - 6) {
      physics.resolveGround(circleDrawnPosition[i], maxHeight - 6);
    }
  }
}

// initializes all of the bodies positions to a certain location
void physicsWorld::initCircles() {
    // initializes multiple bodies
    circleDrawn.resize(totalCircles);
    circleDrawnPosition.resize(totalCircles);

    float radius = 200.f;
    float cx = 400.f, cy = 300.f; // center of screen
    for (int i = 0; i < totalCircles; i++) {
        float angle = (2 * M_PI / totalCircles) * i;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        circleDrawn[i].setPosition(x, y);
        circleDrawnPosition[i].setPosition(glm::vec2(x, y));
    }
}

// updates all outside functions
void physicsWorld::update() {
  this->updateDeltaTime();

  this->updateSFMLEvents();

  this->updateGravity();

  this->updateCollisionOnWindow();
}