#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto6 |"
echo "-----------------------"

mkdir -p ../bin

gcc -I../include -I../include/unity \
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
    echo "| Running bin/progetto6 |"
    echo " "
    ../bin/progetto6
else
    echo "-----------------------"
    echo "|    Build FAILED!    |"
    echo "-----------------------"
    exit 1
fi
