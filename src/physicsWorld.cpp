#include "physicsWorld.hpp"
#include <SFML/System/Vector2.hpp>
#include <iostream>

void physicsWorld::run()
{   
    this->initWindow();
    this->initCircles();
    while (this->window->isOpen())
    {
        // update deltaTime
        this->updateDeltaTime();

        // update SFML events
        this->updateSFMLEvents();

        // update the current state
        this->update();

        this->updatePhysics();

        // render the current state
        this->window->clear();
        this->render();
        this->window->display();
    }
}

void physicsWorld::updateSFMLEvents()
{
    while (this->window->pollEvent(sfEvent))
        {
            // Close window: exit
            if (sfEvent.type == sf::Event::Closed)
                this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window->close();
        }
}

// restarts and re-initializes the deltaTime
void physicsWorld::updateDeltaTime()
{
    // update the deltaTime variable with the time it takes to render a frame
    dtSeconds= deltaTimeInnit.restart();
    deltaTime = dtSeconds.asSeconds();
}

// initites the window at a resolution of 800, 600
void physicsWorld::initWindow()
{
this->window = new sf::RenderWindow(sf::VideoMode({maxWidth, maxHeight}), "Shrimp2D");
}

// renders the shapes onto the window
void physicsWorld::render()
{  
    totalCircles = 6; // quantitiy of circles to render
    // renders multiple circleDrawn
    circleDrawn.resize(totalCircles);
    for (auto& c : circleDrawn)
    {
        this->window->draw(c);
    };
}

void physicsWorld::updatePhysics()
{
    // resolving the physics of every individuL 
    for (int i = 0; i < totalCircles; i++) 
    {

        circleDrawn[i].setRadius(circleDrawnPosition[i].radius);
        circleDrawn[i].setPosition(circleDrawnPosition[i].getPosition().x, circleDrawnPosition[i].getPosition().y);
        circleDrawnPosition[i].update_position(deltaTime);
        physics.applyGravity(circleDrawnPosition[i]);
        std::cout << "pos: " << circleDrawnPosition[i].getPosition().y << " vel: " << circleDrawnPosition[i].velocity.y << " dt: " << deltaTime << std::endl;
        
        // checks ground collision and implements ground resolution
        if (circleDrawnPosition[i].getPosition().y + circleDrawnPosition[i].radius >= maxHeight - 6)
        {
            physics.resolveGround(circleDrawnPosition[i], maxHeight - 6);
            std::cout << "rendering at: " << circleDrawnPosition[i].getPosition().y << std::endl;
        }
    }
}

void physicsWorld::initCircles()
{
    totalCircles = 6; // quantitiy of circles to render
    // renders multiple circleDrawn
    circleDrawn.resize(totalCircles);
    circleDrawnPosition.resize(totalCircles);

    for (int i = 0; i < totalCircles; i++) 
    {
        circleDrawn[i].setPosition (i * 80.f + 50.f, i * 80 + 50);
    }
}

//updates all outside functions
void physicsWorld::update()
{   
}

