#include <iostream>

class people{
public:
  people();

int value( int x, int y){
  return x + y;
}

int reference( int &x, int &y){
  return x+y;
}

int main(){
  int i=1;
  int j=2;
  int benis = value(i,j);
  int cenis = reference(i,j);
}
