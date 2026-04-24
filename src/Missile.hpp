#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Vector3D.hpp"

class Missile {
private:
    // Translational state
    Vector3D position;
    Vector3D velocity;

    // Rotational state
    Vector3D orientation;       // Euler angles: roll (x), pitch (y), yaw (z) in radians
    Vector3D angularVelocity;   // Angular rates in rad/s

    // Physical properties
    double mass;                // Current mass (decreases as fuel burns)
    double dragCoefficient;     // Aerodynamic drag coefficient
    double thrust;              // Thrust force magnitude (Newtons)
    double massFlowRate;        // Fuel burn rate (kg/s)
    double burnTime;            // Total engine burn duration (seconds)
    double elapsedTime;         // Simulation time elapsed (seconds)

    // Internal helper
    Vector3D rotateBodyToInertial(const Vector3D& bodyVec) const;

public:
    // Constructor
    Missile(Vector3D pos, Vector3D vel, double mass, double dragCoeff);

    // Dynamics
    void applyForces(double dt);
    void updatePosition(double dt);
    void updateOrientation(double dt);

    // Setters
    void setAngularVelocity(const Vector3D& angVel) { angularVelocity = angVel; }
    void setThrust(double t)                        { thrust = t; }
    void setBurnTime(double bt)                     { burnTime = bt; }
    void setMassFlowRate(double mfr)                { massFlowRate = mfr; }

    // Getters
    Vector3D getPosition()    const;
    Vector3D getVelocity()    const;
    Vector3D getOrientation() const;
    double   getMass()        const;
    double   getElapsedTime() const;
    bool     isBurnout()      const;
};

#endif // MISSILE_HPP
