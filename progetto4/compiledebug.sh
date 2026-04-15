#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto4 |"
echo "-----------------------"

mkdir -p bin/unity

gcc -c source/unity/unity.c -Iinclude -g bin/unity/unity.out
gcc -c source/charLinkedListQueueADT.c -Iinclude -g bin/charLinkedListQueueADT.out
gcc -c source/tests.c -Iinclude -g bin/tests.out
gcc -c source/main.c -Iinclude -g bin/main.out

gcc bin/unity/unity.out bin/charLinkedListQueueADT.out bin/tests.out bin/main.out -o bin/progetto4.out

echo "---------------------------------------------"
echo "| Build complete! output: bin/progetto4.out |"
echo "---------------------------------------------"
echo " "
echo "| Running debugger on: bin/progetto4.out |"
echo " "

gdb bin/progetto4.out
