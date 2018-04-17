// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
//Matt Calayo mjc5gh 4/16/18 heap.cpp - slightly modified
#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heapy.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> vec) : heap_size(vec.size()) {
    heapy = vec;
    heapy.push_back(heapy[0]);
    heapy[0] = new huffmanNode;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* x) {
    // a vector push_back will resize as necessary
    heapy.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode* x = heapy[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < heapy[hole/2]->freq); hole /= 2 )
        heapy[hole] = heapy[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    heapy[hole] = x;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    huffmanNode* ret = heapy[1];
    // move the last inserted position into the root
    heapy[1] = heapy[heap_size--];
    // make sure the vector knows that there is one less element
    heapy.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode* x = heapy[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && ((heapy[child+1])->freq < ((heapy[child])->freq)) )
            child++;
        // if the child is greater than the node...
        if ( x->freq > (heapy[child])->freq ) {
            heapy[hole] = heapy[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heapy[hole] = x;
}
huffmanNode* heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return heapy[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heapy.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heapy[0] << ") ";
    cout <<"\t";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << heapy[i]->val << " ";
        // next line from from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}

vector<huffmanNode*> heap::getVec(){
  return heapy;
}
