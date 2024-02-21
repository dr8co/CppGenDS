#include <gtest/gtest.h>
#include "../../0x01-ArrayStack/ArrayStack.hpp"

TEST(ArrayStackTest, ConstructorCreatesEmptyStack) {
    constexpr ods::ArrayStack<int> stack;
    EXPECT_EQ(stack.size(), 0);
}

TEST(ArrayStackTest, AddIncreasesStackSize) {
    ods::ArrayStack<int> stack;
    stack.add(1);
    EXPECT_EQ(stack.size(), 1);
}

TEST(ArrayStackTest, AddAppendsElementToEnd) {
    ods::ArrayStack<int> stack;
    stack.add(1);
    stack.add(2);
    EXPECT_EQ(stack.get(1), 2);
}

TEST(ArrayStackTest, AddAtIndexInsertsElementAtCorrectPosition) {
    ods::ArrayStack<int> stack;
    stack.add(1);
    stack.add(2);
    stack.add(1, 3);
    EXPECT_EQ(stack.get(1), 3);
}

TEST(ArrayStackTest, RemoveDecreasesStackSize) {
    ods::ArrayStack<int> stack;
    stack.add(1);
    stack.remove(0);
    EXPECT_EQ(stack.size(), 0);
}

TEST(ArrayStackTest, RemoveReturnsCorrectElement) {
    ods::ArrayStack<int> stack;
    stack.add(1);
    EXPECT_EQ(stack.remove(0), 1);
}

TEST(ArrayStackTest, SetReplacesElementAtCorrectPosition) {
    ods::ArrayStack<int> stack;
    stack.add(1);
    stack.set(0, 2);
    EXPECT_EQ(stack.get(0), 2);
}

TEST(ArrayStackTest, ClearResetsStackSizeToZero) {
    ods::ArrayStack<int> stack;
    stack.add(1);
    stack.clear();
    EXPECT_EQ(stack.size(), 0);
}

TEST(ArrayStackTest, AddAtIndexThrowsExceptionWhenIndexIsOutOfRange) {
    ods::ArrayStack<int> stack;
    EXPECT_THROW(stack.add(1, 1), std::out_of_range);
}

TEST(ArrayStackTest, RemoveThrowsExceptionWhenIndexIsOutOfRange) {
    ods::ArrayStack<int> stack;
    EXPECT_THROW(stack.remove(1), std::out_of_range);
}

TEST(ArrayStackTest, SetThrowsExceptionWhenIndexIsOutOfRange) {
    ods::ArrayStack<int> stack;
    EXPECT_THROW(stack.set(1, 2), std::out_of_range);
}

TEST(ArrayStackTest, GetThrowsExceptionWhenIndexIsOutOfRange) {
    ods::ArrayStack<int> stack;
    EXPECT_THROW(stack.get(1), std::out_of_range);
}
