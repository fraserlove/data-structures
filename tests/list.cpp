#include <gtest/gtest.h>

#include "../include/strux.h"

TEST(List, Constructor) {
    List<int> list;
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.length(), 0);
}

TEST(List, ArrayConstructor) {
    int values[] = {1, 2, 3, 4, 5};
    List<int> list(values, 5);
    
    EXPECT_EQ(list.length(), 5);
    EXPECT_FALSE(list.isEmpty());
    
    for(int i = 0; i < 5; i++) {
        EXPECT_EQ(list.get(i), values[i]);
    }
}

TEST(List, Push) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 2);
    EXPECT_EQ(list.get(2), 3);
}

TEST(List, Insert) {
    List<int> list;
    
    list.push(1);
    list.push(3);
    
    list.insert(1, 2);
    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 2);
    EXPECT_EQ(list.get(2), 3);
    
    list.insert(0, 0);
    EXPECT_EQ(list.get(0), 0);
    
    list.insert(4, 4);
    EXPECT_EQ(list.get(4), 4);
    
    EXPECT_THROW(list.insert(6, 6), std::out_of_range);
    EXPECT_THROW(list.insert(-1, -1), std::out_of_range);
}

TEST(List, Set) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    list.set(1, 5);
    EXPECT_EQ(list.get(1), 5);
    
    EXPECT_THROW(list.set(3, 4), std::out_of_range);
    EXPECT_THROW(list.set(-1, 0), std::out_of_range);
}

TEST(List, Get) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 2);
    EXPECT_EQ(list.get(2), 3);
    
    EXPECT_THROW(list.get(3), std::out_of_range);
    EXPECT_THROW(list.get(-1), std::out_of_range);
}

TEST(List, Remove) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    EXPECT_EQ(list.remove(1), 2);
    EXPECT_EQ(list.length(), 2);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 3);
    
    EXPECT_EQ(list.remove(0), 1);
    EXPECT_EQ(list.length(), 1);
    EXPECT_EQ(list.get(0), 3);
    
    EXPECT_EQ(list.remove(0), 3);
    EXPECT_TRUE(list.isEmpty());
    
    EXPECT_THROW(list.remove(0), std::out_of_range);
    EXPECT_THROW(list.remove(-1), std::out_of_range);
}

TEST(List, RemoveValue) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(2);
    
    EXPECT_TRUE(list.removeValue(2));
    EXPECT_EQ(list.length(), 3);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 3);
    EXPECT_EQ(list.get(2), 2);
    
    EXPECT_TRUE(list.removeValue(1));
    EXPECT_EQ(list.length(), 2);
    
    EXPECT_TRUE(list.removeValue(2));
    EXPECT_EQ(list.length(), 1);
    
    EXPECT_FALSE(list.removeValue(5));
}

TEST(List, Pop) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    EXPECT_EQ(list.pop(), 3);
    EXPECT_EQ(list.length(), 2);
    
    EXPECT_EQ(list.pop(), 2);
    EXPECT_EQ(list.length(), 1);
    
    EXPECT_EQ(list.pop(), 1);
    EXPECT_TRUE(list.isEmpty());
    
    EXPECT_THROW(list.pop(), std::runtime_error);
}

TEST(List, Peek) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    
    EXPECT_EQ(list.peek(), 1);
    
    list.remove(0);
    EXPECT_EQ(list.peek(), 2);
    
    EXPECT_THROW(List<int>().peek(), std::runtime_error);
}

TEST(List, Clear) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    list.clear();
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.length(), 0);
}

TEST(List, Find) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(2);
    
    EXPECT_EQ(list.find(2), 1);
    EXPECT_EQ(list.find(3), 2);
    EXPECT_EQ(list.find(5), -1);
}

TEST(List, Contains) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    EXPECT_TRUE(list.contains(2));
    EXPECT_FALSE(list.contains(5));
}

TEST(List, Reverse) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    list.reverse();
    
    EXPECT_EQ(list.get(0), 3);
    EXPECT_EQ(list.get(1), 2);
    EXPECT_EQ(list.get(2), 1);
    
    EXPECT_THROW(List<int>().reverse(), std::runtime_error);
}

TEST(List, ToVector) {
    List<int> list;
    
    list.push(1);
    list.push(2);
    list.push(3);
    
    Vector<int>* vector = list.toVector();
    
    EXPECT_EQ(vector->length(), 3);
    EXPECT_EQ(vector->get(0), 1);
    EXPECT_EQ(vector->get(1), 2);
    EXPECT_EQ(vector->get(2), 3);
    
    delete vector;
}

TEST(List, MultipleTypes) {
    List<int> li;
    li.push(42);
    EXPECT_EQ(li.peek(), 42);
    
    List<float> lf;
    lf.push(3.14f);
    EXPECT_EQ(lf.peek(), 3.14f);
    
    List<char> lc;
    lc.push('A');
    EXPECT_EQ(lc.peek(), 'A');
}

TEST(List, LargeOperations) {
    List<int> list;
    
    for(int i = 0; i < 1000; i++) {
        list.push(i);
    }
    
    EXPECT_EQ(list.length(), 1000);
    
    for(int i = 0; i < 1000; i++) {
        EXPECT_EQ(list.get(i), i);
    }
    
    for(int i = 0; i < 1000; i++) {
        EXPECT_EQ(list.pop(), 999 - i);
    }
    
    EXPECT_TRUE(list.isEmpty());
}