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
```bash
./missile_simulation
```
2. Expected Output:
The program will simulate the missile's movement over time and print the missile's position at each time step.

## Code Explanation

### Vector3D Class
This class represents a 3D vector and includes basic operations such as addition, subtraction, dot product, cross product, and normalization.

### Key Methods:
1. Vector3D operator+(const Vector3D& other) const;
2. Vector3D cross(const Vector3D& other) const;
3. double magnitude() const;
