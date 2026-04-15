cmake_minimum_required(VERSION 4.1)
project(progetto4 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(include/unity)

add_executable(progetto4
        source/main.c
        include/tests.h
        source/tests.c
        include/charQueueADT.h
        include/linkedListQueue.h
        source/charLinkedListQueueADT.c
        source/unity/unity.c)
