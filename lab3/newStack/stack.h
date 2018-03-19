//Matt Calayo mjc5gh 2/6/18 stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "ListNode.h"
#include "List.h"
using namespace std;

class stack{
 public:
  stack();
  void push(int e);
  int top();
  void pop();
  bool isEmpty();

 private:
  List *stakList;
};
#endif
  
