//Matt Calayo mjc5gh inlab.cpp 2/14/18
#include <iostream>
using namespace std;

int main(){
  bool boo = true;
  char cha = 'g';
  int in = 123;
  double doubl = 9123871.0;
  int *inty = NULL;



  int IntArray[10];
  for(int i = 0;i<10;i++){
    IntArray[i]=i;
  }
  
  char CharArray[10];
  for(int i = 0; i<10;i++){
    CharArray[i]= 'a';
  }
  char CharArray2D[6][5];
  int IntArray2D[6][5];
    for(int j = 0; j<6;j++){
      for(int k = 0; k<5;k++){
	CharArray2D[j][k] = 'a';
	IntArray2D[j][k] = (j+1) * (k+1);
	cout << "j: " << j << endl;
	cout << "k: " << k << endl;
	cout << "Array " << IntArray2D[j][k] << endl;
      }
    }

  cout << "bool: " << boo << endl;
  cout << "char: " << cha << endl;
  cout << "int: " << in << endl;
  cout << "double: " << doubl << endl;
  cout << "int pointer: " << inty << endl;
  cout << "hey"<<endl;
  return 0;
}
