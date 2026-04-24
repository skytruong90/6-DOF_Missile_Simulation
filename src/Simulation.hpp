#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Missile.hpp"

/**
 * @brief Runs the 6-DOF missile simulation.
 *
 * @param simulationTime  Total duration of the simulation in seconds.
 * @param timeStep        Integration time step in seconds (recommended: 0.01).
 *
 * Outputs trajectory data to console and saves full flight log to trajectory.csv.
 */
void runSimulation(double simulationTime, double timeStep);

#endif // SIMULATION_HPP
