// basic file operations
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
#include "flow_network_generator.h"
#include "max_flow_generator.h"
using namespace std;


int main () {
  Graph a1 = GenerateNetwork("Graph 01");
  Graph a2 = GenerateNetwork("Graph 01");
  Graph a3 = GenerateNetwork("Graph 01");
  Graph a4 = GenerateNetwork("Graph 01");
  Graph a5 = GenerateNetwork("Graph 01");

  Graph a6 = GenerateNetwork("Graph 01");
  Graph a7 = GenerateNetwork("Graph 01");
  Graph a8 = GenerateNetwork("Graph 01");
  Graph a9 = GenerateNetwork("Graph 01");
  Graph a10 = GenerateNetwork("Graph 01");

  MFG max_flow_grenerator();

  Graph totals[10] ={a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};

  for(int i = 0; i < 10; i++)
  {
    Graph b = totals[i];
    //cout << "-------------------------------------------------"<< endl;
    //cout<< "Starting print to file"<< endl;
    //cout << "-------------------------------------------------"<< endl;

    int vertex = b.V.size();
    int edge = b.E.size();

    string graphFile = "input_graphs/graph";
    graphFile = graphFile+to_string(i+1);
    graphFile = graphFile+".dot";

    //cout<< graphFile<< endl;

    string fileText ="digraph g{\n\nrankdir=LR\n\n";
    string number =to_string(i+1);
    //cout<< fileText;
 
    for (int l = 0; l< edge; l++)
    {
      string begin(1, b.E[l].begin);
      string end(1, b.E[l].end);
      string flow = to_string(b.E[l].flow);

      string addLine = begin+" -> "+end+"[label =  "+ "\" "+flow+" \"];\n";
      //cout<< addLine;
      fileText = fileText+ addLine;
      
      
    }

    string endFile ="\nlabel = \"graph "+number+"\"\n}";
    fileText = fileText+ endFile;
    cout<< fileText<< endl;
    

    ofstream myfile;  
    myfile.open (graphFile);
    myfile << fileText; 
    myfile.close();
    
  
  }

  for(int i=0;i<10;i++){
    
  }



  return 0;
}