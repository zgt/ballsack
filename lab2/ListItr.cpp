//Matt Calayo mjc5gh 1/25/18 ListItr.cpp
#include <iostream>
#include "ListItr.h"
#include "List.h"
#include "ListNode.h"

ListItr::ListItr(){
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

bool ListItr::isPastEnd() const{
  return (current->next==NULL&&current!=NULL);
}

bool ListItr::isPastBeginning() const{
  return (current->previous==NULL&&current->next!=NULL);
}

void ListItr::moveForward(){
  if(current!=NULL){
    current = current->next;
}
}

void ListItr::moveBackward(){
  if(current!=NULL){
    current = current->previous;
}
}

int ListItr::retrieve() const{
  return current->value;
}
