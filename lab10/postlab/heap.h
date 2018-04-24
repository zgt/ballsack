// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
//Matt Calayo mjc5gh 4/16/18 heap.h - slightly modified
#ifndef HEAP_H
#define HEAP_H
#include "huffmanNode.h"

#include <vector>
#include <iostream>

using namespace std;

class heap {
public:
    heap();
    heap(vector<huffmanNode*> vec);
    ~heap();

    void insert(huffmanNode* x);
    huffmanNode* findMin();
    huffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    vector<huffmanNode*> getVec();

private:
    vector<huffmanNode*> heapy;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
