cmake_minimum_required(VERSION 3.10.0)
project(Shrimp2D VERSION 0.1.0 LANGUAGES C CXX)

# Find SFML
set(SFML_DIR "<sfml-install-path>/lib/cmake/SFML") # Optional, might be needed if CMake can't find it
# request all needed components before creating the target
find_package(SFML REQUIRED COMPONENTS audio network graphics window system)

# create executable after the package has been found
add_executable(Shrimp2D src/main.cpp src/PhysicsWorld.cpp src/RigidBody.cpp src/State.cpp)

# link SFML libraries (using imported targets and PRIVATE linkage)
# the SFML targets automatically provide include directories
target_link_libraries(Shrimp2D PUBLIC sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

include(CTest)
enable_testing()
