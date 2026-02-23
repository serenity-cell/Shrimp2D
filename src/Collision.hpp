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

float Distance( vec2 a, vec2 b )
{
  return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) ); // Euclidean distance between two points 
}
bool CirclevsCircleUnoptimized( SphereCollider a, SphereCollider b )
{
  float r = a.Radius + b.Radius;
  return r < Distance( a.Center, b.Center ); //checs if the distance between the cen
}
bool CirclevsCircleOptimized( SphereCollider a, SphereCollider b )
{
  float r = a.Radius + b.Radius;
  r *= r;
  return r < (a.Center.x - b.Center.x)*(a.Center.x - b.Center.x) + (a.Center.y - b.Center.y)*(a.Center.y - b.Center.y);
}

