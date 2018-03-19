//Matt Calayo mjc5gh 3/1/18 AVLTree.cpp
#include "AVLTree.h"
#include <string>

using namespace std;

// Implement the following
AVLNode::AVLNode() {
  value = "";
  left = NULL;
  right = NULL;
  height = 0;
  
}
AVLTree::AVLTree() {
  root = NULL;
  nodeCount=0;
}
AVLTree::~AVLTree() {
   empty();
}
void AVLTree::insert(const string& x) {
  insert(x, root);
  nodeCount++;
}
string AVLTree::pathTo(const string& x) const {
  return pathTo(x,root);
}
bool AVLTree::find(const string& x) const {
  return find(x,root);
}
int AVLTree::numNodes() const {
  return nodeCount;
}
void AVLTree::balance(AVLNode*& n) {
  int bal = balanceFactor(n);
  if(bal>1){
    if(balanceFactor(n->left)>0){
      rotateLeft(n);
    }
    else{
      doubleRotateLeft(n);
    }
  }
  else if(bal<-1){
    if(balanceFactor(n->right)>0){
      doubleRotateRight(n);
    }
    else{
      rotateRight(n);
    }
  }
}
void AVLTree::rotateLeft(AVLNode* &n) const{
  AVLNode *n2 = n->left;
  n->left = n2->right;
  n2->right = n;
  n->height = max(height(n->right),height(n->left))+1;
  n2->height = max(n->height,height(n2->left))+1;
  n = n2;
}

void AVLTree::rotateRight(AVLNode*& n) const{
  AVLNode *n2 = n->right;
  n->right = n2->left;
  n2->left = n;
  n->height = max(height(n->left),height(n->right))+1;
  n2->height = max(n->height, height(n2->right))+1;
  n = n2;
}

void AVLTree::doubleRotateLeft(AVLNode* &n) const{
  rotateRight(n->left);
  rotateLeft(n);
}

void AVLTree::doubleRotateRight(AVLNode* &n) const{
  rotateLeft(n->right);
  rotateRight(n);
}

void AVLTree::insert(const string& x, AVLNode* &r){
  if(r==NULL){
    r = new AVLNode();
    r->value = x;
  }
  else if(r->value > x){
    insert(x, r->left);
    if( height(r->left) - height(r->right)==2){
      if(x < r->left->value){
	rotateLeft(r);
      }
      else{
	doubleRotateLeft(r);
      }
    }
  }
  else if(x>r->value){
    insert(x,r->right);
    if(height(r->right)-height(r->left)==2){
      if(x>r->right->value){
	rotateRight(r);
      }
      else{
	doubleRotateRight(r);
      }
    }
  }
  r->height = 1 + max(height(r->left), height(r->right));
   balance(r);
}
string AVLTree::pathTo(const string& x, AVLNode *r) const{
  if(!find(x)){
    return "";
    }
   if(r->value==x){
    return r->value;
  }
  else if(r->value > x){
    return (r->value +  " " + pathTo(x, r->left));
  }
  else if(r->value <x){
    return (r->value + " " +  pathTo(x, r->right));
  }
  else{
    return "";
  }
}

bool AVLTree::find(const string& x, AVLNode *r) const{
  if(r==NULL){
    return false;
  }
  else if(r->value==x){
    return true;
  }
  else if(r->value > x){
   return find(x, r->left);
  }
  else if(r->value < x){
    return find(x, r->right);
  }
  else{
    return false;
  }
}

// The following are implemented for you
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x);
  nodeCount--;}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      return NULL;
    }
    // single child
   if (n->left == NULL) {
      return n->right;
    }
    if (n->right == NULL) {
      return n->left;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

void AVLTree::empty(){
  empty(root);
}

void AVLTree::empty(AVLNode* &r){
  if(r != NULL){
    empty(r->left);
    empty(r->right);
    delete r;
  }
  r= NULL;
}

int AVLTree::balanceFactor(AVLNode* &r){
  int leftH = height(r->left);
  int rightH = height(r->right);
  int bFact = leftH - rightH;
  return bFact;
}
