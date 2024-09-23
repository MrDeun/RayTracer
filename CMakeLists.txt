cmake_minimum_required(VERSION 3.5.0)
project(RayTracer VERSION 0.1.0 LANGUAGES C CXX)

add_executable(RayTracer src/main.cpp src/vec3.cpp src/ray.cpp src/color.cpp)

