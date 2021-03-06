//Matt Calayo mjc5gh 1/25/18 List.cpp

#include <iostream>
#include "List.h"
using namespace std;

//default constructor
List::List() {
  head = new ListNode();
  count = 0;
}


List::~List(){
  delete head;
}


bool List::isEmpty() const{
   if(count==0)
     return true;
   else
     return false;
  
}

int List::getHead(){
  return head->value;
}

void List::insertAtHead(int x){
  ListNode *n = new ListNode();
  ListNode *nxt = head;
  n->next = nxt;
  n->value = x;
  head = n;
  count++;
  
}

void List::removeHead(){
  ListNode *del = new ListNode();
  del = head;
  head = head->next;
  delete del;
  count--;
}

