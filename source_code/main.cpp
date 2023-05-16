// basic file operations
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

class Edge{
  public:
    char begin;
    char end;
    int flow;
    int capacity;

    Edge( char b, char e, int currentFlow, int flowCap )
    {
      begin = b;
      end =e;
      flow =currentFlow;
      capacity = flowCap;
    };
};

class Vertex{
  public:
    char name;
    bool source;
    bool sink;
    
    Vertex( char id, bool start, bool end)
    {
      name = id;
      source = start;
      sink = end;
    };
};

class Graph {
  public:
    vector<Vertex> V;
    vector<Edge> E;
    Vertex source;
    Vertex sink;

    void setSource(){
      
    };
    void setSink(){

    };
    void addEdge(){

    };
    void addVertex(){

    };
    void removeEdge(){

    };
    void removeVertex(){

    };
};

int main () {
  ofstream myfile;
  myfile.open ("example.dot");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}