#include "PhysicsWorld.hpp"


void PhysicsWorld::run()
{
    this->initWindow();
    
    // draw anything here
    sf::CircleShape circle();
    
        
    while (this->window->isOpen())
    {
       
        // update deltaTime
        this->updateDt();

        // update SFML events
        this->updateSFMLEvents();

        // update the current state
        //this->update();

        // render the current state
        this->render();
    }
}

void PhysicsWorld::updateSFMLEvents()
{   this->sfEvent;

    while (this->window->pollEvent(sfEvent))
        {
            // Close window: exit
            if (sfEvent.type == sf::Event::Closed)
                this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                this->window->close();

        }

}

void PhysicsWorld::updateDt()
{
    // update the deltaTime variable with the time it takes to render a frame
    this->deltaTime = this->dtClock.restart().asSeconds();
}

void PhysicsWorld::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Shrimp2D");
    
}

void PhysicsWorld::render()
{
    this->window->clear();
    this->window->display();
}