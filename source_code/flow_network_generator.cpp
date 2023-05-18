#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
using namespace std;


//EDGE CLAS
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
    
    void changeBegin(char b2){
        begin = b2;
    };
    void changeEnd(char e2){
        end = e2;
    };
    void changeFlow(int f2){
        flow = f2;
    };
};

//VERTEX CLASS
class Vertex{
  public:
    char name;
    bool source;
    bool sink;

    int edgesFrom = 0;
    int edgesTo = 0;

    Vertex(){
    };
    Vertex( char id, bool start, bool end)
    {
      name = id;
      source = start;
      sink = end;
    };
};

//GRAPH CLASS
class Graph{
  public:
    vector<Vertex> V;
    vector<Edge> E;
    Vertex source;
    Vertex sink;

    string label;
    bool connectedEnd;
    
    Graph(string called)
    {
        label = called;
    };

    void setSource(Vertex addSource){
      source = addSource;
    };
    void setSink(Vertex addSink){
      sink = addSink;
    };
    void addEdge(Edge addE){
        E.push_back (addE);
    };
    void addVertex(Vertex addV){
        V.push_back (addV);
    };
};



Graph GenerateNetwork(string label){
    //Set up random amount of edges
    srand(time(0));
    int vertexNumber = rand() % 10 + 5;

    //Create Graph with name
    Graph g(label);

    //Set source node
    cout<< "-------------------------------------------------"<< endl;
    cout<< "Create "<<vertexNumber << " verticies" << endl;
    Vertex start('A', true, false);
    //cout<< "Start Vertex "<< start.name << endl;
    g.setSink(start);
    g.addVertex(start);

    //Set other nodes
    for (int i = 3; i < vertexNumber+1; i++) 
    {
        //cout<< i << endl;
        char placeName = (char)(i+63);
        //cout<< placeName << endl;
        Vertex v( placeName , false, false );
        //cout<< "Vertex "<< v.name << endl;
        g.addVertex(v);
    }

    //Set sink node 
    Vertex end ('Z', false, true);
    //cout<< "End Vertex "<< end.name << endl;
    g.setSink(end);
    g.addVertex(end);

    for (int j = 0; j< vertexNumber; j++)
    {
        cout << "Graph vertex: " << g.V[j].name << endl;
    }

    

    //Set edges
    cout<< "-------------------------------------------------"<< endl;
    
    int sourceEdges = 0;
    char alreadyBeen = ' ';
    
    //Set 2 edges from source
    while (sourceEdges < 2 )
    {
        int edgeNumber = rand() % (vertexNumber-1) +1;
        int flowValue = rand() % 11;

        //If it's the point is the sink, try again
        if( g.V[edgeNumber].name == end.name)
        {
            cout<< g.V[edgeNumber].name << " is the Sink! Trying again!" << endl;
        }
        //If you've already made a connection to this one, try again
        else if(g.V[edgeNumber].name == alreadyBeen)
        {
            cout<< g.V[edgeNumber].name << " is a repeat! Try again!" << endl;
        }
        //If none of the above is correct, make an edge
        else
        {
            cout<< "Connect start to: " << g.V[edgeNumber].name << endl;
            Edge startE(start.name, g.V[edgeNumber].name,flowValue, flowValue);
            cout<< "Edge " << startE.begin << " to " << startE.end <<  " has flow of " << startE.flow << endl;
            alreadyBeen = g.V[edgeNumber].name;
            g.addEdge(startE);
            sourceEdges++;
        }
    }

    cout<< "-------------------------------------------------"<< endl;
    //Set edges from end to middle
    int endEdges = 0;
    char alreadyBeen2[2] = {' ', ' '};
    int visitedCounter = 0;
    while (endEdges < 3 )
    {
        int edgeNumber = rand() % (vertexNumber-1) +1;
        int flowValue = rand() % 11;

        //If it's the point is the sink, try again
        if( g.V[edgeNumber].name == end.name)
        {
            cout<< g.V[edgeNumber].name << " is the Sink! Trying again!" << endl;
        }
        //If you've already made a connection to this one, try again
        else if((g.V[edgeNumber].name == alreadyBeen2[0])||(g.V[edgeNumber].name == alreadyBeen2[1]))
        {
            cout<< g.V[edgeNumber].name << " is a repeat! Try again!" << endl;
        }
        //If none of the above is correct, make an edge
        else
        {
            cout<< "Connect start to: " << g.V[edgeNumber].name << endl;
            Edge endE( g.V[edgeNumber].name, end.name ,flowValue, flowValue);
            cout<< "Edge " << endE.begin << " to " << endE.end <<  " has flow of " << endE.flow << endl;
            alreadyBeen2[visitedCounter] = g.V[edgeNumber].name;
            visitedCounter++;
            g.addEdge(endE);
            endEdges++;
        }
    }


    return g;
    
}