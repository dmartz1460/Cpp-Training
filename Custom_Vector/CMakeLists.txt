# Add the source file as a library
add_library(CustomVector src/CustomVector.cpp)
target_include_directories(CustomVector PUBLIC src)

# Add the test executable
add_executable(test_vector tests/test_vector.cpp)

# Link the library and GoogleTest to the executable
# Note: gtest_main provides the main() function for the tests
target_link_libraries(test_vector PRIVATE CustomVector gtest_main)

# Register the test with CMake's testing framework (CTest)
include(GoogleTest)
gtest_discover_tests(test_vector)