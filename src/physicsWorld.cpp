#include "physicsWorld.hpp"
#include "rigidBody.hpp"


void physicsWorld::run()
{
    this->initWindow();
    
    circle CircleBody;
    // draw anything here
    
    
        
    while (this->window->isOpen())
    {
        static sf::CircleShape circle(CircleBody.radius);
        //circle.setPosition();
        // update deltaTime
        this->updateDeltaTime();

        // update SFML events
        this->updateSFMLEvents();

        // update the current state
        //this->update();

        // render the current state
        this->window->clear();
        this->window->draw(circle);
        this->window->display();
    }
}

void physicsWorld::updateSFMLEvents()
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

void physicsWorld::updateDeltaTime()
{
    // update the deltaTime variable with the time it takes to render a frame
    this->deltaTime = this->dtClock.restart().asSeconds();
}

void physicsWorld::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Shrimp2D");
    
}

void physicsWorld::render()
{
}