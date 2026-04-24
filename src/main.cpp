#include "Simulation.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

/**
 * @brief 6-DOF Missile Simulation Entry Point
 *
 * Usage:
 *   ./missile_simulation                        (default parameters)
 *   ./missile_simulation <sim_time> <time_step> (custom parameters)
 *
 * Example:
 *   ./missile_simulation 60.0 0.01
 */
int main(int argc, char* argv[]) {

    // Default simulation parameters
    double simulationTime = 60.0;   // seconds
    double timeStep       = 0.01;   // seconds (10ms — high fidelity)

    // Optional command-line overrides
    if (argc == 3) {
        try {
            simulationTime = std::atof(argv[1]);
            timeStep       = std::atof(argv[2]);

            if (simulationTime <= 0.0 || timeStep <= 0.0) {
                std::cerr << "[ERROR] simulationTime and timeStep must be positive.\n";
                return 1;
            }
            if (timeStep > simulationTime) {
                std::cerr << "[ERROR] timeStep cannot exceed simulationTime.\n";
                return 1;
            }
        } catch (...) {
            std::cerr << "[ERROR] Invalid arguments. Expected: <sim_time> <time_step>\n";
            return 1;
        }
    }

    // Startup banner
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════════╗\n";
    std::cout << "  ║      6-DOF MISSILE SIMULATION  v1.0          ║\n";
    std::cout << "  ║      David Tan · Defense M&S                 ║\n";
    std::cout << "  ╠══════════════════════════════════════════════╣\n";
    std::cout << "  ║  Sim Time  : " << simulationTime << " s" << "\n";
    std::cout << "  ║  Time Step : " << timeStep       << " s" << "\n";
    std::cout << "  ║  Steps     : " << (int)(simulationTime / timeStep) << "\n";
    std::cout << "  ╚══════════════════════════════════════════════╝\n\n";

    // Run simulation
    try {
        runSimulation(simulationTime, timeStep);
    } catch (const std::exception& e) {
        std::cerr << "[FATAL] Simulation error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
