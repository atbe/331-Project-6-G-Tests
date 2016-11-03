#include <iostream>
#include <string>

using namespace std;
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

struct Book {
  Book() = delete;
  Book(string _isbn, string _title, string _author) : isbn(_isbn), title(_title), author(_author) {};

  string isbn;
  string title;
  string author;

  bool operator<(const Book &other) { return isbn < other.isbn; };
  bool operator==(const Book &other) { return isbn == other.isbn; };
  bool operator!=(const Book &other) { return isbn != other.isbn; };

};

class Library {
 public:
  Library();
  void add(Book);
  void check_in(Book);
  Book *check_out(Book);
  Book *search(Book);
  long available_copies(Book);

 private:
  struct BookNode {
    Book value;
    BookNode *left;
    BookNode *right;
    size_t count = 1;
    BookNode(Book b) : value(b), left(nullptr), right(nullptr) {};
  };
  BookNode *root;
  void add(BookNode *&root_node, BookNode *&new_node);
  BookNode *search(Book, BookNode *root);
};

#endif //LIBRARY_LIBRARY_H
