// basic file operations
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <vector>
#include <sstream>
#include "flow_network_generator.h"
using namespace std;


int main () {

  for(int i = 0; i < 10; i++)
  {
    cout << "-------------------------------------------------"<< endl;
    Graph a = GenerateNetwork("Graph " + to_string(i+1));
    cout << "-------------------------------------------------"<< endl;
    cout<< "Starting print to file"<< endl;
    int vertex = a.V.size();
    int edge = a.E.size();
    cout<< "-------------------------------------------------"<< endl;

    
    /*for(int i = 0; i < vertex; i++)
    {
      cout << "Graph vertex: " << a.V[i].name << endl;
    }
    for (int l = 0; l< edge; l++)
    {
      cout<< "Edge from " << a.E[l].begin << " to " << a.E[l].end<< " and has a flow of " << a.E[l].flow << endl;
    }*/

    string graphFile = "input_graphs/graph";
    graphFile = graphFile+to_string(i+1);
    graphFile = graphFile+".dot";

    cout<< graphFile<< endl;

    string fileText ="diagraph g{\n\nrankdir=LR\n\n";
    string number =to_string(i+1);
    cout<< fileText<< endl;
 
    for (int l = 0; l< edge; l++)
    {
      cout << a.E[l].begin<< endl;
      string begin(1, a.E[l].begin);
      string end(1, a.E[l].end);
      string flow = to_string(a.E[l].flow);

      //string begin = a.E[l].begin;
      //string end = a.E[l].end;
      //string addLine = a.E[l].begin+" -> "+a.E[l].end+' [label = " '+a.E[l].flow+' "];\n';
      //cout<< addLine<< endl;
      //fileText =fileText.append(addLine);
    }

    string endFile ="\nlabel = \"graph\""+number+"\"];\n}";
    cout<< endFile<< endl;

    //fileText=fileText.append(endFile);
    //cout<< fileText<< endl;
    


    ofstream myfile;  
    myfile.open (graphFile);
    myfile << "Test message"; 
    myfile.close();
    
  
  }
  return 0;
}