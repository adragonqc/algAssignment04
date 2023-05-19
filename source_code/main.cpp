// basic file operations
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <vector>
#include "flow_network_generator.h"
using namespace std;


int main () {

  Graph a = GenerateNetwork("Test Graph");

  int vertex = a.V.size();
  int edge = a.E.size();
  cout<< "-------------------------------------------------"<< endl;
  // run for loop from 0 to vecSize
  for(int i = 0; i < vertex; i++)
  {
    cout << "Graph vertex: " << a.V[i].name << endl;
  }
  for (int l = 0; l< edge; l++)
  {
    cout<< "Edge from " << a.E[l].begin << " to " << a.E[l].end<< " and has a flow of " << a.E[l].flow << endl;
  }
  
  
  ofstream myfile;  
  myfile.open ("example.dot");
  myfile << "Writing this to a file.\n"; 
  myfile.close(); 
  return 0;
}