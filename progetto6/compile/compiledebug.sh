#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto6 |"
echo "-----------------------"

mkdir -p ../bin

# Compile individual source files into object files with debug symbols
gcc -g -c ../src/ram.c -I../include -o ../bin/ram.o
gcc -g -c ../src/unity/unity.c -I../include/unity -o ../bin/unity.o
gcc -g -c ../src/tests.c -I../include -I../include/unity -o ../bin/tests.o

# Link object files into the final executable
gcc ../bin/ram.o ../bin/unity.o ../bin/tests.o -o ../bin/progetto6.out

echo "---------------------------------------------"
echo "| Build complete! output: bin/progetto6.out |"
echo "---------------------------------------------"
echo " "
echo "| Running debugger on: bin/progetto6.out |"
echo " "

gdb ../bin/progetto6.out
