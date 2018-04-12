#include <iostream>

using namespace std;

template <class tType>
tType minimum( tType x, tType y){
  tType ret;
  ret = (x<y)? x:y;
  return ret;
}

int main(){
  int a=10,b=5,c;
  long x=20,y=50,z;
  c=minimum<int>(a,b);
  z=minimum<long>(x,y);
  cout <<c<<endl;
  cout <<z<<endl;

  return 0;
}
