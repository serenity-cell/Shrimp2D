#pragma once
#include "RigidBody.hpp"
#include "glm/glm.hpp"

struct Solver
{
    glm::vec2 gravity = glm::vec2(0.0f, 9.81f);
    void Update(float deltaTime)
    {
        // Update physics simulation
    }

    void apply_gravity()
    {
        
    };
};