cmake_minimum_required(VERSION 4.1)
project(progetto6 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(include/unity)

add_executable(progetto6
        include/unity/unity.h
        include/unity/unity_internals.h
        include/ram.h
        include/tests.h
        src/unity/unity.c
        src/main.c
        src/ram.c
        src/tests.c)
