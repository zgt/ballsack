//Matt Calayo mcj5gh 4/16/18 huffmanNode.cpp
#include "huffmanNode.h"

using namespace std;

huffmanNode::huffmanNode(){
  val=5;
  freq=0;
  bit="";
  left=NULL;
  right=NULL;
}

huffmanNode::huffmanNode(char c, int fre){
  val = c;
  freq = fre;
  bit="";
  left = NULL;
  right = NULL;
}

huffmanNode::~huffmanNode(){
}

bool operator<(const huffmanNode &l, const huffmanNode &r){
  return (l.freq < r.freq);
}

bool operator>(const huffmanNode &l, const huffmanNode &r){
  return (l.freq > r.freq);
}
