#pragma once
#include "rigidBody.hpp"
#include "collision.hpp"

// SFML types used by physicsWorld
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

//  extra libraries
#include <map>
#include <vector>


#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP
class physicsWorld
{
    protected:

        sf::RenderWindow* window;
        sf::Event sfEvent;

        // dt or delta time keeps track of how long it takes
        // to render a frame
        sf::Clock deltaTimeInnit;
        sf::Time dtSeconds;
        float deltaTime = 0.f;

        // keyboard keys are int data type as the keyboard in sf
        // is defined as an enum
        std::map<std::string, int> supportedKeys;

        //initializing the window and states
        void initWindow();

        circleBody circlePosition = circleBody(0.f, 0.f);
        solver physics;
        static sf::CircleShape circle;

        

    public:

        int totalCircles; // quantitiy of circles to render
        // renders multiple circles
        std::vector<sf::CircleShape> circleDrawn;

        //PhysicsWorld();
        //virtual ~PhysicsWorld();

        //void endApplication();

        // reseting dt on PhysicsWorld loop
        void updateDeltaTime();
        // updating SFML on PhysicsWorld loop
        void updateSFMLEvents();
        void update();
        void render();
        // running PhysicsWorld
        void run();
};

#endif