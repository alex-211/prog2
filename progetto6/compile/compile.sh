#!/bin/bash
echo "-----------------------"
echo "| Compiling progetto6 |"
echo "-----------------------"

# Create output directory if it doesn't exist
mkdir -p ../bin

# Compile and link all source files
# We include both the core logic (ram.c), the test framework (unity.c),
# the test definitions (tests.c), and the entry point (main.c).
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
else
    echo "-----------------------"
    echo "|    Build FAILED!    |"
    echo "-----------------------"
    exit 1
fi
