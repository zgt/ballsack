//Matt Calayo mjc5gh 2/6/18 stack.cpp

#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(){
  stakList = new List();
}

void stack::push(int e){
  stakList->insertAtHead(e);
}

int stack::top(){
  return stakList->getHead();
}

void stack::pop(){
  stakList->removeHead();
}

bool stack::isEmpty(){
  return stakList->isEmpty();
}
