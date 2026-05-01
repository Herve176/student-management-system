# Student Management System

A C++ application for managing student records with basic CRUD operations.

## Features

- **Create**: Add new students to the system
- **Read**: Display student information
- **Update**: Modify existing student records
- **Delete**: Remove students from the system

## Project Structure
student-management-system/ ├── CMakeLists.txt # CMake build configuration ├── main.cpp # Entry point with menu interface ├── Student.h # Student class header ├── Student.cpp # Student class implementation ├── LICENSE # Project license └── README.md # 
## Prerequisites

- C++11 or later
- CMake 3.10+
- GCC or Clang compiler

## Building

### Build Steps

```bash
# Navigate to project directory
cd student-management-system

# Create and enter build directory
mkdir -p build && cd build

# Configure and build
cmake ..
make