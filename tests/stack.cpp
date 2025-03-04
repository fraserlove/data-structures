#include <gtest/gtest.h>

#include "../include/strux.h"

TEST(Stack, Constructor) {
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.length(), 0);
}

TEST(Stack, SingleElementConstructor) {
    Stack<int> stack(42);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.length(), 1);
    EXPECT_EQ(stack.peek(), 42);
}

TEST(Stack, ArrayConstructor) {
    int values[] = {1, 2, 3, 4, 5};
    Stack<int> stack(values, 5);
    
    EXPECT_EQ(stack.length(), 5);
    EXPECT_FALSE(stack.isEmpty());
    
    for(int i = 0; i < 5; i++) {
        EXPECT_EQ(stack.pop(), 5 - i);
    }
}

TEST(Stack, Push) {
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    EXPECT_EQ(stack.length(), 3);
    EXPECT_EQ(stack.peek(), 3);
}

TEST(Stack, Pop) {
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.length(), 2);
    
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.length(), 1);
    
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.isEmpty());
    
    EXPECT_THROW(stack.pop(), std::runtime_error);
}

TEST(Stack, Peek) {
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    
    EXPECT_EQ(stack.peek(), 2);
    
    stack.pop();
    EXPECT_EQ(stack.peek(), 1);
    
    EXPECT_THROW(Stack<int>().peek(), std::runtime_error);
}

TEST(Stack, Clear) {
    Stack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    stack.clear();
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.length(), 0);
}

TEST(Stack, MultipleTypes) {
    Stack<int> si;
    si.push(42);
    EXPECT_EQ(si.peek(), 42);
    
    Stack<float> sf;
    sf.push(3.14f);
    EXPECT_EQ(sf.peek(), 3.14f);
    
    Stack<char> sc;
    sc.push('A');
    EXPECT_EQ(sc.peek(), 'A');
}

TEST(Stack, LargeOperations) {
    Stack<int> stack;
    
    for(int i = 0; i < 1000; i++) {
        stack.push(i);
    }
    
    EXPECT_EQ(stack.length(), 1000);
    
    for(int i = 0; i < 1000; i++) {
        EXPECT_EQ(stack.pop(), 999 - i);
    }
    
    EXPECT_TRUE(stack.isEmpty());
}
