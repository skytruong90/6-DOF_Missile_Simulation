# 6-DOF Missile Simulation in C++

## Project Overview

This project is a basic 6-DOF (Six Degrees of Freedom) missile simulation written in C++. It models the movement of a missile in 3D space, incorporating fundamental aerodynamic forces and simple control logic. This simulation is designed to help you gain hands-on experience with C++ programming and deepen your understanding of missile dynamics and 6-DOF simulations.

## Project Structure
```bash
6DOF-Missile-Simulation/
├── src/
│   ├── main.cpp
│   ├── Missile.hpp
│   ├── Missile.cpp
│   ├── Vector3D.hpp
│   ├── Vector3D.cpp
│   ├── Simulation.hpp
│   ├── Simulation.cpp
├── README.md
```
## Features

6-DOF Simulation: Models translational and rotational movement of a missile in 3D space.
Aerodynamic Forces: Incorporates basic aerodynamic forces like thrust, drag, and gravity.
Modular Code: Organized into classes for easy extension and modification.

## Getting Started

### Prerequisites
C++ Compiler: Ensure you have a C++11 or later compliant compiler (e.g., GCC, Clang, MSVC).
IDE: Optional but recommended IDEs include Visual Studio, CLion, or VS Code.
### Libraries:
Eigen (optional) for linear algebra operations.

## Installation
1. Clone the Repository:
```bash
git clone https://github.com/skytruong90/6-DOF_Missile_Simulation.git
```
2. Navigate to the Project Directory:
```bash
cd 6DOF-Missile-Simulation
```
3. Compile the Code:
```bash
g++ src/*.cpp -o missile_simulation
```

## Usage
1. Run the Simulation:
