#include "physicsWorld.hpp"
#include <SFML/System/Vector2.hpp>
#include <iostream>

void PhysicsWorld::run() {
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
void PhysicsWorld::updateSFMLEvents() {
    while (this->window->pollEvent(sfEvent)) {
        // Close window: exit
        if (sfEvent.type == sf::Event::Closed)
        this->window->close();
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->window->close();
    }
}

// restarts and re-initializes the deltaTime
void PhysicsWorld::updateDeltaTime() {
    
    // update the deltaTime variable with the time it takes to render a frame
    dtSeconds = deltaTimeInnit.restart();
    deltaTime = dtSeconds.asSeconds();

    // outputs the Frames per second (aka, fps counter)
    std::cout << "FPS: " << 1/deltaTime << "\n";
}

// initites the window at a resolution of 800, 600
void PhysicsWorld::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode({maxWidth, maxHeight}), "Shrimp2D");
    this->window->setFramerateLimit(60);
}

// renders the bodies onto the window
void PhysicsWorld::render() {
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
void PhysicsWorld::applyForces(int i) {
    // resolving the physics of every individuL
    Physics.applyGravity(circleDrawnPosition[i]);

    // std::cout << i << " pos: " << circleDrawnPosition[i].getPosition().x << " | "
    // <<circleDrawnPosition[i].getPosition().y << " vel: " 
    // << circleDrawnPosition[i].velocity.y << " dt: " << deltaTime << std::endl;

    // checks ground collision and implements ground resolution
    if (circleDrawnPosition[i].getPosition().y +
            circleDrawnPosition[i].radius >= maxHeight - 6) {
        Physics.resolveGround(circleDrawnPosition[i], maxHeight - 6);
    }
}

void PhysicsWorld::solveCircleCollision(int i) {
    for (int j = i + 1; j < totalCircles; j++) {
        glm::vec2 bodyA = circleDrawnPosition[i].getPosition();
        glm::vec2 bodyB = circleDrawnPosition[j].getPosition();
        if (Physics.isColliding(bodyA, bodyB, CirclePosition.radius, CirclePosition.radius)) {
            Physics.resolveCollision(circleDrawnPosition[i], circleDrawnPosition[j]);
        } 
    }


}

// resolving the physics of every individual body 
void PhysicsWorld::solveWindowCollision(int i) {
    // checks ground collision and implements ground resolution
    // the minus six is to leave space for the circle to not go half way through the collision
    if (circleDrawnPosition[i].getPosition().y + circleDrawnPosition[i].radius <= maxHeight - 6) {
        Physics.resolveGround(circleDrawnPosition[i], maxHeight - 6);
    }

    if (circleDrawnPosition[i].getPosition().x + circleDrawnPosition[i].radius >= maxWidth - 6 || 
        circleDrawnPosition[i].getPosition().x + circleDrawnPosition[i].radius <=  6) {
        Physics.resolveWall(circleDrawnPosition[i], maxWidth - 6);
    }

}

void PhysicsWorld::updatePosition(int i) {
    circleDrawnPosition[i].update_position(deltaTime);
}

// initializes all of the bodies positions once
void PhysicsWorld::initCircles() {
    // initializes the total of circles desired
    totalCircles = 10;

    // initializes multiple bodies
    circleDrawn.resize(totalCircles);
    circleDrawnPosition.resize(totalCircles);

    // intitializing the circle positions along the radius of a circle
    float radius = 100.f;
    float cx = 400.f, cy = 300.f; // center of screen

    // spawns circles along a radius
    for (int i = 0; i < totalCircles; i++) {
        float angle = (2 * M_PI / totalCircles) * i;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        circleDrawn[i].setPosition(x, y);
        circleDrawnPosition[i].setPosition(glm::vec2(x, y));
    }

}

// updates all outside functions
void PhysicsWorld::update() {
    this->updateDeltaTime();

    this->updateSFMLEvents();

    for (int i = 0; i < totalCircles; i++) {

        this->applyForces(i);

        this->updatePosition(i); 

        this->solveWindowCollision(i);

        this->solveCircleCollision(i);
    }
}
    