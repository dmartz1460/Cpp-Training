#include <gtest/gtest.h>
#include "CustomVector.h"

// Test that the vector initializes with size 0
TEST(CustomVectorTest, InitialSizeIsZero) {
    CustomVector vec;
    EXPECT_EQ(vec.size(), 0);
}

// Test adding an element
TEST(CustomVectorTest, AddElement) {
    CustomVector vec;
    vec.add(42);
    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec.get(0), 42);
}