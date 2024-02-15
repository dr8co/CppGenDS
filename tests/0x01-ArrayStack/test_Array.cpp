#include <gtest/gtest.h>
#include "../../0x01-ArrayStack/Array.hpp"

TEST(ArrayTest, ConstructorCreatesEmptyArray) {
    ods::Array<int> array(0);
    EXPECT_EQ(array.length, 0);
}

TEST(ArrayTest, ConstructorWithInitialValueFillsArray) {
    ods::Array<int> array(5, 1);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], 1);
    }
}

TEST(ArrayTest, FillChangesAllElements) {
    ods::Array<int> array(5);
    array.fill(2);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], 2);
    }
}

TEST(ArrayTest, AssignmentCopiesAllElements) {
    ods::Array<int> array1(5, 1);
    ods::Array<int> array2 = array1;
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array2[i], 1);
    }
}

TEST(ArrayTest, SubscriptOperatorAccessesCorrectElement) {
    ods::Array<int> array(5, 1);
    array[2] = 3;
    EXPECT_EQ(array[2], 3);
}

TEST(ArrayTest, SwapSwapsElementsAtGivenIndices) {
    ods::Array<int> array(2);
    array[0] = 1;
    array[1] = 2;
    array.swap(0, 1);
    EXPECT_EQ(array[0], 2);
    EXPECT_EQ(array[1], 1);
}

TEST(ArrayTest, CopyRangeCopiesCorrectElements) {
    ods::Array<int> array1(5);
    for (int i = 0; i < 5; ++i) {
        array1[i] = i;
    }
    ods::Array<int> array2(0);
    ods::Array<int>::copyRange(array1, array2, 1, 4);
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(array2[i], i + 1);
    }
}

TEST(ArrayTest, ResizeChangesLengthAndKeepsElements) {
    ods::Array<int> array(5, 1);
    array.resize(3);
    EXPECT_EQ(array.length, 3);
    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(array[i], 1);
    }
}

TEST(ArrayTest, ReverseReversesElementOrder) {
    ods::Array<int> array(5);
    for (int i = 0; i < 5; ++i) {
        array[i] = i;
    }
    array.reverse();
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(array[i], 4 - i);
    }
}

TEST(ArrayTest, SubscriptOperatorThrowsExceptionWhenIndexIsOutOfRange) {
    ods::Array<int> array(5);
    EXPECT_THROW(array[5], std::out_of_range);
}

TEST(ArrayTest, SwapThrowsExceptionWhenIndexIsOutOfRange) {
    ods::Array<int> array(5);
    EXPECT_THROW(array.swap(0, 5), std::out_of_range);
}
