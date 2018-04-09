//Matt Calayo mjc5gh 4/8/18 threexinput.cpp
#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone( int x);

int main(){
  timer t;
  int x,y;

  cout << "Enter x: ";
  cin >> x ;
  cout <<endl;
  cout << "Enter number of loops: ";
  cin >> y;

  t.start();
  for(int i = 0; i<y;i++){
    threexplusone(x);
  }
  t.stop();

  cout << "Number of steps: " << threexplusone(x) << endl;
  cout << "Time taken for " << y << " calls: " << t.getTime() << " seconds" << endl;
  
    
  return 0;
}
