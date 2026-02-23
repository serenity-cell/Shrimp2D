#include "Collision.hpp"
float Collision::distance(Point a, Point b) {
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) ); // Euclidean distance between two points 

};

bool CirclevsCircleUnoptimized( SphereCollider a, SphereCollider b ){
    RadiusSum = a.Radius + b.Radius;
    return r < Distance( a.Center, b.Center ); //checks if the distance between the center of each object
};

bool CirclevsCircleOptimized( SphereCollider a, SphereCollider b ){
    RadiusSum = a.Radius + b.Radius;
    RadiusSum *= RadiusSum; //squaring the radius to avoid the costly square root operation in the distance calculation
    return r < (a.Center.x - b.Center.x)*(a.Center.x - b.Center.x) + (a.Center.y - b.Center.y)*(a.Center.y - b.Center.y);
};

double RelativeVelocity( vec2 vA, vec2 vB,){
    return RelativeVelocity += vB - vA
};
double DotProduct (vec2 a, vec2 b){
    
};