//Matt Calayo mjc5gh 3/3/18 hashTable.cpp
#include "hashTable.h"

hashTable::hashTable(int size){
  buckets = new vector<list<string> >;
  if(!checkprime(size)){
    size = getNextPrime(size);
  }
  size *= 1.25;
  buckets->resize(size);

  for(int i = 0;i<size;i++){
    list<string> bucketList;
    buckets->push_back(bucketList);
  }
  maxSize=size;
}

bool hashTable::find(const string& s){
  list<string> &hashList = buckets->at(hash(s));
  bool result = (::find(hashList.begin(), hashList.end(), s) != hashList.end());
  return result;
}

bool hashTable::insert(const string& s){
    if(!this->find(s)){
      list<string> &hashList = buckets->at(hash(s));
      hashList.push_back(s);
      return true;
    }
    else
      return false;
  }

unsigned int hashTable::hash(const string& s) const{
  unsigned int val=1;
  int wordLength = s.length();
  for(int i = 0;i<wordLength;i++){
    val *= (s[i]*37);
  }
  val %= maxSize;
  return val;
}


bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

