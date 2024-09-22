#pragma once

class vec3 {
  public:
    double x;
    double y;
    double z;

    vec3() : x{0},y{0},z{0} {}
    vec3(double x, double y, double z): x{x},y{y},z{x} {}

    vec3 operator-() const {return vec3(-x,-y,-z);}
    vec3& operator+=(const vec3& v) {
      x = v.x;
      y = v.y;
      z = v.z;
      return *this;
    } 
};