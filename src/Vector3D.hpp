#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

/**
 * @brief 3D vector class for flight dynamics calculations.
 *
 * Supports all standard vector operations used in 6-DOF equations
 * of motion: addition, subtraction, scalar multiplication,
 * dot/cross products, normalization, and magnitude.
 */
class Vector3D {
public:
    double x, y, z;

    // Constructors
    Vector3D();
    Vector3D(double x, double y, double z);

    // Arithmetic operators
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double scalar)         const;  // scalar multiplication
    Vector3D operator/(double scalar)         const;  // scalar division
    Vector3D& operator+=(const Vector3D& other);      // compound addition

    // Vector operations
    double   dot(const Vector3D& other)  const;
    Vector3D cross(const Vector3D& other) const;

    // Magnitude & normalization
    double   magnitude()        const;
    double   magnitudeSquared() const;  // faster — avoids sqrt
    Vector3D normalize()        const;  // safe — returns zero vector if magnitude ~0

    // Utility
    bool isZero(double epsilon = 1e-10) const;
};

#endif // VECTOR3D_HPP
