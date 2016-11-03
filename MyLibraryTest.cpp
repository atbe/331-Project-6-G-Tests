#include <iostream>
using std::cout; using std::endl;
#include "gtest/gtest.h"
#include "src/Library.h"

class MyLibraryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  // virtual void TearDown() {}

  Library library;
};

/** Tests for Library class.
 *
 * Search for book.
 * Add book to library.
 * Check in a book.
 * Check out a book.
 *
 */

/** minstack::getMin()
 *
 * Check to see if stack stays empty when expected.
 */
TEST_F(MyLibraryTest, ConstructALibrary)
{
    Library l;
}

