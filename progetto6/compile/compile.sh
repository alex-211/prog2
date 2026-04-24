#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto6 |"
echo "-----------------------"

# Create output directories if they don't exist
mkdir -p ../bin

# Compile individual source files into object files
gcc -c ../src/ram.c -I../include -o ../bin/ram.o
gcc -c ../src/unity/unity.c -I../include/unity -o ../bin/unity.o
gcc -c ../src/tests.c -I../include -I../include/unity -o ../bin/tests.o

# Link object files into the final executable (Test suite)
gcc ../bin/ram.o ../bin/unity.o ../bin/tests.o -o ../bin/progetto6.out

echo "---------------------------------------------"
echo "| Build complete! output: bin/progetto6.out |"
echo "---------------------------------------------"
echo " "
