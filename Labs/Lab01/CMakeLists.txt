# cmake_minimum_required(VERSION <specify CMake version here>)
project(Lab01 C)

set(CMAKE_C_STANDARD 99)

add_library(Lab01 library.c library.h names.cpp names.c LectureSample_1.c LectureSample_1.h)