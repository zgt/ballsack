/*
 * Matt Calayo mjc5gh 1/25/18 ListNode.h
 * Filename: ListNode.h
 * Description: ListNode class definition
 */

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();                 // Constructor

private:
    int value;
    ListNode *next;	// for doubly linked lists

    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class List;
};

#endif
