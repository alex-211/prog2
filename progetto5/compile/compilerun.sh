#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto5 |"
echo "-----------------------"

# Create output directories if they don't exist
mkdir -p ../bin

# Compile individual source files into object files
gcc -c ../src/intLinkedListSortedSetADT.c -I../include -o ../bin/intLinkedListSortedSetADT.o
gcc -c ../src/test_intLinkedListSortedSetADT.c -I../include -o ../bin/test_intLinkedListSortedSetADT.o

# Link object files into the final executable
gcc ../bin/intLinkedListSortedSetADT.o ../bin/test_intLinkedListSortedSetADT.o -o ../bin/progetto5.out

echo "---------------------------------------------"
echo "| Build complete! output: bin/progetto5.out |"
echo "---------------------------------------------"
echo " "
echo "| Running bin/progetto5.out |"
echo " "

../bin/progetto5.out
