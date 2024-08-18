#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Vector3D.hpp"

class Missile {
private:
    Vector3D position;
    Vector3D velocity;
    Vector3D orientation; // Simplified as a vector
    double mass;
    double dragCoefficient;
    double thrust;

public:
    Missile(Vector3D pos, Vector3D vel, double mass, double drag);
    void applyForces(double dt);
    void updatePosition(double dt);
    void updateOrientation(double dt);
    Vector3D getPosition() const;
};

#endif // MISSILE_HPP
