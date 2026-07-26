#!/usr/bin/env bash

# Build script to build the project and run code complexity analysis using lizard.

# Set the target directory to the first argument passed to the script
TARGET_DIR=$1

git config --global --add safe.directory /home/docker/Cpp-Training/build/_deps/googletest-src
# Pass the argument to CMake using the -D flag
cmake -S . -B build -DTARGET_PROJECT=$TARGET_DIR

# Build the project
cmake --build build

# Run code complexity analysis using lizard on the project's source code
echo '=== Running Code Complexity Analysis ==='
lizard .