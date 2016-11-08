#include <iostream>
using std::cout; using std::endl;
#include "gtest/gtest.h"
#include "src/{Project_File_Here}.h"

class My{}Test : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  // virtual void TearDown() {}

};

/** Tests for {} class.
 *
 */

TEST_F(My{}Test, Construct{})
{
}

