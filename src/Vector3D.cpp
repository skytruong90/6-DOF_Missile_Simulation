#include "Vector3D.hpp"
#include <cmath>
#include <stdexcept>

// Default constructor
Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0) {}

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

// Scalar multiplication (vector * scalar)
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

// Scalar division (vector / scalar)
Vector3D Vector3D::operator/(double scalar) const {
    if (std::abs(scalar) < 1e-10)
        throw std::runtime_error("Vector3D: division by zero");
    return Vector3D(x / scalar, y / scalar, z / scalar);
}

// Compound addition
Vector3D& Vector3D::operator+=(const Vector3D& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
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

// Magnitude (Euclidean norm)
double Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Normalize — returns zero vector if magnitude is zero (safe for drag calculation)
Vector3D Vector3D::normalize() const {
    double mag = magnitude();
    if (mag < 1e-10)
        return Vector3D(0.0, 0.0, 0.0);
    return Vector3D(x / mag, y / mag, z / mag);
}

// Squared magnitude — avoids sqrt when only comparing magnitudes
double Vector3D::magnitudeSquared() const {
    return x * x + y * y + z * z;
}

// Check if vector is approximately zero
bool Vector3D::isZero(double epsilon) const {
    return magnitudeSquared() < epsilon * epsilon;
}
