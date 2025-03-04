#include <gtest/gtest.h>

#include "../include/strux.h"

TEST(Queue, Constructor) {
    Queue<int> queue;
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.length(), 0);
}

TEST(Queue, SingleElementConstructor) {
    Queue<int> queue(42);
    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.length(), 1);
    EXPECT_EQ(queue.peek(), 42);
}

TEST(Queue, ArrayConstructor) {
    int values[] = {1, 2, 3, 4, 5};
    Queue<int> queue(values, 5);
    
    EXPECT_EQ(queue.length(), 5);
    EXPECT_FALSE(queue.isEmpty());
    
    for(int i = 0; i < 5; i++) {
        EXPECT_EQ(queue.pop(), values[i]);
    }
}

TEST(Queue, Enqueue) {
    Queue<int> queue;
    
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_EQ(queue.length(), 3);
    EXPECT_EQ(queue.peek(), 1);
}

TEST(Queue, Dequeue) {
    Queue<int> queue;
    
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_EQ(queue.length(), 2);
    
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.length(), 1);
    
    EXPECT_EQ(queue.pop(), 3);
    EXPECT_TRUE(queue.isEmpty());
    
    EXPECT_THROW(queue.pop(), std::runtime_error);
}

TEST(Queue, Peek) {
    Queue<int> queue;
    
    queue.push(1);
    queue.push(2);
    
    EXPECT_EQ(queue.peek(), 1);
    
    queue.pop();
    EXPECT_EQ(queue.peek(), 2);
    
    EXPECT_THROW(Queue<int>().peek(), std::runtime_error);
}

TEST(Queue, Clear) {
    Queue<int> queue;
    
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    queue.clear();
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.length(), 0);
}

TEST(Queue, MultipleTypes) {
    Queue<int> qi;
    qi.push(42);
    EXPECT_EQ(qi.peek(), 42);
    
    Queue<float> qf;
    qf.push(3.14f);
    EXPECT_EQ(qf.peek(), 3.14f);
    
    Queue<char> qc;
    qc.push('A');
    EXPECT_EQ(qc.peek(), 'A');
}

TEST(Queue, LargeOperations) {
    Queue<int> queue;
    
    for(int i = 0; i < 1000; i++) {
        queue.push(i);
    }
    
    EXPECT_EQ(queue.length(), 1000);
    
    for(int i = 0; i < 1000; i++) {
        EXPECT_EQ(queue.pop(), i);
    }
    
    EXPECT_TRUE(queue.isEmpty());
}
