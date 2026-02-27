#include "PhysicsWorld.hpp"

void PhysicsWorld::run()
{
    while (true)
    {
        this->initWindow();
        
        // update dt
        this->updateDt();

        // update SFML events
        this->updateSFMLEvents();

        // update the current state
        this->update();

        // render the current state
        this->render();
    }
}

void PhysicsWorld::updateSFMLEvents()
{
    if (this->sfEvent.type == sf::Event::Closed)
        this->window->close();
}

void PhysicsWorld::updateDt()
{
    // update the dt variable with the time it takes to render a frame
    this->dt = this->dtClock.restart().asSeconds();
}

void PhysicsWorld::initWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shrimp2D");
    
}