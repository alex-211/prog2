cmake_minimum_required(VERSION 4.1)
project(progetto2 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(progetto2
        include/contact.h
        source/contact.c
        main.c)
