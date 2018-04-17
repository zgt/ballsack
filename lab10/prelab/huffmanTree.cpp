//Matt Calayo mjc5gh 4/16/18 huffmanTree.cpp
#include "huffmanTree.h"
#include <cstdlib>

using namespace std;

huffmanTree::huffmanTree(){
  root = NULL;
}

huffmanTree::~huffmanTree(){
  delete root;
}


heap huffmanTree::createHeap(heap h){
  while(h.size()>1){
    huffmanNode* a =  h.findMin();
    h.deleteMin();
    huffmanNode* b = h.findMin();
    h.deleteMin();
    huffmanNode* c = combine(a,b);
    h.insert(c);
  }
  return h;
}


huffmanNode* huffmanTree::combine(huffmanNode* a, huffmanNode* b){
  int f1 = a->freq;
  int f2 = b->freq;
  int f3 = f1+f2;
  huffmanNode* c = new huffmanNode('z', f3);
  c->left = a;
  c->right = b;
  return c;
}
/*
void huffmanTree::printPrefix(){
  printPrefixNode(root,"");
  }*/

void huffmanTree::printPrefix(huffmanNode* n, string pre){
  if(n->left==NULL&&n->right==NULL){
    cout<<n->val<<" "<<pre<<endl;
  }
  if(n->left!=NULL){
    printPrefix(n->left, pre+"0");
  }
  if(n->right!=NULL){
    printPrefix(n->right, pre+"1");
  }
}

void huffmanTree::preset(huffmanNode* n, string pre){
  if(n->left==NULL&&n->right==NULL){
    n->bit=pre;
  }
  if(n->left!=NULL){
    preset(n->left, pre+"0");
  }
  if(n->right!=NULL){
    preset(n->right, pre+"1");
  }
}
