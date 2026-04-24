#include "Missile.hpp"
#include <cmath>

// Constructor
Missile::Missile(Vector3D pos, Vector3D vel, double mass, double dragCoeff)
    : position(pos),
      velocity(vel),
      orientation(0.0, 0.0, 0.0),
      angularVelocity(0.0, 0.0, 0.0),
      mass(mass),
      dragCoefficient(dragCoeff),
      thrust(5000.0),
      massFlowRate(2.0),
      burnTime(30.0),
      elapsedTime(0.0) {}

// Apply all forces: thrust, drag, gravity
void Missile::applyForces(double dt) {
    // Gravity in inertial frame (NED: +Z is down, so -Z is up)
    Vector3D gravity(0.0, 0.0, -9.81 * mass);

    // Drag opposes velocity — guard against zero velocity
    Vector3D dragForce(0.0, 0.0, 0.0);
    double speed = velocity.magnitude();
    if (speed > 1e-6) {
        double dragMag = dragCoefficient * speed * speed;
        dragForce = velocity.normalize() * (-dragMag);
    }

    // Thrust along body +X axis, rotated into inertial frame
    Vector3D thrustForce(0.0, 0.0, 0.0);
    if (elapsedTime < burnTime) {
        // Body-frame thrust direction (forward = +X)
        Vector3D bodyThrust(thrust, 0.0, 0.0);
        thrustForce = rotateBodyToInertial(bodyThrust);
        // Fuel burn — decrease mass over time
        mass -= massFlowRate * dt;
        if (mass < 10.0) mass = 10.0; // dry mass floor
    }

    // Net force → acceleration → integrate velocity
    Vector3D netForce = gravity + dragForce + thrustForce;
    Vector3D acceleration = netForce * (1.0 / mass);
    velocity = velocity + acceleration * dt;

    elapsedTime += dt;
}

// Integrate position from velocity
void Missile::updatePosition(double dt) {
    position = position + velocity * dt;
}

// Integrate orientation from angular velocity
void Missile::updateOrientation(double dt) {
    orientation = orientation + angularVelocity * dt;
    // Normalize pitch to [-PI, PI]
    const double PI = 3.14159265358979323846;
    if (orientation.y > PI)  orientation.y -= 2.0 * PI;
    if (orientation.y < -PI) orientation.y += 2.0 * PI;
}

// Rotate a body-frame vector into inertial frame
// Uses simplified Euler angles: roll (x), pitch (y), yaw (z)
Vector3D Missile::rotateBodyToInertial(const Vector3D& bodyVec) const {
    double roll  = orientation.x;
    double pitch = orientation.y;
    double yaw   = orientation.z;

    double cr = cos(roll),  sr = sin(roll);
    double cp = cos(pitch), sp = sin(pitch);
    double cy = cos(yaw),   sy = sin(yaw);

    // Rotation matrix R = Rz(yaw) * Ry(pitch) * Rx(roll)
    double x = (cy*cp) * bodyVec.x
             + (cy*sp*sr - sy*cr) * bodyVec.y
             + (cy*sp*cr + sy*sr) * bodyVec.z;

    double y = (sy*cp) * bodyVec.x
             + (sy*sp*sr + cy*cr) * bodyVec.y
             + (sy*sp*cr - cy*sr) * bodyVec.z;

    double z = (-sp) * bodyVec.x
             + (cp*sr) * bodyVec.y
             + (cp*cr) * bodyVec.z;

    return Vector3D(x, y, z);
}

// Getters
Vector3D Missile::getPosition()        const { return position; }
Vector3D Missile::getVelocity()        const { return velocity; }
Vector3D Missile::getOrientation()     const { return orientation; }
double   Missile::getMass()            const { return mass; }
double   Missile::getElapsedTime()     const { return elapsedTime; }
bool     Missile::isBurnout()          const { return elapsedTime >= burnTime; }
