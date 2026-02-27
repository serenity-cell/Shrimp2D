#pragma once

// SFML types used by PhysicsWorld
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <map>
#include <stack>
#include <vector>



class PhysicsWorld
{
    private:

        sf::RenderWindow *window;
        sf::Event sfEvent;

        // dt or delta time keeps track of how long it takes
        // to render a frame
        sf::Clock dtClock;
        float dt;

        // keyboard keys are int data type as the keyboard in sf
        // is defined as an enum
        std::map<std::string, int> supportedKeys;

        //initializing the window and states
        void initWindow(){};

    public:
        PhysicsWorld(){};
        virtual ~PhysicsWorld(){};

        void endApplication(){};

        // reseting dt on PhysicsWorld loop
        void updateDt(){};
        // updating SFML on PhysicsWorld loop
        void updateSFMLEvents(){};
        void update(){};
        void render(){};
        // running PhysicsWorld
        void run(){};
};