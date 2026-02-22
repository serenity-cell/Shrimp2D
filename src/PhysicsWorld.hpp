#include <glm/glm.hpp>
#include "RigidBody.hpp"
#include <vector>
using namespace glm;


class PhysicsWorld{
    private:
        std::vector<RigidBody*>m_objects;
        vec2 m_gravity = vec2(0, -9.18f);

    public:
        void add_object(RigidBody* body) {/* ... */};
        void remove_object(RigidBody* body) {/* ... */};

        void step (float DeltaTime) {}

};
