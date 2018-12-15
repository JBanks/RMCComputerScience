# cmake_minimum_required(VERSION <specify CMake version here>)
project(final_2017 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(src/main.c
        src/sphere.h
        src/student.c
        src/student.h
        src/support.c
        src/support.h)
