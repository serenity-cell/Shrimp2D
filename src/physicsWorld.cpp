#include "physicsWorld.hpp"
#include <SFML/System/Vector2.hpp>
#include <iostream>
//#include <iostream>

void physicsWorld::run() {
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
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->window->close();
    }
}

// restarts and re-initializes the deltaTime
void physicsWorld::updateDeltaTime() {
    
    // update the deltaTime variable with the time it takes to render a frame
    dtSeconds = deltaTimeInnit.restart();
    deltaTime = dtSeconds.asSeconds();

    // outputs the Frames per second (aka, fps counter)
    std::cout << "FPS: " << 1/deltaTime << "\n";
}

// initites the window at a resolution of 800, 600
void physicsWorld::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode({maxWidth, maxHeight}), "Shrimp2D");
    this->window->setFramerateLimit(60);
}

// renders the bodies onto the window
void physicsWorld::render() {
    for (int i = 0; i < totalCircles; i++) {
        circleDrawn[i].setRadius(circleDrawnPosition[i].radius);
        circleDrawn[i].setPosition(circleDrawnPosition[i].getPosition().x,
                                circleDrawnPosition[i].getPosition().y);
    }
    // renders multiple circleDrawn
    for (auto &c : circleDrawn) {
        this->window->draw(c);
    }
}

// gives each individual body its own physics
void physicsWorld::updateGravity(int i) {
    // resolving the physics of every individuL
    circleDrawnPosition[i].update_position(deltaTime);
    physics.applyGravity(circleDrawnPosition[i]);

    // std::cout << i << " pos: " << circleDrawnPosition[i].getPosition().x << " | "
    // <<circleDrawnPosition[i].getPosition().y << " vel: " 
    // << circleDrawnPosition[i].velocity.y << " dt: " << deltaTime << std::endl;

    // checks ground collision and implements ground resolution
    if (circleDrawnPosition[i].getPosition().y +
            circleDrawnPosition[i].radius >=
        maxHeight - 6) {
    physics.resolveGround(circleDrawnPosition[i], maxHeight - 6);
    }
}

void physicsWorld::updateCircleCollision(int i) {
    circleDrawnPosition[i].update_position(deltaTime);
    for (int j = i + 1; j < totalCircles; j++) {
        glm::vec2 bodyA = circleDrawnPosition[i].getPosition();
        glm::vec2 bodyB = circleDrawnPosition[j].getPosition();
        if (physics.isColliding(bodyA, bodyB, circlePosition.radius, circlePosition.radius)) {
           
        }
    }


}

// resolving the physics of every individual body 
void physicsWorld::updateWindowCollision(int i) {  
    circleDrawnPosition[i].update_position(deltaTime);
    // checks ground collision and implements ground resolution
    if (circleDrawnPosition[i].getPosition().y + circleDrawnPosition[i].radius >=
        maxHeight - 6) {
    physics.resolveGround(circleDrawnPosition[i], maxHeight - 6);
    }
}

void physicsWorld::updatePhysics(int i) {
    physics.applyGravity(circleDrawnPosition[i]);
}

// initializes all of the bodies positions once
void physicsWorld::initCircles() {
    // initializes the total of circles desired
    totalCircles = 40; // quantitiy of circles to render
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

    for (int i = 0; i < totalCircles; i++) {
        this->updateGravity(i);

        this->updateWindowCollision(i);

        this->updatePhysics(i);

        this->updateCircleCollision(i);
    }
}
    