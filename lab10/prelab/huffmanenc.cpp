//Matt Calayo mjc5gh 4/16/18 huffmanenc.cpp
//I tried doing this multiple ways but neither worked. For some reason when I inserted into the heap it would not correctly insert. I checked multiple times to make sure my insert and percolate methods were right but nothing worked. I think that if I was able to insert correctly then the rest of the huffman encoding would have worked.
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffmanTree.h"
#include "huffmanNode.h"
#include <string>

using namespace std;

int main(int argc, char **argv){
  if(argc!=2){
    cout <<"I need 1 parameter"<<endl;
    exit(1);
  }

  FILE *f = fopen(argv[1], "r");
  if(f==NULL){
    cout <<"bad file"<<endl;
    exit(2);
  }
  int charCount=0;
  heap* heep = new heap();

  int charFreq[128];
  for(int i=0;i<128;i++){
    charFreq[i]=0;
  }
  char g;
  while((g = fgetc(f))!=EOF){
    int gInt = (int) g;
    if(gInt>=0x20 && gInt<=127){
      charCount++;
      charFreq[gInt]++;
    }
  }
  
  for(int i=1;i<128;i++){
    if(charFreq[i]>0){     
      huffmanNode* n = new huffmanNode((char)i,charFreq[i]);
      heep->insert(n);
    }
  }
   
    

  huffmanTree* treeboy = new huffmanTree();
  heap heep2 = treeboy->createHeap(*heep);
  treeboy->printPrefix(heep2.findMin(),"");

  cout << "----------------------------------------" << endl;

  treeboy->preset(heep2.findMin(),"");
  rewind(f);
  int finalSize = 0;
  int initialSize = charCount * 8;
  vector<huffmanNode*> veccyboi = heep->getVec();
  
  while((g=fgetc(f))!=EOF){
    for(int i =1; i<heep->size()+1;i++){
      if(veccyboi[i]->val==g){
	finalSize += (veccyboi[i]->bit).size();
	cout <<veccyboi[i]->bit << " ";
      }
    }
  }
  cout <<endl<<finalSize<<endl;
  fclose(f);
  cout << "----------------------------------------" << endl;
  double ratio = (double)initialSize/finalSize;
  cout<<"Compression ratio: "<<ratio<<endl;
  double cost = (double)finalSize/charCount;
  cout<<"The Huffman Tree cost: "<<cost<<" bits per character"<<endl;
}
