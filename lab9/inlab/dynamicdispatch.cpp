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
  virtual void eat(){
    cout<<"nomnom"<<endl;
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
  void eat(){
    cout<<"nibble"<<endl;
  }
};

class lion:public feline
{
public:
  void sound(){
    cout<<"roar"<<endl;
  }
  void purr(){
    cout<<"scary purr"<<endl;
  }
  void eat(){
    cout<<"chomp"<<endl;
  }
};

int main()
{
  feline *kitty;
  feline *kitty2;
  cat steve;
  lion piko;
  kitty = &steve;
  kitty2 = &piko;
  kitty->sound();
  kitty->purr();
  kitty->eat();
  kitty2->sound();
  kitty2->purr();
  kitty2->eat();
  return 1;
}
