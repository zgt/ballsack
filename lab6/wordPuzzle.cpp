//Matt Calayo mjc5gh 3/3/18 wordPuzzle.cpp
//The big theta runtime of wordPuzzle is 160 * the number of rows * the number of columns
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "hashTable.h"
#include <sstream>
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

int main(int argc, char** argv){
  int row, col;
  int numWords=0;
  if(argc<3){
    cout<<"gimme another argument"<<endl;
  }
  else{
    string wordList = argv[1];
    fstream fileRead(wordList.c_str());
    int lines = 0;
    string piko;
    while(getline(fileRead,piko)){
      lines++;
    }
    fileRead.close();

    hashTable *hash = new hashTable(lines);

    fileRead.open(wordList.c_str());
    string line;

    while(fileRead.good()){
      getline(fileRead,line);
      if(line.length()>2){
	hash->insert(line);
      }
    }
    fileRead.close();

    string grid = argv[2];
    fileRead.open(grid.c_str());
    if(readInGrid(grid.c_str(),row,col)){
      // cout<<"i read your grid!!!!!"<<endl;
    }
    else{
      cout<<"couldn't read your grid :("<<endl;
    }
    string rString;
    string d;
    timer time;
    time.start();

    for(int cRow = 0; cRow<row; cRow++){
      for(int cCol = 0; cCol<col; cCol++){
	for(int direc = 0; direc<8; direc++){
	  for(int wLength=3; wLength<=22;wLength++){
	    string word = getWordInGrid(cRow,cCol,direc,wLength,row,col);
	    if(word.length()==wLength){
	    if(hash->find(word)){
	      numWords++;
	      switch(direc){
		
	      case 0:
		d = "N";
		break;
	      case 1:
		d = "NE";
		break;
	      case 2:
		d = "E";
		break;
	      case 3:
		d = "SE";
		break;
	      case 4:
		d = "S";
		break;
	      case 5:
		d = "SW";
		break;
	      case 6:
		d = "W";
		break;
	      case 7:
		d = "NW";
		break;
		}
	  
	    

	       stringstream ss;
	      ss << d << " (" << cRow << ", " << cCol <<"): " << word << endl;
	       rString += ss.str();
	    }
	    }
	  }
	}
      }
    }
    time.stop();
     double timeR = time.getTime();
      cout <<rString<<endl;
     cout <<numWords<< " words found"<<endl;
     int timeR2=(timeR*1000);
     cout <<timeR2<<endl;
  }
		
    
    
  
}

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    // cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
	    // cout << grid[r][c];
        }
	//	 cout << endl;
    }
    // return success!
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
