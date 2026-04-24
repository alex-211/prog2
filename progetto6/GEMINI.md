# Buddy System RAM Management (Progetto 6)

## Project Overview
This project involves implementing a **Buddy System** for dynamic RAM management in C. The implementation follows a Test-Driven Development (TDD) approach using the **Unity** testing framework.

The core logic revolves around a binary tree structure where each node represents a block of memory. Blocks can be split into two "buddies" of equal size (powers of 2) or merged back together when both are free.

### Key Technologies
- **Language:** C
- **Testing Framework:** Unity
- **Concepts:** Dynamic memory allocation, binary trees, Buddy System algorithm.

## Project Structure
- `include/ram.h`: Header file containing the API definitions and data structures.
- `src/ram.c`: Implementation of the RAM management logic (to be developed).
- `src/tests.c`: Unity-based test suite for verifying the implementation (to be developed).
- `src/main.c`: Entry point for the application.
- `include/unity/`, `src/unity/`: Unity testing framework files.
- `bin/`: Directory for compiled binaries.

## API Specifications (`ram.h`)
- `initram(int M)`: Creates a RAM structure with `M` KB (must be a power of 2).
- `allocram(int K, RAM ram)`: Attempts to allocate `K` KB.
- `deallocram(RAM ram)`: Frees a previously allocated node.
- `numfree(RAM ram)`: Returns total free memory in KB.
- `ram2str(RAM ram)`: Serializes the RAM state to a string.
- `str2ram(char *str)`: Deserializes the RAM state from a string.
- `freeram(RAM* ramptr)`: Deeply frees the RAM data structure.

## Development Conventions
- **Left-Priority:** When searching for a free node, always prioritize the left child (`lbuddy`). This is mandatory for compatibility with automated tests.
- **TDD:** New features should be driven by tests in `src/tests.c`.
- **Memory Management:** Ensure all allocated nodes are properly freed using `freeram` to avoid leaks.

## Building and Running
Since no Makefile is provided, the following GCC commands can be used:

### Compile and Run Tests
```bash
gcc -Iinclude -Iinclude/unity src/unity/unity.c src/ram.c src/tests.c -o bin/tests
./bin/tests
```

### Compile and Run Main
```bash
gcc -Iinclude src/ram.c src/main.c -o bin/main
./bin/main
```

## Implementation Notes
- The RAM structure uses an `enum stato {INTERNO, LIBERO, OCCUPATO}`.
- `INTERNO` nodes are those that have been split into buddies.
- `LIBERO` nodes are available for allocation.
- `OCCUPATO` nodes are currently in use.
