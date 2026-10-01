#include "vector.h"
#include <cmath>
#include <stdexcept>

Vector::Vector(double x1_, double y1_, double z1_,
    double x2_, double y2_, double z2_)
    : x1(x1_), y1(y1_), z1(z1_), x2(x2_), y2(y2_), z2(z2_) {
}

double Vector::getX1() const { return x1; }
double Vector::getY1() const { return y1; }
double Vector::getZ1() const { return z1; }
double Vector::getX2() const { return x2; }
double Vector::getY2() const { return y2; }
double Vector::getZ2() const { return z2; }

void Vector::setX1(double v) { x1 = v; }
void Vector::setY1(double v) { y1 = v; }
void Vector::setZ1(double v) { z1 = v; }
void Vector::setX2(double v) { x2 = v; }
void Vector::setY2(double v) { y2 = v; }
void Vector::setZ2(double v) { z2 = v; }

double Vector::getDX() const { return x2 - x1; }
double Vector::getDY() const { return y2 - y1; }
double Vector::getDZ() const { return z2 - z1; }

double Vector::length() const {
    double dx = getDX(), dy = getDY(), dz = getDZ();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// ===== Сложение: покоординатно по точкам =====
Vector Vector::operator+(const Vector& other) const {
    return Vector(x1 + other.x1, y1 + other.y1, z1 + other.z1,
        x2 + other.x2, y2 + other.y2, z2 + other.z2);
}

Vector& Vector::operator+=(const Vector& other) {
    x1 += other.x1; y1 += other.y1; z1 += other.z1;
    x2 += other.x2; y2 += other.y2; z2 += other.z2;
    return *this;
}

// ===== Вычитание: покоординатно по точкам =====
Vector Vector::operator-(const Vector& other) const {
    return Vector(x1 - other.x1, y1 - other.y1, z1 - other.z1,
        x2 - other.x2, y2 - other.y2, z2 - other.z2);
}

Vector& Vector::operator-=(const Vector& other) {
    x1 -= other.x1; y1 -= other.y1; z1 -= other.z1;
    x2 -= other.x2; y2 -= other.y2; z2 -= other.z2;
    return *this;
}

// ===== Векторное произведение: через компоненты =====
Vector Vector::operator*(const Vector& other) const {
    double ax = getDX(), ay = getDY(), az = getDZ();
    double bx = other.getDX(), by = other.getDY(), bz = other.getDZ();
    return Vector(0, 0, 0,
        ay * bz - az * by,
        az * bx - ax * bz,
        ax * by - ay * bx);
}

Vector& Vector::operator*=(const Vector& other) {
    *this = *this * other;
    return *this;
}

// Умножение на число — тоже покоординатно по точкам
Vector Vector::operator*(double k) const {
    return Vector(x1 * k, y1 * k, z1 * k,
        x2 * k, y2 * k, z2 * k);
}

Vector& Vector::operator*=(double k) {
    x1 *= k; y1 *= k; z1 *= k;
    x2 *= k; y2 *= k; z2 *= k;
    return *this;
}

Vector Vector::operator/(const Vector& other) const {
    double bx = other.getDX(), by = other.getDY(), bz = other.getDZ();
    if (bx == 0 || by == 0 || bz == 0)
        throw std::runtime_error("Division by zero");
    return Vector(0, 0, 0, getDX() / bx, getDY() / by, getDZ() / bz);
}

Vector& Vector::operator/=(const Vector& other) {
    *this = *this / other;
    return *this;
}

Vector Vector::operator/(double k) const {
    if (k == 0) throw std::runtime_error("Division by zero");
    return Vector(x1 / k, y1 / k, z1 / k,
        x2 / k, y2 / k, z2 / k);
}

Vector& Vector::operator/=(double k) {
    x1 /= k; y1 /= k; z1 /= k;
    x2 /= k; y2 /= k; z2 /= k;
    return *this;
}

double Vector::operator^(const Vector& other) const {
    double dot = getDX() * other.getDX()
        + getDY() * other.getDY()
        + getDZ() * other.getDZ();
    double l1 = length(), l2 = other.length();
    if (l1 == 0 || l2 == 0) return 0;
    return dot / (l1 * l2);
}

bool Vector::operator==(const Vector& other) const {
    return getDX() == other.getDX()
        && getDY() == other.getDY()
        && getDZ() == other.getDZ();
}
bool Vector::operator!=(const Vector& other) const { return !(*this == other); }
bool Vector::operator>(const Vector& other)  const { return length() > other.length(); }
bool Vector::operator>=(const Vector& other) const { return length() >= other.length(); }
bool Vector::operator<(const Vector& other)  const { return length() < other.length(); }
bool Vector::operator<=(const Vector& other) const { return length() <= other.length(); }

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x1 << "," << v.y1 << "," << v.z1 << ")->("
        << v.x2 << "," << v.y2 << "," << v.z2 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
    is >> v.x1 >> v.y1 >> v.z1 >> v.x2 >> v.y2 >> v.z2;
    return is;
}