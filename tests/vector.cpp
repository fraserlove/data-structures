#include <gtest/gtest.h>

#include "../include/strux.h"

TEST(Vector, Constructor) {
    Vector<int> vector;
    EXPECT_TRUE(vector.isEmpty());
    EXPECT_EQ(vector.length(), 0);
}

TEST(Vector, ArrayConstructor) {
    int values[] = {1, 2, 3, 4, 5};
    Vector<int> vector(values, 5);
    
    EXPECT_EQ(vector.length(), 5);
    EXPECT_FALSE(vector.isEmpty());
    
    for(int i = 0; i < 5; i++) {
        EXPECT_EQ(vector.get(i), values[i]);
    }
}

TEST(Vector, Push) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    EXPECT_EQ(vector.length(), 3);
    EXPECT_EQ(vector.get(0), 1);
    EXPECT_EQ(vector.get(1), 2);
    EXPECT_EQ(vector.get(2), 3);
}

TEST(Vector, Insert) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(3);
    
    vector.insert(1, 2);
    EXPECT_EQ(vector.length(), 3);
    EXPECT_EQ(vector.get(0), 1);
    EXPECT_EQ(vector.get(1), 2);
    EXPECT_EQ(vector.get(2), 3);
    
    vector.insert(0, 0);
    EXPECT_EQ(vector.get(0), 0);
    
    vector.insert(4, 4);
    EXPECT_EQ(vector.get(4), 4);
    
    EXPECT_THROW(vector.insert(6, 6), std::out_of_range);
    EXPECT_THROW(vector.insert(-1, -1), std::out_of_range);
}

TEST(Vector, Set) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    vector.set(1, 5);
    EXPECT_EQ(vector.get(1), 5);
    
    EXPECT_THROW(vector.set(3, 4), std::out_of_range);
    EXPECT_THROW(vector.set(-1, 0), std::out_of_range);
}

TEST(Vector, Get) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    EXPECT_EQ(vector.get(0), 1);
    EXPECT_EQ(vector.get(1), 2);
    EXPECT_EQ(vector.get(2), 3);
    
    EXPECT_THROW(vector.get(3), std::out_of_range);
    EXPECT_THROW(vector.get(-1), std::out_of_range);
}

TEST(Vector, Remove) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    EXPECT_EQ(vector.remove(1), 2);
    EXPECT_EQ(vector.length(), 2);
    EXPECT_EQ(vector.get(0), 1);
    EXPECT_EQ(vector.get(1), 3);
    
    EXPECT_EQ(vector.remove(0), 1);
    EXPECT_EQ(vector.length(), 1);
    EXPECT_EQ(vector.get(0), 3);
    
    EXPECT_EQ(vector.remove(0), 3);
    EXPECT_TRUE(vector.isEmpty());
    
    EXPECT_THROW(vector.remove(0), std::out_of_range);
    EXPECT_THROW(vector.remove(-1), std::out_of_range);
}

TEST(Vector, RemoveValue) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    vector.push(2);
    
    EXPECT_TRUE(vector.removeValue(2));
    EXPECT_EQ(vector.length(), 3);
    EXPECT_EQ(vector.get(0), 1);
    EXPECT_EQ(vector.get(1), 3);
    EXPECT_EQ(vector.get(2), 2);
    
    EXPECT_TRUE(vector.removeValue(1));
    EXPECT_EQ(vector.length(), 2);
    
    EXPECT_TRUE(vector.removeValue(2));
    EXPECT_EQ(vector.length(), 1);
    
    EXPECT_FALSE(vector.removeValue(5));
}

TEST(Vector, Pop) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    EXPECT_EQ(vector.pop(), 3);
    EXPECT_EQ(vector.length(), 2);
    
    EXPECT_EQ(vector.pop(), 2);
    EXPECT_EQ(vector.length(), 1);
    
    EXPECT_EQ(vector.pop(), 1);
    EXPECT_TRUE(vector.isEmpty());
    
    EXPECT_THROW(vector.pop(), std::runtime_error);
}

TEST(Vector, Clear) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    vector.clear();
    EXPECT_TRUE(vector.isEmpty());
    EXPECT_EQ(vector.length(), 0);
}

TEST(Vector, Find) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    vector.push(2);
    
    EXPECT_EQ(vector.find(2), 1);
    EXPECT_EQ(vector.find(3), 2);
    EXPECT_EQ(vector.find(5), -1);
}

TEST(Vector, FindAll) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    vector.push(2);
    vector.push(2);
    
    Vector<int>* indices = vector.findAll(2);
    
    EXPECT_EQ(indices->length(), 3);
    EXPECT_EQ(indices->get(0), 1);
    EXPECT_EQ(indices->get(1), 3);
    EXPECT_EQ(indices->get(2), 4);
    
    delete indices;
    
    indices = vector.findAll(5);
    EXPECT_EQ(indices->length(), 0);
    delete indices;
}

TEST(Vector, Contains) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    EXPECT_TRUE(vector.contains(2));
    EXPECT_FALSE(vector.contains(5));
}

TEST(Vector, Reverse) {
    Vector<int> vector;
    
    vector.push(1);
    vector.push(2);
    vector.push(3);
    
    vector.reverse();
    
    EXPECT_EQ(vector.get(0), 3);
    EXPECT_EQ(vector.get(1), 2);
    EXPECT_EQ(vector.get(2), 1);
}

TEST(Vector, MultipleTypes) {
    Vector<int> vi;
    vi.push(42);
    EXPECT_EQ(vi.get(0), 42);
    
    Vector<float> vf;
    vf.push(3.14f);
    EXPECT_EQ(vf.get(0), 3.14f);
    
    Vector<char> vc;
    vc.push('A');
    EXPECT_EQ(vc.get(0), 'A');
}

TEST(Vector, LargeOperations) {
    Vector<int> vector;
    
    for(int i = 0; i < 1000; i++) {
        vector.push(i);
    }
    
    EXPECT_EQ(vector.length(), 1000);
    
    for(int i = 0; i < 1000; i++) {
        EXPECT_EQ(vector.get(i), i);
    }
    
    for(int i = 0; i < 1000; i++) {
        EXPECT_EQ(vector.pop(), 999 - i);
    }
    
    EXPECT_TRUE(vector.isEmpty());
}

TEST(Vector, ArrayInsert) {
    Vector<int> vector;
    
    int values[] = {4, 5, 6};
    vector.push(1);
    vector.push(2);
    vector.push(3);
    vector.push(7);
    
    vector.insert(3, values, 3);
    
    EXPECT_EQ(vector.length(), 7);
    EXPECT_EQ(vector.get(0), 1);
    EXPECT_EQ(vector.get(1), 2);
    EXPECT_EQ(vector.get(2), 3);
    EXPECT_EQ(vector.get(3), 4);
    EXPECT_EQ(vector.get(4), 5);
    EXPECT_EQ(vector.get(5), 6);
    EXPECT_EQ(vector.get(6), 7);
    
    EXPECT_THROW(vector.insert(8, values, 3), std::out_of_range);
    EXPECT_THROW(vector.insert(-1, values, 3), std::out_of_range);
}

TEST(Vector, ArrayPush) {
    Vector<int> vector;
    
    int values[] = {1, 2, 3};
    vector.push(values, 3);
    
    EXPECT_EQ(vector.length(), 3);
    EXPECT_EQ(vector.get(0), 1);
    EXPECT_EQ(vector.get(1), 2);
    EXPECT_EQ(vector.get(2), 3);
}
