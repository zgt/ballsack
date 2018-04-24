

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    string start = dests[0];
    vector<string> dests2= dests;
    float mindist = computeDistance(me,start,dests);
    float cmpdist = 0.0;
    while(next_permutation(dests.begin()+1,dests.end())){
      cmpdist = computeDistance(me,start,dests);
      if(cmpdist<mindist){
	mindist=cmpdist;
	dests2=dests;
      }
    }
    printRoute(dests2[0],dests2);
    cout<<"and will have length " <<mindist<<endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float dist = 0.0;
  string c1= start;
  string c2= dests[dests.size()-1];
  for(int i=1;i<dests.size();i++){
    dist+=me.getDistance(c1,dests[i]);
    c1=dests[i];
  }
  dist+=me.getDistance(dests[0],c2);
  return dist;



}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
  cout<<"Your journey will take you along the path ";
  for(int i=0;i<dests.size();i++){
    cout<<dests[i]<< " -> ";
  }
  cout<<start<<endl;
}

