#pragma once
#include "RigidBody.hpp"
#include "glm/glm.hpp"
#include <cmath>          // for std::abs

struct Solver
{
    glm::vec2 gravity = glm::vec2(0.0f, -9.81f);

    void apply_gravity(rigid_body& body){
        body.add_acceleration(gravity);
    };

    float dot_product(const glm::vec2& a, const glm::vec2& b){
        return a.x * b.x + a.y * b.y;
    };

    glm::vec2 collide_line(glm::vec2 line, glm::vec2 normal, circle& circle, rigid_body& body){
        const float distance = dot_product(line - body.get_position_current(), normal);
        // only resolve if the circle is on the normal-facing side and within radius
        if (distance > 0.0f && distance < circle.radius) {
            const float penetration = circle.radius - distance;
            return normal * penetration;
        }
        return glm::vec2(0.0f);
    }

};