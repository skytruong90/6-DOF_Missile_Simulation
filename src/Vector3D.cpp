#include "Vector3D.hpp"
#include <cmath>

// Default constructor
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// Parameterized constructor
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

// Vector addition
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

// Vector subtraction
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

// Dot product
double Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Cross product
Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// Magnitude of the vector
double Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalize the vector
Vector3D Vector3D::normalize() const {
    double mag = magnitude();
    return Vector3D(x / mag, y / mag, z / mag);
}
