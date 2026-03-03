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
        //this->update();

        // render the current state
        this->window->clear();
        this->render();
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
}

//initites the window at a resolution of 800, 600
void physicsWorld::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({800, 600}), "Shrimp2D");
}

void physicsWorld::render()
{  
    int totalCircles = 6; // quanitiy of circles to render here

    // renders multiple 
    std::vector<sf::CircleShape> circles(totalCircles);
    for (float i = 0; i < totalCircles; i++) 
    {
        circles[i].setRadius(circleRigid.radius);
        circles[i].setPosition(circleRigid.get_position().x + 20 * i, circleRigid.get_position().y);
    }

    for (auto& c : circles) 
    {
        this->window->draw(c);
    };
}

void physicsWorld::update()
{
    circleRigid.update_position(deltaTime);
}

