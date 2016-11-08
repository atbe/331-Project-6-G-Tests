#include <iostream>
using std::cout; using std::endl;
#include "gtest/gtest.h"
#include "src/MaxHeap.h"

class MyMaxHeapTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  // virtual void TearDown() {}

};

/** Tests for MaxHeap class.
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
 * myMaxHeap()
 *
 * percolateDown()
 * percolateUp()
 * heapCreate()
 *
 * HeapOverlow Exception
 * HeapUnderflow Exception
 */

TEST_F(MyMaxHeapTest, ConstructAMaxHeap)
{
}

