#include <iostream>
using std::cout; using std::endl;
#include "gtest/gtest.h"
#include "src/Library.h"

class MyLibraryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
      Book hamlet("978-0743477123", "Hamlet", "William Shakespeare");
      Book macbeth("978-0743477109", "Macbeth", "The Bard");
      Book macbeth2("99", "Macbeth", "The Bard");
      Book macbeth3("99", "Macbeth", "The Bard");
      l.add(hamlet);
      l.add(hamlet);
      l.add(hamlet);
      l.add(hamlet);
      l.add(macbeth);
      l.add(macbeth2);
      l.add(macbeth3);
  }

  // virtual void TearDown() {}

  Library l;
};

/** Tests for Library class.
 *
 * Search for book.
 * Add book to library.
 * Check in a book.
 * Check out a book.
 *
 */

TEST_F(MyLibraryTest, ConstructALibrary)
{
    Library l;
}

TEST_F(MyLibraryTest, SearchForBook)
{
    Book hamlet("978-0743477123", "Hamlet", "William Shakespeare");
    ASSERT_NE(nullptr, l.search(hamlet)) << "Ensure hamlet can be found using search.";

    Book ham("123", "ju", "li");
    ASSERT_EQ(nullptr, l.search(ham)) << "Nullptr should be returned when searching for a book that is not in the library.";
}

TEST_F(MyLibraryTest, CheckBookCount)
{
    Book hamlet("978-0743477123", "Hamlet", "William Shakespeare");
    ASSERT_EQ(4, l.available_copies(hamlet)) << "The number of copies should be 4 after adding a book 4 times.";

    Book ham("123", "ju", "li");
    ASSERT_EQ(0, l.available_copies(ham)) << "The number of available copies for a book not in the library should be 0.";
}

TEST_F(MyLibraryTest, CheckoutBook)
{
    Book hamlet("978-0743477123", "Hamlet", "William Shakespeare");
    auto checkedOutBook = l.check_out(hamlet);
    ASSERT_NE(nullptr, checkedOutBook) << "Checking out a book that has a count >= 1 should not return nullptr.";
    ASSERT_EQ(3, l.available_copies(hamlet)) << "The count on a book that is checked out should be decremented by 1.";

    Book ham("123", "ju", "li");
    auto checkedOutBookBad = l.check_out(ham);
    ASSERT_EQ(nullptr, checkedOutBookBad) << "Attempting to checkout a book that is not in the library should return nullptr.";
    ASSERT_EQ(0, l.available_copies(ham)) << "The count on a book that is not in the library should be 0.";
}

TEST_F(MyLibraryTest, CheckinBook)
{
    Book hamlet("978-0743477123", "Hamlet", "William Shakespeare");
    l.check_in(hamlet);
    ASSERT_EQ(5, l.available_copies(hamlet)) << "Checking in a book should increment its count by 1.";

    Book ham("123", "ju", "li");
    l.check_in(ham);
    ASSERT_EQ(0, l.available_copies(ham)) << "Checking in a book that does not belong to the library should not add it to the library. To check this we check how many copies of that book we have and it should be 0.";
}

