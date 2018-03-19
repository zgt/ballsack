/*
 * Matt Calayo mjc5gh 1/25/18 List.h
 * Filename: List.h
 * Description: List class definition
 * 	also includes the prototype for non-member function print()
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;


class List {
public:
    List();				//Constructor
    // List(const List& source);	//Copy Constructor
    ~List();			//Destructor
    // List& operator=(const List& source);	//Equals Operator
    bool isEmpty() const;		//Returns true if empty; else false
    int getHead(); //returns the value of the head
    void insertAtHead(int x);	//Insert x at head of list
    void removeHead();		//Removes the head of list
private:
    ListNode *head;	//indicates beginning and end of the list
    int count;			//#of elements in list
};

#endif
/* end of List.h */
