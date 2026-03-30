cmake_minimum_required(VERSION 4.1)
project(progetto3 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(progetto3
        include/charArrayQueue.h
        include/charQueueADT.h
        source/charQueueADT.c
        source/main.c)
