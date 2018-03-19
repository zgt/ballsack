//Matt Calayo mjc5gh 1/25/18 List.cpp

#include <iostream>
#include "List.h"
using namespace std;

//default constructor
List::List() {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
  //cout << "List Default Constructor: " << *this <<endl;
}

List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
   if(count==0){
  return true;
  }
  else
   return false;
  
}

void List::makeEmpty(){
   if(!this->isEmpty()){
     ListItr *step = new ListItr(head->next);
     while(!(step->isPastEnd())){
       ListNode *cur = new ListNode();
       ListNode *prev = new ListNode();
       ListNode *next = new ListNode();
       cur = step->current;
       prev = cur->previous;
       next = cur->next;
       prev->next = next;
       next->previous = prev;
       step->moveForward();
     
  }
  }
}

ListItr List::first(){
  ListItr * retuItr = new ListItr(head->next);
  return *retuItr;
}

ListItr List::last(){
  ListItr * retuItr = new ListItr(tail->previous);
  return *retuItr;
}

void List::insertAfter(int x, ListItr position){
  ListNode *n = new ListNode();
  ListNode *pos = new ListNode();
  pos = position.current;
  ListNode *temp = pos->next;
  n->next = pos->next;
  n->previous = pos;
  temp->previous = n;
  pos->next = n;
  n->value = x;
  count++;
  
  
}

void List::insertBefore(int x, ListItr position){
  ListNode *n = new ListNode();
  ListNode *pos = new ListNode();
  pos = position.current;
  ListNode *temp = pos->previous;
  n->next =pos;
  n->previous = temp;
  temp->next = n;
  pos->previous = n;
  n->value=x;
  count++;

}

void List::insertAtTail(int x){
  ListNode *n = new ListNode();
  ListNode *prev = tail->previous;
  n->next = tail;
  n->previous = prev;
  tail->previous = n;
  prev->next = n;
  n->value = x;
  count++;
}

void List::remove(int x){
  ListItr finder =  find(x);
  ListNode *temp = new ListNode();
  ListNode *tempn = new ListNode();
  ListNode *tempp = new ListNode();
  temp = finder.current;
  tempn = temp->next;
  tempp = temp->previous;
  tempn->previous = tempp;
  tempp->next = tempn;
  delete temp;
}

ListItr List::find(int x){
   ListItr *finder = new ListItr(head);
   while(!(finder->isPastEnd())){
    if(finder->retrieve() == x){
      return *finder;
      break;
    }
    else
      finder->moveForward();
   }
}

int List::size() const {
  int coun = 0;
   ListItr *counter = new ListItr(head);
  while(!(counter->isPastEnd())){
    coun++;
    counter->moveForward();
  }
  return coun-1;
}

void printList(List& source, bool direction){
  if(direction){
    ListItr *start = new ListItr(source.first());
    while(!(start->isPastEnd())){
      cout << start->retrieve() << " " << endl;
      start->moveForward();
    }
  }
  else{
    ListItr *start = new ListItr(source.last());
    while(!(start->isPastBeginning())){
      cout << start->retrieve() << " " << endl;
      start->moveBackward();
    }
  }
}
