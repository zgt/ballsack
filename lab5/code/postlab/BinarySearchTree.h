//Matt Calayo mjc5gh 3/1/18 BinarySearchTree.h
#ifndef BST_H
#define BST_H
#include <string>

using namespace std;

class BinaryNode {
  BinaryNode();

  string value;
  BinaryNode* left;
  BinaryNode* right;

  friend class BinarySearchTree;
};

class BinarySearchTree {
 public:
  BinarySearchTree();
  ~BinarySearchTree();

  // insert finds a position for x in the tree and places it there.
  void insert(const string& x);
  // remove finds x's position in the tree and removes it.
  void remove(const string& x);

  // pathTo finds x in the tree and returns a string representing the path it
  // took to get there.
  string pathTo(const string& x) const;
  // find determines whether or not x exists in the tree.
  bool find(const string& x) const;
  // numNodes returns the total number of nodes in the tree.
  int numNodes() const;

  void empty();

 private:
  int nodeCount;
  BinaryNode* root;

  void insert(const string& x, BinaryNode* &r);
  void remove(const string& x, BinaryNode* &r);
  BinaryNode* getMin(BinaryNode *r);
  BinaryNode* getMax(BinaryNode *r);
  bool find(const string& x, BinaryNode* r) const;
  string pathTo(const string& x, BinaryNode* r) const;
  void empty(BinaryNode* &r) const;
};

#endif
