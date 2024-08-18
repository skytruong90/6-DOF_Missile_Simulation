#include "Simulation.hpp"
#include <iostream>

// Run the simulation
void runSimulation(double simulationTime, double timeStep) {
    Missile missile(Vector3D(0, 0, 0), Vector3D(0, 0, 0), 1000, 0.5);

    for (double t = 0; t < simulationTime; t += timeStep) {
        missile.applyForces(timeStep);
        missile.updatePosition(timeStep);
        missile.updateOrientation(timeStep);

        Vector3D pos = missile.getPosition();
        std::cout << "Time: " << t << " Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")\n";
    }
}
