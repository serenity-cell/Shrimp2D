#include <glm/glm.hpp>
#include "RigidBody.hpp"
#include "PhysicsWorld.hpp"
#ifndef COLLISION_HPP
#define COLLISION_HPP
enum ColliderType {
    CIRCLE,
    PLANE
};

struct Collider {
    ColliderType Type;
};

struct SphereCollider : Collider {
    vec2 Center;
    float Radius;
};

struct PlaneCollider : Collider {
    vec2 Normal;
    float Distance; // distance from the origin
};

double Distance( vec2 a, vec2 b ){};
bool CirclevsCircleUnoptimized( SphereCollider a, SphereCollider b ) {
    double RadiusSum
};
bool CirclevsCircleOptimized( SphereCollider a, SphereCollider b ){
    double RadiusSum
};
double RelativeVelocity( vec2 vA, vec2 vB vec2 n){
    double VelocitySum
};

double DotProduct (vec2 a, vec2 b);

// V^{AB} \cdot n = (V^B - V^A)

//V_1 = \begin{bmatrix}x_1 \\y_1\end{bmatrix}, V_2 = \begin{bmatrix}x_2 \\y_2\end{bmatrix} \\ V_1 \cdot V_2 = x_1 * x_2 + y_2 * y_2 


#endif