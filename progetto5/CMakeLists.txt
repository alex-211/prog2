cmake_minimum_required(VERSION 4.1)
project(progetto5 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(progetto5
        include/intLinkedListSortedSetADT.h
        include/intSortedSetADT.h
        src/intLinkedListSortedSetADT.c
        src/test_intLinkedListSortedSetADT.c)
