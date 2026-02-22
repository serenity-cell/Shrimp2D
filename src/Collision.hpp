#include <glm/glm.hpp>
#include "RigidBody.hpp"
#include "PhysicsWorld.hpp"

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