//Matt Calayo mjc5gh 2/4/18 postfixCalculator.h
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
#include <cstdlib>
using namespace std;

class PostfixCalculator {
 public:
  PostfixCalculator();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  void pushNum(int e);
  int getTop();
  void popNum();
  bool isEmpty();

 private:
  stack stak;
};
#endif
