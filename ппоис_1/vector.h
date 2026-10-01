#pragma once
#include <iostream>

class Vector {
private:
    double x1, y1, z1; // начало
    double x2, y2, z2; // конец
public:
    Vector(double x1_ = 0, double y1_ = 0, double z1_ = 0,
        double x2_ = 0, double y2_ = 0, double z2_ = 0);

    double getX1() const; double getY1() const; double getZ1() const;
    double getX2() const; double getY2() const; double getZ2() const;
    void setX1(double v); void setY1(double v); void setZ1(double v);
    void setX2(double v); void setY2(double v); void setZ2(double v);

    // компоненты вектора (разности)
    double getDX() const;
    double getDY() const;
    double getDZ() const;

    double length() const;

    Vector operator+(const Vector& other) const;   // покоординатно по точкам
    Vector& operator+=(const Vector& other);

    Vector operator-(const Vector& other) const;   // покоординатно по точкам
    Vector& operator-=(const Vector& other);

    Vector operator*(const Vector& other) const;   // векторное произведение
    Vector& operator*=(const Vector& other);

    Vector operator*(double k) const;
    Vector& operator*=(double k);

    Vector operator/(const Vector& other) const;
    Vector& operator/=(const Vector& other);

    Vector operator/(double k) const;
    Vector& operator/=(double k);

    double operator^(const Vector& other) const;   // косинус

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    bool operator>(const Vector& other) const;
    bool operator>=(const Vector& other) const;
    bool operator<(const Vector& other) const;
    bool operator<=(const Vector& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend std::istream& operator>>(std::istream& is, Vector& v);
};