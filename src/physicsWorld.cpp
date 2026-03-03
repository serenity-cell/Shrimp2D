#include "physicsWorld.hpp"


void physicsWorld::run()
{
    this->initWindow();
    while (this->window->isOpen())
    {  
        std::vector<sf::CircleShape> circles(3);
        for (int i = 0; i < 3; i++) 
        {

            circles[i].setRadius(circleRigid.radius);
            circles[i].setPosition(100 * i + 100, 100);
        }

        // update deltaTime
        this->updateDeltaTime();

        // update SFML events
        this->updateSFMLEvents();

        // update the current state
        //this->update();

        // render the current state
        this->window->clear();
        for (auto& c : circles) 
        {
            this->window->draw(c);
        };
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
    sf::Time dt = deltaTimeInnit.restart();
    float deltaTime = dt.asMilliseconds();
    //update position with the deltatime
    circleRigid.update_position(deltaTime);
}

void physicsWorld::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Shrimp2D");
    
}

void physicsWorld::render()
{
   std::vector<sf::CircleShape> circles(4);
    for (int i = 0; i < 4; i++) 
    {
        circles[i].setRadius(circleRigid.radius);
        circles[i].setPosition(100 * i + 100, 100);
    }

    
}