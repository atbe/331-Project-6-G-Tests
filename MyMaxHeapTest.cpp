#include <iostream>
using std::cout; using std::endl;
#include "gtest/gtest.h"
#include "src/MaxHeap.h"
#include <vector>
using std::vector;
#include <cmath>
#include <algorithm>

class MyMaxHeapTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  // virtual void TearDown() {}

  vector<int> sampleData{2, 3, 1, 1, 45, 102, -12, 0, 42, 11, 420, 1738, 7, 9};
  myMaxHeap<int> filledHeap{sampleData};
  myMaxHeap<int> emptyHeap;
};

/** Tests for MaxHeap ADT.
 *
 * isEmpty()
 * getIndex()
 * display()
 * getHeight()
 * getNumberOfNodes()
 * clear()
 * peekTop()
 * add()
 * remove()
 * increaseKey()
 * decreaseKey()
 *
 * HeapUnderflow Exception
 *
 * Each TEST_F tests a single function and its
 * behaviours on corner cases.
 */

TEST_F(MyMaxHeapTest, ConstructAMaxHeap)
{
    ASSERT_TRUE(emptyHeap.isEmpty()) << "Default intialized heap is implicitly empty.";
    ASSERT_FALSE(filledHeap.isEmpty()) << "Heap intialized with a vector of elements is not empty.";
    ASSERT_EQ(1738, filledHeap.peekTop()) << "Top of the heap should be the largest element.";
}

TEST_F(MyMaxHeapTest, GetHeight)
{
    ASSERT_EQ(0, emptyHeap.getHeight()) << "Default intialized heap is implicitly empty.";
    ASSERT_EQ((int)std::log2(sampleData.size()), filledHeap.getHeight()) << "Default intialized heap is implicitly empty.";
}

TEST_F(MyMaxHeapTest, GetNumberOfNodes)
{
    ASSERT_EQ(0, emptyHeap.getNumberOfNodes()) << "Empty heap should have 0 nodes.";
    ASSERT_EQ(sampleData.size(), filledHeap.getNumberOfNodes()) << "Filled heap should report the correct number of nodes.";
}

TEST_F(MyMaxHeapTest, RemoveItem)
{
    filledHeap.remove();
    ASSERT_EQ(420, filledHeap.peekTop()) << "Removing the top item promotes the second largest item to the root";
    ASSERT_EQ(sampleData.size() - 1, filledHeap.getNumberOfNodes()) << "Removing a node should decrease the number of nodes.";

    // Remove once more just to be sure
    filledHeap.remove();
    ASSERT_EQ(102, filledHeap.peekTop()) << "Removing the top item promotes the second largest item to the root";

    // Test remove when only one item is present.
    emptyHeap.add(99);
    emptyHeap.remove();
    // Removing from an empty heap should throw an error
    try
    {
        emptyHeap.remove();
        FAIL() << "Removing on an empty heap should throw an exception";
    } catch (...) {} // Need the catch block regardless
}

TEST_F(MyMaxHeapTest, AddItem)
{
    filledHeap.add(1739);
    ASSERT_EQ(1739, filledHeap.peekTop()) << "Removing the top item promotes the second largest item to the root";
    emptyHeap.add(111);
    ASSERT_EQ(111, emptyHeap.peekTop()) << "Adding an item to an empty heap should go to the top.";
}

TEST_F(MyMaxHeapTest, IncreaseKeyPriority)
{
    filledHeap.increaseKey(8, 2016);
    ASSERT_EQ(2016, filledHeap.peekTop()) << "Increasing a key to the highest value should make it the top value.";

    // testing for negative increaseKey value
    filledHeap.increaseKey(8, -2016);
    ASSERT_EQ(2016, filledHeap.peekTop()) << "Increasing a key priority by a negative value should have no effect.";
}

TEST_F(MyMaxHeapTest, DecreaseKeyPriority)
{
    filledHeap.decreaseKey(1, 5);
    ASSERT_EQ(1733, filledHeap.peekTop()) << "Decreasing a key to the highest value should make it the top value.";

    // testing for negative decreaseKey value
    filledHeap.decreaseKey(1, -5);
    ASSERT_EQ(1733, filledHeap.peekTop()) << "Decreasing a key by a negative value should have no effect.";
}

TEST_F(MyMaxHeapTest, GetIndex)
{
    ASSERT_EQ(1738, filledHeap.getItem(1)) << "Increasing a key to the highest value should make it the top value.";
    //
    // Getting any index from an empty heap should throw an error
    try
    {
        emptyHeap.getItem(1);
        FAIL() << "getItem on an empty heap should throw an exception.";
    } catch (...) {}
}

TEST_F(MyMaxHeapTest, Display)
{
    // Displaying an empty heap should throw an exception (according to the Professors Piazza post).
    try
    {
        emptyHeap.display();
        FAIL() << "Displaying an empty heap should throw an exception.";
    } catch (...) {}
}

TEST_F(MyMaxHeapTest, Clear)
{
    // Clear and check that num of nodes is 0
    filledHeap.clear();
    ASSERT_EQ(0, filledHeap.getNumberOfNodes());

    emptyHeap.clear();
    ASSERT_EQ(0, emptyHeap.getNumberOfNodes());
}

TEST_F(MyMaxHeapTest, PeekTop)
{
    ASSERT_EQ(1738, filledHeap.peekTop()) << "Peek top should return the largest item.";

    try
    {
        emptyHeap.peekTop();
        FAIL() << "Peektop on empty heap should throw an exception";
    } catch (...) {}
}
