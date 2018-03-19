//Matt Calayo mjc5gh 2/4/18 postfixCalculator.cpp
#include "postfixCalculator.h"
#include "stack.h"
#include <cstdlib>
using namespace std;

PostfixCalculator::PostfixCalculator() {
  stack stak;
}

void PostfixCalculator::add() {
  int num1 = stak.top();
  stak.pop();
  int num2 = stak.top();
  stak.pop();
  int num3 = num1 + num2;
  stak.push(num3);
}

void PostfixCalculator::subtract() {
  int num1 = stak.top();
  stak.pop();
  int num2 = stak.top();
  stak.pop();
  int num3 = num2 - num1;
  stak.push(num3);
}

void PostfixCalculator::multiply(){
  int num1 = stak.top();
  stak.pop();
  int num2 = stak.top();
  stak.pop();
  int num3 = num2 * num1;
  stak.push(num3);
}

void PostfixCalculator::divide(){
  int num1 = stak.top();
  stak.pop();
  int num2 = stak.top();
  stak.pop();
  int num3 = num2 / num1;
  stak.push(num3);
}

void PostfixCalculator::negate(){
  int num1 = stak.top();
  stak.pop();
  int num2 = num1 * -1;
  stak.push(num2);
}

void PostfixCalculator::pushNum(int e){
  stak.push(e);
}

int PostfixCalculator::getTop(){
  return stak.top();
}

void PostfixCalculator::popNum(){
  stak.pop();
}

bool PostfixCalculator::isEmpty(){
  return stak.isEmpty();
}
