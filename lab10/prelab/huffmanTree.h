//Matt Calayo mjc5gh 4/16/18 huffmanTree.h
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "huffmanNode.h"
#include "heap.h"

using namespace std;

class huffmanTree{
 public:
  huffmanTree();
  ~huffmanTree();
  huffmanNode *root;
  heap createHeap(heap h);
  huffmanNode* combine(huffmanNode* a, huffmanNode* b);
  // void printPrefix();
  void printPrefix(huffmanNode* n, string pre);
  void preset(huffmanNode* n, string pre);
};
#endif
