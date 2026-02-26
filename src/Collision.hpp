#pragma once
#include "RigidBody.hpp"
#include "glm/glm.hpp"

struct Solver
{
    glm::vec2 gravity = glm::vec2(0.0f, -9.81f);

    void apply_gravity(rigid_body& body)
    {
        body.acceleration += gravity;
    };

    double dot_product(const glm::vec2& a, const glm::vec2& b)
    {
        return a.x * b.x + a.y * b.y;
    };
};