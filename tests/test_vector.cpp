#include <gtest/gtest.h>
#include <vector>

#include "../inc/continuous.h"


/* 
    Test fixture for ContainerCont
*/
class VectorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        /*
            Common setup code if needed 
        */
    }

    void TearDown() override
    {
        /*
            Common cleanup code if needed
        */
    }
};

/* 
    Test container creation
*/
TEST_F(VectorTest, Creation)
{
    ContainerCont<int> container;
    EXPECT_EQ(container.size(), 0);
    EXPECT_EQ(container.capacity(), 0);
}

/* 
    Test insertion at the end
*/
TEST_F(VectorTest, PushBack)
{
    ContainerCont<int> container;
    
    /* 
        Test regular push_back
    */
    container.push_back(1);
    EXPECT_EQ(container.size(), 1);
    EXPECT_EQ(container[0], 1);

    /* 
        Test multiple push_backs
    */
    container.push_back(2);
    container.push_back(3);
    EXPECT_EQ(container.size(), 3);
    EXPECT_EQ(container[1], 2);
    EXPECT_EQ(container[2], 3);

    /* 
        Test move semantics
    */
    ContainerCont<int> moveContainer;
    int value = 42;
    moveContainer.push_back(std::move(value));
    EXPECT_EQ(moveContainer[0], 42);
}

/* 
    Test insertion at specific position
*/
TEST_F(VectorTest, Insert)
{
    ContainerCont<int> container;
    container.push_back(1);
    container.push_back(3);

    /* 
        Insert in the middle
    */
    container.insert(1, 2);
    EXPECT_EQ(container.size(), 3);
    EXPECT_EQ(container[0], 1);
    EXPECT_EQ(container[1], 2);
    EXPECT_EQ(container[2], 3);

    /* 
        Insert at the beginning
    */
    container.insert(0, 0);
    EXPECT_EQ(container.size(), 4);
    EXPECT_EQ(container[0], 0);

    /* 
        Test move semantics
    */
    ContainerCont<int> moveContainer;
    moveContainer.push_back(2);
    int value = 1;
    moveContainer.insert(0, std::move(value));
    EXPECT_EQ(moveContainer[0], 1);
}

/* 
    Test removal
*/
TEST_F(VectorTest, Erase)
{
    ContainerCont<int> container;
    for(int i = 0; i < 5; ++i)
    {
        container.push_back(i);
    }

    /* 
        Erase from the middle
    */
    container.erase(2);
    EXPECT_EQ(container.size(), 4);
    EXPECT_EQ(container[2], 3);

    /* 
        Erase from the beginning
    */
    container.erase(0);
    EXPECT_EQ(container.size(), 3);
    EXPECT_EQ(container[0], 1);

    /* 
        Erase from the end
    */
    container.erase(container.size() - 1);
    EXPECT_EQ(container.size(), 2);
    EXPECT_EQ(container[container.size() - 1], 3);
}

/* 
    Test element access
*/
TEST_F(VectorTest, ElementAccess)
{
    ContainerCont<int> container;
    for(int i = 0; i < 5; ++i)
    {
        container.push_back(i);
    }

    /* 
        Test operator[]
    */
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(container[i], i);
    }

    /* 
        Test const operator[]
    */
    const ContainerCont<int>& constContainer = container;
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(constContainer[i], i);
    }
}

/* 
    Test size and capacity
*/
TEST_F(VectorTest, SizeAndCapacity)
{
    ContainerCont<int> container;
    EXPECT_EQ(container.size(), 0);
    EXPECT_EQ(container.capacity(), 0);

    container.push_back(1);
    EXPECT_EQ(container.size(), 1);
    EXPECT_GE(container.capacity(), 1);

    container.reserve(10);
    EXPECT_EQ(container.size(), 1);
    EXPECT_GE(container.capacity(), 10);
}

/* 
    Test copying
*/
TEST_F(VectorTest, Copying)
{
    ContainerCont<int> original;
    for(int i = 0; i < 5; ++i)
    {
        original.push_back(i);
    }

    /* 
        Test copy constructor
    */
    ContainerCont<int> copy(original);
    EXPECT_EQ(copy.size(), original.size());
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(copy[i], original[i]);
    }

    /* 
        Test copy assignment
    */
    ContainerCont<int> assigned;
    assigned = original;
    EXPECT_EQ(assigned.size(), original.size());
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(assigned[i], original[i]);
    }
}

/* 
    Test moving
*/
TEST_F(VectorTest, Moving)
{
    ContainerCont<int> original;
    for(int i = 0; i < 5; ++i)
    {
        original.push_back(i);
    }

    /* 
        Test move constructor
    */
    ContainerCont<int> moved(std::move(original));
    EXPECT_EQ(moved.size(), 5);
    EXPECT_EQ(original.size(), 0);
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(moved[i], i);
    }

    /* 
        Test move assignment
    */
    ContainerCont<int> assigned;
    assigned = std::move(moved);
    EXPECT_EQ(assigned.size(), 5);
    EXPECT_EQ(moved.size(), 0);
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(assigned[i], i);
    }
}

/* 
    Test iterators
*/
TEST_F(VectorTest, Iterators)
{
    ContainerCont<int> container;
    for(int i = 0; i < 5; ++i)
    {
        container.push_back(i);
    }

    /* 
        Test regular iterator
    */
    int expected = 0;
    for(auto it = container.begin(); it != container.end(); ++it)
    {
        EXPECT_EQ(*it, expected++);
    }

    /* 
        Test const iterator
    */
    const ContainerCont<int>& constContainer = container;
    expected = 0;
    for(auto it = constContainer.begin(); it != constContainer.end(); ++it)
    {
        EXPECT_EQ(*it, expected++);
    }

    /* 
        Test iterator-based insert
    */
    auto it = container.begin();
    ++it;
    container.insert(it, 10);
    EXPECT_EQ(container[0], 0);
    EXPECT_EQ(container[1], 10);
    EXPECT_EQ(container[2], 1);
    EXPECT_EQ(container[3], 2);
    EXPECT_EQ(container[4], 3);
    EXPECT_EQ(container[5], 4);

    /* 
        Test iterator-based erase
    */
    it = container.begin();
    ++it;
    container.erase(it);
    EXPECT_EQ(container[0], 0);
    EXPECT_EQ(container[1], 1);
    EXPECT_EQ(container[2], 2);
    EXPECT_EQ(container[3], 3);
    EXPECT_EQ(container[4], 4);
}

/* 
    Test clearing
*/
TEST_F(VectorTest, Clear)
{
    ContainerCont<int> container;
    for(int i = 0; i < 5; ++i)
    {
        container.push_back(i);
    }

    container.clear();
    EXPECT_EQ(container.size(), 0);
    EXPECT_EQ(container.capacity(), 0);
}

