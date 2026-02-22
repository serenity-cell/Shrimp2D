#include <glm/glm.hpp>
using namespace glm;

struct RigidBody {
    vec2 Position; // (x, y)
    vec2 Velocity; // (x.velocity, y.velocity)
    vec2 Force;
    float Mass;
};
