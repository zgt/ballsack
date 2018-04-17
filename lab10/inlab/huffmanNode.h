//Matt Calayo mjc5gh 4/16/18 huffmanNode.h
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class huffmanNode{
 public:
  huffmanNode();
  huffmanNode(char x, int y);
  ~huffmanNode();
  huffmanNode *left, *right;
  char val;
  int freq;
  string bit;
};


bool operator<(const huffmanNode& n, const huffmanNode &n2);
bool operator>(const huffmanNode& n, const huffmanNode &n2);
#endif
