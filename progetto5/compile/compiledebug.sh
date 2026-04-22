#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto5 |"
echo "-----------------------"

mkdir -p ../bin

# Compile individual source files into object files with debug symbols
gcc -g -c ../src/intLinkedListSortedSetADT.c -I../include -o ../bin/intLinkedListSortedSetADT.o
gcc -g -c ../src/test_intLinkedListSortedSetADT.c -I../include -o ../bin/test_intLinkedListSortedSetADT.o

# Link object files into the final executable
gcc ../bin/intLinkedListSortedSetADT.o ../bin/test_intLinkedListSortedSetADT.o -o ../bin/progetto5.out

echo "---------------------------------------------"
echo "| Build complete! output: bin/progetto5.out |"
echo "---------------------------------------------"
echo " "
echo "| Running debugger on: bin/progetto5.out |"
echo " "

gdb ../bin/progetto5.out
