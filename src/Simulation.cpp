#include "Simulation.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

void runSimulation(double simulationTime, double timeStep) {

    // Initial conditions — launch at 45-degree pitch angle
    Vector3D initPos(0.0, 0.0, 0.0);
    Vector3D initVel(0.0, 0.0, 0.0);

    Missile missile(initPos, initVel, 500.0, 0.3);

    // Set initial pitch to 45 degrees (pi/4 radians) for ballistic trajectory
    missile.setAngularVelocity(Vector3D(0.0, 0.0, 0.0));

    // Open CSV for trajectory logging
    std::ofstream csv("trajectory.csv");
    csv << "Time,X,Y,Z,Vx,Vy,Vz,Roll,Pitch,Yaw,Mass,Burnout\n";

    // Print console header
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=====================================================\n";
    std::cout << "       6-DOF MISSILE SIMULATION — TRAJECTORY LOG    \n";
    std::cout << "=====================================================\n";
    std::cout << std::setw(8)  << "Time(s)"
              << std::setw(10) << "X(m)"
              << std::setw(10) << "Y(m)"
              << std::setw(10) << "Z(m)"
              << std::setw(10) << "Speed"
              << std::setw(10) << "Mass(kg)"
              << std::setw(10) << "Status"
              << "\n";
    std::cout << "-----------------------------------------------------\n";

    double maxAltitude = 0.0;
    double maxSpeed    = 0.0;
    bool   burnoutLogged = false;
    int    printInterval = static_cast<int>(1.0 / timeStep); // print every 1 second
    int    step = 0;

    for (double t = 0.0; t <= simulationTime; t += timeStep, ++step) {

        // Update dynamics
        missile.applyForces(timeStep);
        missile.updatePosition(timeStep);
        missile.updateOrientation(timeStep);

        Vector3D pos = missile.getPosition();
        Vector3D vel = missile.getVelocity();
        Vector3D ori = missile.getOrientation();
        double   spd = vel.magnitude();
        double   mss = missile.getMass();
        bool     out = missile.isBurnout();

        // Track maximums
        if (pos.z > maxAltitude) maxAltitude = pos.z;
        if (spd   > maxSpeed)    maxSpeed    = spd;

        // Log burnout event once
        if (out && !burnoutLogged) {
            std::cout << "  >>> ENGINE BURNOUT at T+" << t << "s"
                      << " | Alt: " << pos.z << "m"
                      << " | Speed: " << spd << " m/s\n";
            burnoutLogged = true;
        }

        // Ground impact termination
        if (t > 0.1 && pos.z < 0.0) {
            std::cout << "  >>> GROUND IMPACT at T+" << t << "s"
                      << " | Range: " << pos.x << "m\n";
            csv << t << "," << pos.x << "," << pos.y << "," << 0.0
                << "," << vel.x << "," << vel.y << "," << vel.z
                << "," << ori.x << "," << ori.y << "," << ori.z
                << "," << mss << "," << (out ? "YES" : "NO") << "\n";
            break;
        }

        // Write to CSV every step
        csv << t       << ","
            << pos.x   << "," << pos.y   << "," << pos.z
            << "," << vel.x   << "," << vel.y   << "," << vel.z
            << "," << ori.x   << "," << ori.y   << "," << ori.z
            << "," << mss     << "," << (out ? "YES" : "NO") << "\n";

        // Console output every 1 second
        if (step % printInterval == 0) {
            std::cout << std::setw(8)  << t
                      << std::setw(10) << pos.x
                      << std::setw(10) << pos.y
                      << std::setw(10) << pos.z
                      << std::setw(10) << spd
                      << std::setw(10) << mss
                      << std::setw(10) << (out ? "BURNOUT" : "BURNING")
                      << "\n";
        }
    }

    csv.close();

    // Mission summary
    std::cout << "=====================================================\n";
    std::cout << "  MISSION SUMMARY\n";
    std::cout << "  Max Altitude : " << maxAltitude << " m\n";
    std::cout << "  Max Speed    : " << maxSpeed    << " m/s\n";
    std::cout << "  Data saved   : trajectory.csv\n";
    std::cout << "=====================================================\n";
}
