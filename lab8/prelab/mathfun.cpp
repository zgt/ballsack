//Matt Calayo mjc5gh 3/26/18 mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product(int, int);
extern "C" int power(int,int);

int main(){

  int prod, x, y;
  int prod2, x2, y2;

  cout << "Enter two numbers to be multiplied: ";
  cin >> x;
  cin >> y;

  cout << "2 nums for power x^y";
  cin >> x2;
  cin >> y2;

  if(x<=0||y<=0){
    cerr<< "gimme positive numbers";
    return 1;
  }
  if(x2<=0||y2<=0){
    cerr<< "gimme positive numbers";
    return 1;
  }

  prod = product(x,y);
  cout << "product of " << x << " and "<< y << " is: " << prod <<endl;

  prod2 = power(x2,y2);
  cout << prod2<<endl;
  

  return 0;
}
