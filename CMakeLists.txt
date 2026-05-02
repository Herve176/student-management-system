cmake_minimum_required(VERSION 3.20)
project(student_management_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(student_management_system main.cpp
        Student.cpp
        Student.h
        services/StudentService.cpp
        services/StudentService.h)
