cmake_minimum_required(VERSION 3.20)
project(CppTraining VERSION 1.0 LANGUAGES CXX)

# Force C++17 Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json (Required for clang-tidy)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- 1. Static Analysis Configuration ---
# Enable clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=*,-fuchsia-*,-google-readability-todo")
endif()

# Enable cppcheck
find_program(CPPCHECK_EXE NAMES "cppcheck")
if(CPPCHECK_EXE)
    set(CMAKE_CXX_CPPCHECK "${CPPCHECK_EXE};--enable=all;--inconclusive;--force;--inline-suppr")
endif()

# --- 2. GoogleTest Integration ---
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable CTest
enable_testing()

# --- 3. Include Target Project ---
# Check if TARGET_PROJECT was provided via the command line
if(DEFINED TARGET_PROJECT)
    # Add only the specific project directory passed from the script
    add_subdirectory(${TARGET_PROJECT})
else()
    message(WARNING "No TARGET_PROJECT specified. Nothing to build.")
endif()