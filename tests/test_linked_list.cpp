#include <gtest/gtest.h>
#include <vector>

#include "../inc/linked_singly.h"


/* 
    Test fixture for ContainerListSingly
*/
class LinkedListTest : public ::testing::Test
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
TEST_F(LinkedListTest, Creation)
{
    ContainerListSingly<int> container;
    EXPECT_EQ(container.size(), 0);
}

/* 
    Test insertion at the end
*/
TEST_F(LinkedListTest, PushBack)
{
    ContainerListSingly<int> container;
    
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
    ContainerListSingly<int> moveContainer;
    int value = 42;
    moveContainer.push_back(std::move(value));
    EXPECT_EQ(moveContainer[0], 42);
}

/* 
    Test insertion at specific position
*/
TEST_F(LinkedListTest, Insert)
{
    ContainerListSingly<int> container;
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
    ContainerListSingly<int> moveContainer;
    moveContainer.push_back(2);
    int value = 1;
    moveContainer.insert(0, std::move(value));
    EXPECT_EQ(moveContainer[0], 1);
}

/* 
    Test removal
*/
TEST_F(LinkedListTest, Erase)
{
    ContainerListSingly<int> container;
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
TEST_F(LinkedListTest, ElementAccess)
{
    ContainerListSingly<int> container;
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
    const ContainerListSingly<int>& constContainer = container;
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(constContainer[i], i);
    }
}

/* 
    Test copying
*/
TEST_F(LinkedListTest, Copying)
{
    ContainerListSingly<int> original;
    for(int i = 0; i < 5; ++i)
    {
        original.push_back(i);
    }

    /* 
        Test copy constructor
    */
    ContainerListSingly<int> copy(original);
    EXPECT_EQ(copy.size(), original.size());
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(copy[i], original[i]);
    }

    /* 
        Test copy assignment
    */
    ContainerListSingly<int> assigned;
    assigned = original;
    EXPECT_EQ(assigned.size(), original.size());
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(assigned[i], original[i]);
    }
}

/* 
    Test move semantics (including move ctor)
*/
TEST_F(LinkedListTest, Moving)
{
    ContainerListSingly<int> original;
    for(int i = 0; i < 5; ++i)
    {
        original.push_back(i);
    }

    /* 
        Test move constructor
    */
    ContainerListSingly<int> moved(std::move(original));
    EXPECT_EQ(moved.size(), 5);
    EXPECT_EQ(original.size(), 0);
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(moved[i], i);
    }

    /* 
        Test move assignment
    */
    ContainerListSingly<int> assigned;
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
TEST_F(LinkedListTest, Iterators) 
{
    ContainerListSingly<int> container;
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
    const ContainerListSingly<int>& constContainer = container;
    expected = 0;
    for(auto it = constContainer.begin(); it != constContainer.end(); ++it)
    {
        EXPECT_EQ(*it, expected++);
    }

    /* 
        Test iterator-based insert
    */
    auto it = container.begin();
    EXPECT_EQ(*it, 0);
    EXPECT_EQ(it.getValue(), 0);
    
    ++it;
    EXPECT_EQ(*it, 1);
    EXPECT_EQ(it.getValue(), 1);
    
    auto newIt = container.insert(it, 10);
    EXPECT_EQ(*newIt, 10);
    EXPECT_EQ(newIt.getValue(), 10);
    EXPECT_EQ(container[1], 10);

    /* 
        Test iterator-based erase
    */    
    container.clear();
    for(int i = 0; i < 5; ++i)
    {
        container.push_back(i);
    }

    /* 
        Verify initial state
    */
    EXPECT_EQ(container.size(), 5);
    for(int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(container[i], i);
    }

    /* 
        Test erasing from middle
    */
    it = container.begin();
    ++it;  // Points to 1
    
    auto nextIt = container.erase(it);  // Should point to 2
            
    EXPECT_EQ(container.size(), 4);
    EXPECT_EQ(container[0], 0);
    EXPECT_EQ(container[1], 2);
    EXPECT_EQ(container[2], 3);
    EXPECT_EQ(container[3], 4);
    
    EXPECT_EQ(*nextIt, 2);
    
    it = nextIt;
    EXPECT_EQ(*it, 2);
    
    /* 
        Test second erase
    */
    nextIt = container.erase(it);
    
    EXPECT_EQ(container.size(), 3);
    EXPECT_EQ(container[0], 0);
    EXPECT_EQ(container[1], 3);
    EXPECT_EQ(container[2], 4);
    EXPECT_EQ(*nextIt, 3);

    /* 
        Test erasing from beginning
    */
    it = container.begin();
    
    nextIt = container.erase(it);

    EXPECT_EQ(container.size(), 2);
    EXPECT_EQ(container[0], 3);
    EXPECT_EQ(container[1], 4);
    EXPECT_EQ(*nextIt, 3);

    /* 
        Test erasing from end
    */
    it = container.begin();
    ++it;
    
    nextIt = container.erase(it);
    
    EXPECT_EQ(container.size(), 1);
    EXPECT_EQ(container[0], 3);
    EXPECT_EQ(nextIt, container.end());
}

/* 
    Test clearing
*/
TEST_F(LinkedListTest, Clear)
{
    ContainerListSingly<int> container;
    for(int i = 0; i < 5; ++i)
    {
        container.push_back(i);
    }

    container.clear();
    EXPECT_EQ(container.size(), 0);
}


