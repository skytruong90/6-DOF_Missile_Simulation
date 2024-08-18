#include "Missile.hpp"

// Constructor
Missile::Missile(Vector3D pos, Vector3D vel, double mass, double drag)
    : position(pos), velocity(vel), mass(mass), dragCoefficient(drag), thrust(1000) {}

// Apply forces like thrust, drag, and gravity
void Missile::applyForces(double dt) {
    Vector3D gravity(0, 0, -9.81); // Simplified gravity force
    Vector3D drag = velocity.normalize() * (-dragCoefficient * velocity.magnitude() * velocity.magnitude());

    // Update velocity based on forces
    velocity = velocity + (gravity + drag + Vector3D(0, 0, thrust / mass)) * dt;
}

// Update the missile's position
void Missile::updatePosition(double dt) {
    position = position + velocity * dt;
}

// Update the missile's orientation (simplified)
void Missile::updateOrientation(double dt) {
    // Placeholder for future orientation logic
}

// Get the current position of the missile
Vector3D Missile::getPosition() const {
    return position;
}
