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
  
  ofstream myfile;  
  myfile.open ("example.dot");
  myfile << "Writing this to a file.\n"; 
  myfile.close(); 
  return 0;
}