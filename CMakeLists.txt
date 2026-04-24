cmake_minimum_required(VERSION 3.10)
project(MissileSimulation VERSION 1.0 LANGUAGES CXX)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/Missile.cpp
    src/Simulation.cpp
    src/Vector3D.cpp
)

# Executable
add_executable(missile_simulation ${SOURCES})

# Include headers
target_include_directories(missile_simulation PRIVATE src)

# Compiler warnings
target_compile_options(missile_simulation PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -O2
)
