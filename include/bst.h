// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <minmax.h>

template<typename T>
class BST {
private:
  struct dot {
    T t;
    dot* left;
    dot* right;
    int count;
    dot(T m) :left(nullptr), right(nullptr), count(1) {
      t = m;
    }
  };
  dot* root;

public:
  BST() : root(nullptr) {};

  void insert(T m) {
    root = insert(root, m);
  }

  int search(std::string x) {
    dot* y = root;
    while (y != nullptr) {
      if (x == y->t) {
        return y->count;
      }
      else if (x > y->t) {
        y = y->right;
      }
      else {
        y = y->left;
      }
    }
    return 0;
  }

  void search2(std::string x) {
    if (root == nullptr) {
      root = new dot(x);
      return;
    }
    dot* y = root;
    while (y != nullptr) {
      if (x == y->t) {
        y->count++;
        return;
      } else if (x > y->t) {
        if (y->right == nullptr) {
          y->right = new dot(x);
          return;
        } else {
          y = y->right;
        } 
      } else {
        if (y->left == nullptr) {
          y->left = new dot(x);
          return;
        } else {
          y = y->left;
        }
      }
    }
    return;
  }

  int depth() {
    return hight(root) - 1;
  }

  int hight(dot* p) {
    if ((p->left != nullptr) && (p->right != nullptr)) {
      return max(hight(p->left), hight(p->right)) + 1;
    } else if (p->left != nullptr) {
      return hight(p->left) + 1;
    } else if (p->right != nullptr) {
      return hight(p->right) + 1;
    } else {
      return 1;
    }
  }
};

#endif  // INCLUDE_BST_H_
