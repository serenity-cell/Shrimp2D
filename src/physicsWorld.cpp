#include "physicsWorld.hpp"


void physicsWorld::run()
{
    this->initWindow();
    while (this->window->isOpen())
    {
        // update deltaTime
        this->updateDeltaTime();

        // update SFML events
        this->updateSFMLEvents();

        // update the current state
        this->update();

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
this->window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Shrimp2D");
}

// renders the shapes onto the window
void physicsWorld::render()
{  

    totalCircles = 6; // quantitiy of circles to render

    // renders multiple circleDrawn
    circleDrawn.resize(totalCircles);
    for (int i = 0; i < totalCircles; i++) 
    {
        circleDrawn[i].setRadius(circlePosition.radius);
        circleDrawn[i].setPosition(circlePosition.getPosition().x + 60.f * i, circlePosition.getPosition().y);
    }

    for (auto& c : circleDrawn) 
    {
        this->window->draw(c);
    };
}

//updates all outside functions
void physicsWorld::update()
{   
    //updates the physics part of the circle/s
    circlePosition.update_position(deltaTime);
    physics.applyGravity(circlePosition);
    std::cout << "pos: " << circlePosition.getPosition().y << " vel: " << circlePosition.velocity.y << " dt: " << deltaTime << std::endl;
    
    // checks ground collision and implements ground resolution
    if (circlePosition.getPosition().y + circlePosition.radius >= 590.f)
    {
        physics.resolveGround(circlePosition, 590.0f);
        std::cout << "rendering at: " << circlePosition.getPosition().y << std::endl;
    }
    
}

