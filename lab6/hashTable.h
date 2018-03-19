//Matt Calayo mjc5gh 3/3/18 hashTable.h
#ifndef HASH_T_H
#define HASH_T_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>


using namespace std;

class hashTable{
 public:
  hashTable(int size);
  ~hashTable();
  bool find(const string& s);
  bool insert(const string& s);
  int maxSize;

 private:
  vector<list<string> > *buckets;
   unsigned int hash(const string& s) const;
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);

};

#endif
