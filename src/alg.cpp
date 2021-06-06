// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string str1 = "";
  while (!file.eof()) {
    char x = file.get();
    if ((x > 64) && (x < 91)) {
      str1 += (x + 32);
    } else if ((x > 96) && (x < 123)) {
      str1 += x;
    } else if (str1 != "") {
      tree.search2(str1);
      str1 = "";
    }
  }
  file.close();
  return tree;
}
