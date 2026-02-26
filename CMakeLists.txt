cmake_minimum_required(VERSION 3.10.0)
project(Shrimp2D VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Shrimp2D src/main.cpp)
find_package(SFML REQUIRED audio network graphics window system)
include(CTest)
enable_testing()

