//Matt Calayo mjc5gh 2/4/18 testPostfixCalc.cpp
#include "postfixCalculator.h"
#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    cout<<"Input postfix expression for calculation: "<<endl;
    PostfixCalculator p;
    string s;
    while(cin >> s){
      //cout << s <<endl;
      if(s.compare("+")==0){
	p.add();
	//	cout<<"adding!"<<endl;
    }
      else if(s.compare("-")==0){
	p.subtract();
	//	cout<<"subtracting!"<<endl;
      }
      else if(s.compare("*")==0){
	p.multiply();
	//	cout<<"multiplying!"<<endl;
      }
      else if(s.compare("/")==0){
	p.divide();
	//	cout<<"dividing!"<<endl;
      }
      else if(s.compare("~")==0){
	p.negate();
	//	cout<<"negating!"<<endl;
      }
      else{
	const char *cS = s.c_str();
	int in = atoi(cS);
	p.pushNum(in);
      }
    }
    cout << "Result is: " << p.getTop() << endl;
    
    return 0;
}
