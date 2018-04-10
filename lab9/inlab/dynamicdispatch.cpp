#include <iostream>

using namespace std;

class feline
{
public:
  virtual void sound(){
    cout<<"hello"<<endl;
  }
  void purr(){
    cout<<"purrpurr"<<endl;
  }
};

class cat:public feline
{
public:
  void sound(){
    cout<<"meow"<<endl;
  }
  void purr(){
    cout<<"purrpurrpurr"<<endl;
  }
};

int main()
{
  feline *kitty;
  cat steve;
  kitty = &steve;
  kitty->sound();
  kitty->purr();
  return 1;
}
