#pragma once

#include <cmath>
#include <iostream>
class vec3 {
public:
  double x;
  double y;
  double z;

  vec3() : x{0}, y{0}, z{0} {}
  vec3(double x, double y, double z) : x{x}, y{y}, z{x} {}

  vec3 operator-() const { return vec3(-x, -y, -z); }
  vec3 &operator+=(const vec3 &v);
  vec3 &operator*=(double t);
  vec3 &operator/=(double t);

  double length() const { return std::sqrt(lenghth_squated()); }
  double lenghth_squated() const { return x * x + y * y + z * z; }

  inline std::ostream &operator<<(std::ostream &out) {
    return out << x << ' ' << y << ' ' << z;
  }
  inline vec3 operator+(const vec3 &second) const {
    return vec3(x + second.x, y + second.y, z + second.z);
  }
  inline vec3 operator-(const vec3 &first) const {
    return vec3(x - first.x, y - first.y, z - first.z);
  }
  inline vec3 operator*(const vec3 &first) const {
    return vec3(x * first.x, y * first.y, first.z * z);
  }
  inline vec3 operator/(const vec3 &first) const {
    return vec3(x / first.x, y / first.y, z / first.z);
  }

  inline vec3 operator*(double decimal) const {
    return vec3(x * decimal, y * decimal, z * decimal);
  }
  inline vec3 operator/(double decimal) const {
    return vec3(x / decimal, y / decimal, z / decimal);
  }

  inline vec3 cross(const vec3 &second) const {
    return vec3(y * second.z - z * second.y, z * second.x - x * second.z,
                x * second.y - y * second.x);
  }
  vec3 unit_vector() const {
    return vec3(x / length(), y / length(), z / length());
  }
};
using point3 = vec3;

vec3 operator*(double decimal, const vec3& v);