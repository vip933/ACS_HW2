cmake_minimum_required(VERSION 3.20)
project(ACS_mdleypunskiy_HW2)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

set(SOURCE_FILES
        # source files
        main.cpp
        shape.cpp
        ball.cpp
        tetrahedron.cpp
        container.cpp
        parallelepiped.cpp

        # headers files
        tetrahedron.h
        ball.h
        parallelepiped.h
        container.h
        shape.h
        rnd.h
)

add_executable(project ${SOURCE_FILES})
