#include "PhysicsWorld.hpp"



void PhysicsWorld::step(float DeltaTime){
    for (RigidBody* obj :m_objects) {
        obj -> Force += obj -> Mass * m_gravity; //apply gravity 

        obj -> Velocity += obj -> Force / obj -> Mass * DeltaTime; // update velocity
        obj -> Position += obj -> Velocity * DeltaTime; // update position

        obj -> Force = vec2(0, 0); //resets net force at the end
    }
}