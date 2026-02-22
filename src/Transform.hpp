#include <glm/glm.hpp>
using namespace glm;


struct CollisionPoints{
    vec2 a; //furthest point of a into b 
    vec2 b; // firthest point of b into a
    vec2 normalize;
    float depth; // how much they are penetrating each other
    bool is_colliding;

};

struct Transform {
    vec2 position;
    vec2 rotation;
    vec2 scale;
};