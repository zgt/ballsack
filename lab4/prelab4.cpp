//Matt Calayo mjc5gh 2/11/18 prelab4.cpp
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void sizeOfTest(){
  int *i = new int;
  char *c = new char;
  double *d = new double;
  cout << "Type: int Size: " << sizeof(int)<<endl;
  cout << "Type: unsigned int Size: " << sizeof(unsigned int)<<endl;
  cout << "Type: float Size: " << sizeof(float)<<endl;
  cout << "Type: double Size: " << sizeof(double)<<endl;
  cout << "Type: char Size: " <<sizeof(char)<<endl;
  cout << "Type: bool Size: " << sizeof(bool)<<endl;
  cout << "Type: pointer int Size: " << sizeof(i)<<endl;
  cout << "Type: pointer char Size: " << sizeof(c)<<endl;
  cout << "Type: pointer double Size: " <<sizeof(d)<<endl;
}

void outputBinary(unsigned int x){
  string out;
  int rem;
  unsigned int div = x;
  while(div != 0){
    if( div % 2 == 0){
      out.insert(0,"0");
    }
  else{
    out.insert(0,"1");
    }
    div = div/2;
  }
  while(out.length()<32){
    out.insert(0,"0");
  }
  for(int i = 4; i<39;i = i+5){
    out.insert(i," ");
  }
  cout << " " << endl;
  cout << "The binary representation of " << x << " is: " << out << endl;
}
    
void overflow(){
  unsigned int over = 4294967295;
  cout << " " << endl;
  cout << "Max unsigned int value: " << over << endl;
  over = over + 1;
  cout << "Max unsigned int after adding 1: " << over << endl;
  cout << "When 1 is added to an unsigned int it adds 1 to the binary representation of the number.For example if there is 4 bit data type,"<<endl;
  cout << "then the maximum value that can be held is 1111. If 1 is added to this value then"<<endl;
  cout << "the result would be 10000. If the data type is 4 bit then only the last 4 zeros would be" <<endl;
  cout << "read resulting in the value being 0000. This is an integer overflow and causes the value" << endl;
  cout << "to turn to 0."<<endl;
}
	
	  
      

int main(){
  sizeOfTest();
  string input;
  int intput;
  cout << "Input integer to be converted to binary: ";
  cin >> input;
  intput = atoi(input.c_str());
  outputBinary(intput);
  overflow();
  return 0;
}
