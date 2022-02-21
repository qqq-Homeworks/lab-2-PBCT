cmake_minimum_required(VERSION 3.20)
project(2_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_lab
        Man.cpp Man.hpp #1.1.hpp 1.1.cpp
        Planet.cpp Planet.hpp #1.3.cpp 1.3.hpp
        Department.cpp Department.hpp #1.4.hpp 1.4.cpp
        )
