#include <gtest/gtest.h>

#include "../include/strux.h"

TEST(PQueue, Constructor) {
    PQueue<int> pqueue;
    EXPECT_TRUE(pqueue.isEmpty());
    EXPECT_EQ(pqueue.length(), 0);
    EXPECT_FALSE(pqueue.isMax());
    EXPECT_TRUE(pqueue.isMin());
}

TEST(PQueue, MaxHeapConstructor) {
    PQueue<int> pqueue(true);
    EXPECT_TRUE(pqueue.isEmpty());
    EXPECT_EQ(pqueue.length(), 0);
    EXPECT_TRUE(pqueue.isMax());
    EXPECT_FALSE(pqueue.isMin());
}

TEST(PQueue, SizeConstructor) {
    PQueue<int> pqueue(10);
    EXPECT_TRUE(pqueue.isEmpty());
    EXPECT_EQ(pqueue.length(), 0);
    EXPECT_FALSE(pqueue.isMax());
}

TEST(PQueue, ArrayConstructor) {
    int values[] = {5, 3, 8, 1, 2};
    PQueue<int> minHeap(values, 5);
    
    EXPECT_EQ(minHeap.length(), 5);
    EXPECT_FALSE(minHeap.isEmpty());
    EXPECT_FALSE(minHeap.isMax());
    EXPECT_TRUE(minHeap.validHeap());
    
    EXPECT_EQ(minHeap.peek(), 1);
    
    PQueue<int> maxHeap(values, 5, true);
    EXPECT_EQ(maxHeap.length(), 5);
    EXPECT_TRUE(maxHeap.isMax());
    EXPECT_TRUE(maxHeap.validHeap());
    
    EXPECT_EQ(maxHeap.peek(), 8);
}

TEST(PQueue, Push) {
    PQueue<int> minHeap;
    
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(8);
    
    EXPECT_EQ(minHeap.length(), 3);
    EXPECT_EQ(minHeap.peek(), 3);
    EXPECT_TRUE(minHeap.validHeap());
    
    PQueue<int> maxHeap(true);
    
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.push(8);
    
    EXPECT_EQ(maxHeap.length(), 3);
    EXPECT_EQ(maxHeap.peek(), 8);
    EXPECT_TRUE(maxHeap.validHeap());
}

TEST(PQueue, Dequeue) {
    PQueue<int> minHeap;
    
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(8);
    
    EXPECT_EQ(minHeap.pop(), 3);
    EXPECT_EQ(minHeap.length(), 2);
    EXPECT_TRUE(minHeap.validHeap());
    
    EXPECT_EQ(minHeap.pop(), 5);
    EXPECT_EQ(minHeap.length(), 1);
    
    EXPECT_EQ(minHeap.pop(), 8);
    EXPECT_TRUE(minHeap.isEmpty());
    
    EXPECT_THROW(minHeap.pop(), std::runtime_error);
    
    PQueue<int> maxHeap(true);
    
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.push(8);
    
    EXPECT_EQ(maxHeap.pop(), 8);
    EXPECT_EQ(maxHeap.length(), 2);
    EXPECT_TRUE(maxHeap.validHeap());
    
    EXPECT_EQ(maxHeap.pop(), 5);
    EXPECT_EQ(maxHeap.pop(), 3);
    EXPECT_TRUE(maxHeap.isEmpty());
}

TEST(PQueue, Peek) {
    PQueue<int> minHeap;
    
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(8);
    
    EXPECT_EQ(minHeap.peek(), 3);
    
    PQueue<int> maxHeap(true);
    
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.push(8);
    
    EXPECT_EQ(maxHeap.peek(), 8);
    
    EXPECT_THROW(PQueue<int>().peek(), std::runtime_error);
}

TEST(PQueue, Clear) {
    PQueue<int> pqueue;
    
    pqueue.push(5);
    pqueue.push(3);
    pqueue.push(8);
    
    pqueue.clear();
    EXPECT_TRUE(pqueue.isEmpty());
    EXPECT_EQ(pqueue.length(), 0);
}

TEST(PQueue, Find) {
    PQueue<int> pqueue;
    
    pqueue.push(5);
    pqueue.push(3);
    pqueue.push(8);
    
    EXPECT_NE(pqueue.find(3), -1);
    EXPECT_NE(pqueue.find(5), -1);
    EXPECT_NE(pqueue.find(8), -1);
    EXPECT_EQ(pqueue.find(10), -1);
}

TEST(PQueue, Contains) {
    PQueue<int> pqueue;
    
    pqueue.push(5);
    pqueue.push(3);
    pqueue.push(8);
    
    EXPECT_TRUE(pqueue.contains(3));
    EXPECT_TRUE(pqueue.contains(5));
    EXPECT_TRUE(pqueue.contains(8));
    EXPECT_FALSE(pqueue.contains(10));
}

TEST(PQueue, RemoveValue) {
    PQueue<int> minHeap;
    
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(8);
    minHeap.push(1);
    
    EXPECT_TRUE(minHeap.removeValue(5));
    EXPECT_EQ(minHeap.length(), 3);
    EXPECT_TRUE(minHeap.validHeap());
    EXPECT_FALSE(minHeap.contains(5));
    
    EXPECT_TRUE(minHeap.removeValue(1));
    EXPECT_EQ(minHeap.length(), 2);
    EXPECT_TRUE(minHeap.validHeap());
    
    EXPECT_FALSE(minHeap.removeValue(10));
    
    PQueue<int> maxHeap(true);
    
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.push(8);
    
    EXPECT_TRUE(maxHeap.removeValue(3));
    EXPECT_EQ(maxHeap.length(), 2);
    EXPECT_TRUE(maxHeap.validHeap());
    EXPECT_FALSE(maxHeap.contains(3));
}

TEST(PQueue, ValidHeap) {
    int values[] = {5, 3, 8, 1, 2};
    PQueue<int> minHeap(values, 5);
    
    EXPECT_TRUE(minHeap.validHeap());
    
    PQueue<int> maxHeap(values, 5, true);
    EXPECT_TRUE(maxHeap.validHeap());
}

TEST(PQueue, MultipleTypes) {
    PQueue<int> pi;
    pi.push(42);
    EXPECT_EQ(pi.peek(), 42);
    
    PQueue<float> pf;
    pf.push(3.14f);
    pf.push(2.71f);
    EXPECT_EQ(pf.peek(), 2.71f);
    
    PQueue<char> pc;
    pc.push('C');
    pc.push('A');
    pc.push('B');
    EXPECT_EQ(pc.peek(), 'A');
}

TEST(PQueue, LargeOperations) {
    PQueue<int> minHeap;
    
    for(int i = 999; i >= 0; i--) {
        minHeap.push(i);
    }
    
    EXPECT_EQ(minHeap.length(), 1000);
    EXPECT_TRUE(minHeap.validHeap());
    
    for(int i = 0; i < 1000; i++) {
        EXPECT_EQ(minHeap.pop(), i);
    }
    
    EXPECT_TRUE(minHeap.isEmpty());
    
    PQueue<int> maxHeap(true);
    
    for(int i = 0; i < 1000; i++) {
        maxHeap.push(i);
    }
    
    EXPECT_EQ(maxHeap.length(), 1000);
    EXPECT_TRUE(maxHeap.validHeap());
    
    for(int i = 999; i >= 0; i--) {
        EXPECT_EQ(maxHeap.pop(), i);
    }
    
    EXPECT_TRUE(maxHeap.isEmpty());
}
