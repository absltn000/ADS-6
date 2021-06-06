// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template<typename T>
class BST {
 private:
  struct dot {
    T t;
    unsigned char height;
    dot* left;
    dot* right;
    int count;
    dot(T m) : height(1), left(nullptr), right(nullptr), count(1) {
     t = m;
    }
  }
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
      } else if (x > y->t) {
        y = y->right;
      } else {
        y = y->left;
      }
    }
    return 0;
  }

  int search2(std::string x) {
    dot* y = root;
    while (y != nullptr) {
      if (x == y->t) {
        y->count++;
        return y->count;
      } else if (x > y->t) {
        y = y->right;
      } else {
        y = y->left;
      }
    }
    root = insert(root, x);
    return 0;
  }

  int depth() {
    return height1(root);
  }

 private:
  unsigned char height1(dot* p) {
    return p ? p->height:0;
  }

  int bfactor(dot* p) {
    return height1(p->right) - height1(p->left);
  }

  void fixheight(dot* p) {
    unsigned char hl = height1(p->left);
    unsigned char hr = height1(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
  }

  dot* rotateright(dot* p) {
    dot* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
  }

  dot* rotateleft(dot* q) {
    dot* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
  }

  dot* balance(dot* p) {
    fixheight(p);
    if (bfactor(p) == 2) {
      if (bfactor(p->right) < 0)
        p->right = rotateright(p->right);
      return rotateleft(p);
    }
    if (bfactor(p) == -2) {
      if (bfactor(p->left) > 0)
        p->left = rotateleft(p->left);
      return rotateright(p);
    }
    return p;
  }

  dot* insert(dot* p, T m) {
    if (!p) return new dot(m);
    if (m < p->t)
      p->left = insert(p->left, m);
    else
      p->right = insert(p->right, m);
    return balance(p);
  }
};

#endif  // INCLUDE_BST_H_
