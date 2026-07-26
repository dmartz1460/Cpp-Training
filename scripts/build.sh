#!/usr/bin/env bash

# Build script to build the project and run code complexity analysis using lizard.

# Make build directory inside the project's folder
mkdir build && cd build

# Build the project using CMake
cmake ..
cmake --build .
ctest --output-on-failure
cd ..

# Run code complexity analysis using lizard on the project's source code
echo '=== Running Code Complexity Analysis ==='
lizard .