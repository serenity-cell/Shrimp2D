#pragma once
#include "rigidBody.hpp"
#include "collision.hpp"

// SFML types used by physicsWorld
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#include <iostream>
#include <map>
#include <stack>
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
        float deltaTime;

        // keyboard keys are int data type as the keyboard in sf
        // is defined as an enum
        std::map<std::string, int> supportedKeys;

        //initializing the window and states
        void initWindow();
        circleBody circleRigid;
        solver Physics;
        static sf::CircleShape circle;


    public:
        
        
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