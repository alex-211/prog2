#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto4 |"
echo "-----------------------"

# Create output directories if they don't exist
mkdir -p bin/unity

# Compile individual source files into object files
gcc -c source/unity/unity.c -Iinclude -o bin/unity/unity.out
gcc -c source/charLinkedListQueueADT.c -Iinclude -o bin/charLinkedListQueueADT.out
gcc -c source/tests.c -Iinclude -o bin/tests.out
gcc -c source/main.c -Iinclude -o bin/main.out

# Link object files into the final executable
gcc bin/unity/unity.out bin/charLinkedListQueueADT.out bin/tests.out bin/main.out -o bin/progetto4.out

echo "---------------------------------------------"
echo "| Build complete! output: bin/progetto4.out |"
echo "---------------------------------------------"
echo " "
echo "Running bin/progetto4.out"
echo " "

./bin/progetto4.out
