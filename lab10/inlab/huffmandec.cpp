// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.
//Matt Calayo mcj5gh 4/17/18 huffmandec.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffmanNode.h"
using namespace std;

void buildTree(huffmanNode* n, string prefix, char c, int count){
  if(prefix.length()==count){
    n->val=c;
  }
  if(prefix[count]=='0'){
    if(n->left==NULL){
      huffmanNode* temp = new huffmanNode(5,0);
      n->left=temp;
    }
    buildTree(n->left,prefix,c,count+1);
  }
  if(prefix[count]=='1'){
    if(n->right==NULL){
      huffmanNode* temp = new huffmanNode(5,0);
      n->right=temp;
    }
    buildTree(n->right,prefix,c,count+1);
  }
}

void decode(huffmanNode* n, string bits, int count, string s2){
  cout<<bits.substr(count,bits.length())<<" "<<s2<<endl;
  if(count<bits.length()){
      if(n->left==NULL&&n->right==NULL){
	s2+=n->val;
	return;
      }
      if(bits[count]=='0'){
	decode(n->left,bits, count+1,s2);
      }
      if(bits[count]=='1'){
	decode(n->right,bits,count+1,s2);
	  }
  }
}

void destructionAnnihilation(huffmanNode* n){
  if(n!=NULL){
    destructionAnnihilation(n->right);
    destructionAnnihilation(n->left);
    delete n;
  }
  n=NULL;
}

  

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
	huffmanNode* nodey = new huffmanNode(5,0);
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
	// cout << "character '" << character << "' has prefix code '"
	//    << prefix << "'" << endl;
	buildTree(nodey,prefix,character[0],0);
	
	//	cout <<nodey->left->val<<endl;
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    huffmanNode* root = nodey;
    string sg="";
    for(int i = 0;i<allbits.length()+1;i++){
      if(root->left==NULL&&root->right==NULL){
	sg+=root->val;
	root=nodey;
      }
      if(allbits[i]=='0'){
	root = root->left;
      }
      if(allbits[i]=='1'){
	root = root->right;
	  }
    }
      cout<<sg<<endl;
      delete root;
      
    file.close();
}
