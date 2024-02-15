# Data Structures with Generic Types in C++

## Overview

This repository reviews the basic data structures in C++ with generic types.
The data structures are implemented using templates,
which allows the data structures to be used with any data type.

The data structures reviewed are:

- Stack
  - Array-based

## Running the Code

CMakelists.txt is included in the repository to build the code.

Googletest is used for testing the code, so it should be installed on your system.

To build the code, run the following commands:

```bash
# Configure the build with the C++ compiler of your choice, and the build system of your choice.
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++-13 -G Ninja
cmake --build build

# You can then navigate to the build directory and run the executables.
./build/0x01-ArrayStack/ArrayStack

# To run the tests, just invoke ctest from the root directory of the repository.
ctest
```
