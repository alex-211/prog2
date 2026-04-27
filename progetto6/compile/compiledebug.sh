#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto6 |"
echo "-----------------------"

mkdir -p ../bin

# Compile with debug symbols (-g)
gcc -g -I../include -I../include/unity \
    ../src/ram.c \
    ../src/unity/unity.c \
    ../src/tests.c \
    ../src/main.c \
    -o ../bin/progetto6

if [ $? -eq 0 ]; then
    echo "---------------------------------------------"
    echo "| Build complete! output: bin/progetto6     |"
    echo "---------------------------------------------"
    echo " "
    echo "| Running debugger on: bin/progetto6 |"
    echo " "
    gdb ../bin/progetto6
else
    echo "-----------------------"
    echo "|    Build FAILED!    |"
    echo "-----------------------"
    exit 1
fi
