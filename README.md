# 6-DOF Missile Simulation in C++

[![Language](https://img.shields.io/badge/C++17-%2300599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://github.com/skytruong90/6-DOF_Missile_Simulation)
[![Domain](https://img.shields.io/badge/Domain-Defense_M%26S-red?style=flat-square)](https://github.com/skytruong90/6-DOF_Missile_Simulation)
[![Simulation](https://img.shields.io/badge/Type-6DOF_Flight_Dynamics-00C8FF?style=flat-square)](https://github.com/skytruong90/6-DOF_Missile_Simulation)
[![Status](https://img.shields.io/badge/Status-Active-00FF88?style=flat-square)](https://github.com/skytruong90/6-DOF_Missile_Simulation)

## Project Overview

A C++ implementation of a Six Degrees of Freedom (6-DOF) rigid-body missile simulation, modeling translational and rotational dynamics in 3D space. Designed to demonstrate flight dynamics fundamentals applicable to tactical missile systems and defense M&S environments — covering equations of motion, aerodynamic force modeling, and modular simulation architecture.

---

## Project Structure

```bash
6-DOF_Missile_Simulation/
├── src/
│   ├── main.cpp
│   ├── Missile.cpp
│   ├── Missile.hpp
│   ├── Simulation.cpp
│   ├── Simulation.hpp
│   ├── Vector3D.cpp
│   └── Vector3D.hpp
├── CMakeLists.txt
├── .gitignore
└── README.md
```

---

## Features

- **6-DOF Equations of Motion** — Models full translational and rotational dynamics of a missile in 3D space, capturing position, velocity, orientation, and angular rates.
- **Aerodynamic Force Modeling** — Incorporates thrust, drag, and gravitational forces acting on the missile body across the flight envelope.
- **Modular Architecture** — Organized into well-defined classes (Vector3D, Missile, Simulation) for clean separation of concerns and easy extension.
- **Time-Stepped State Propagation** — Numerical integration loop updates missile state at each time step for continuous trajectory simulation.

---

## Getting Started

### Prerequisites

- **C++ Compiler** — C++11 or later (GCC, Clang, or MSVC)
- **IDE** — Visual Studio, CLion, or VS Code (optional but recommended)
- **Eigen** (optional) — Linear algebra library for matrix operations

### Installation

1. Clone the repository:

```bash
git clone https://github.com/skytruong90/6-DOF_Missile_Simulation.git
```

2. Navigate to the project directory:

```bash
cd 6DOF-Missile-Simulation
```

3. Compile the code:

```bash
g++ src/*.cpp -o missile_simulation
```

---

## Usage

1. Run the simulation:

```bash
./missile_simulation
```

2. Expected output:

The simulation propagates the missile's state over time, printing position, velocity, and orientation at each time step — providing a full trajectory trace from launch through flight.

---

## Code Explanation

### Vector3D Class

Represents a 3D vector with full support for vector arithmetic used throughout the dynamics engine.

**Key Methods:**

```cpp
Vector3D operator+(const Vector3D& other) const;   // Vector addition
Vector3D cross(const Vector3D& other) const;        // Cross product (moment/torque calculations)
double magnitude() const;                           // Euclidean norm
```

### Missile Class

Models the missile's full state — position, velocity, orientation, mass, and aerodynamic properties — and provides methods to propagate dynamics forward in time.

**Key Methods:**

```cpp
void applyForces(double dt);        // Computes and applies aerodynamic + propulsive forces
void updatePosition(double dt);     // Integrates translational equations of motion
void updateOrientation(double dt);  // Integrates rotational equations of motion
```

### Simulation Loop

The main loop initializes the missile state and iteratively propagates it forward using the applied forces and a fixed time step. Position and orientation are output at each step, producing a complete flight trajectory.

---

## Future Enhancements

- **GNC Integration** — Implement closed-loop guidance, navigation, and control algorithms to steer the missile along a predefined trajectory.
- **Quaternion Attitude Representation** — Replace Euler angles with quaternions to eliminate gimbal lock and improve rotational stability.
- **Monte Carlo Dispersion Analysis** — Add statistical analysis capability to assess performance across dispersed initial conditions and environmental uncertainties.
- **Real-Time Visualization** — Integrate 3D trajectory rendering for live flight path display during simulation execution.
- **Advanced Aerodynamics** — Incorporate Mach-dependent drag, altitude-varying atmospheric models, and angle-of-attack effects.

---

## Technical Background

This simulation is grounded in the same principles used in professional defense M&S environments:

| Concept | Implementation |
|--------|----------------|
| Translational Dynamics | Newton's 2nd Law in body/inertial frames |
| Rotational Dynamics | Euler's equations of motion |
| Force Modeling | Thrust, aerodynamic drag, gravity |
| State Propagation | Time-stepped numerical integration |
| Architecture | Object-oriented C++ with modular class design |

---

<div align="center">

[![View Repository](https://img.shields.io/badge/View_Repository-%E2%86%97-00C8FF?style=for-the-badge&labelColor=050A0F)](https://github.com/skytruong90/6-DOF_Missile_Simulation)

</div>
