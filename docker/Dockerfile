# Use a stable Ubuntu base image
FROM ubuntu:24.04

# Avoid prompts when installing packages
ENV DEBIAN_FRONTEND=noninteractive

# Install C++ toolchain, CMake, and Static Analysis tools
RUN apt update && apt install -y \
    build-essential \
    cmake \
    git \
    clang-tidy \
    clang-format \
    cppcheck \
    python3 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Install Lizard for Cyclomatic Complexity analysis
RUN pip3 install --break-system-packages lizard