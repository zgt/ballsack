//Matt Calayo mjc5gh 2/15/18 bitCounter.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

int bitCount(int num){
  if(num==0)
    return 0;
  else if(num & 1){
    return 1 + bitCount(num>>1);
  }
  else{
    return bitCount(num>>1);
  }
}

int main(int argc, char *argv[]){
  int in = atoi(argv[1]);
  cout << bitCount(in)<<endl;
  return 1;
}
