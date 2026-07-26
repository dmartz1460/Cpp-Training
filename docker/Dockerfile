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


# Set new user's home directory as default working directory
WORKDIR ${HOME}

# Define build argument for build script command
ARG ENTRYPOINT_SCRIPT_COMMAND

# Copy the entrypoint script into the docker container
COPY --chmod=0755 ${ENTRYPOINT_SCRIPT_COMMAND} /usr/local/bin/entrypoint.sh

# Set the default command to run when the container starts
ENTRYPOINT ["entrypoint.sh"]