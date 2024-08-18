#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

class Vector3D {
public:
    double x, y, z;

    // Constructors
    Vector3D();
    Vector3D(double x, double y, double z);

    // Operations
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    double dot(const Vector3D& other) const;
    Vector3D cross(const Vector3D& other) const;
    double magnitude() const;
    Vector3D normalize() const;
};

#endif // VECTOR3D_HPP
