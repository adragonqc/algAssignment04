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
    void changeCapacity(int c2){
        capacity = c2;
    };
    void switchEnd(){
        char temp = begin;
        begin = end;
        end = temp;
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
    int maxFlow;

    Graph()
    {
    };
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
    //srand(time(rando));
    int vertexNumber = rand() % 5 + 5;

    //Create Graph with name
    Graph g(label);

    //Set source node
    Vertex start('A', true, false);
    g.setSink(start);
    g.addVertex(start);

    //Set other nodes
    for (int i = 3; i < vertexNumber+1; i++) 
    {
        char placeName = (char)(i+63);
        Vertex v( placeName , false, false );
        g.addVertex(v);
    }

    //Set sink node 
    Vertex end ('Z', false, true);
    g.setSink(end);
    g.addVertex(end);


    //Set edges
    int sourceEdges = 0;
    char alreadyBeenS[2] = {' ', ' '};
    int visitedCounter= 0;
    
    //Set 2 edges from source
    while (sourceEdges < 2 )
    {
        int edgeNumber = rand() % (vertexNumber-1) +1;
        int flowValue = rand() % 10 +1;

        //If it's the point is the sink, try again
        if( g.V[edgeNumber].name == end.name)
        {
            //cout<< g.V[edgeNumber].name << " is the Sink! Trying again!" << endl;
        }
        //If you've already made a connection to this one, try again
        else if(g.V[edgeNumber].name == alreadyBeenS[0])
        {
            //cout<< g.V[edgeNumber].name << " is a repeat! Try again!" << endl;
        }
        //If none of the above is correct, make an edge
        else
        {
            //cout<< "Connect start to: " << g.V[edgeNumber].name << endl;
            Edge startE(start.name, g.V[edgeNumber].name,flowValue, flowValue);

            //update edge values for vertex
            start.edgesFrom++;
            g.V[edgeNumber].edgesTo++;

            //Update values so no repeats and add to edge list
            //cout<< "Edge " << startE.begin << " to " << startE.end <<  " has flow of " << startE.flow << endl;
            alreadyBeenS[visitedCounter] = g.V[edgeNumber].name;
            visitedCounter++;
            g.addEdge(startE);
            sourceEdges++;
        }
    }

    //cout<< "-------------------------------------------------"<< endl;
    //Set edges from middle to end
    int endEdges = 0;
    char alreadyBeenE[3] = {' ', ' ', ' '};
    int visitedCounter2 = 0;
    while (endEdges < 3 )
    {
        int edgeNumber = rand() % (vertexNumber-1) +1;
        int flowValue = rand() % 10 +1;

        //If it's the point is the sink, try again
        if( g.V[edgeNumber].name == end.name)
        {
            //cout<< g.V[edgeNumber].name << " is the Sink! Trying again!" << endl;
        }
        //If you've already made a connection to this one, try again
        else if((g.V[edgeNumber].name == alreadyBeenE[0])||(g.V[edgeNumber].name == alreadyBeenE[1]))
        {
            //cout<< g.V[edgeNumber].name << " is a repeat! Try again!" << endl;
        }
        //If none of the above is correct, make an edge
        else
        {
            //cout<< "Connect end to: " << g.V[edgeNumber].name << endl;
            Edge endE( g.V[edgeNumber].name, end.name ,flowValue, flowValue);

            //update edge values for vertex
            end.edgesTo++;
            g.V[edgeNumber].edgesFrom++;

            //Update values so no repeats and add to edge list
            //cout<< "Edge " << endE.begin << " to " << endE.end <<  " has flow of " << endE.flow << endl;
            alreadyBeenE[visitedCounter2] = g.V[edgeNumber].name;
            visitedCounter2++;
            g.addEdge(endE);
            endEdges++;
        }
    }

    //Set middle edges
    //cout<< "-------------------------------------------------"<< endl;
    int midEdges = 0;
    for (int k = 1; k< vertexNumber-1; k++)
    {
        char beenFromMid[3] = {' ', ' ', ' '};
        char beenToMid[3] = {' ', ' ', ' '};
        int visitedCounter = 0;

        //Create edges to the middles ones if they don't exist
        //cout<< "-----------------------"<< endl;
        //cout << "Add Edges to Vertex: " << g.V[k].name << endl;
        while (g.V[k].edgesTo<1)
        {
            int edgeNumber = rand() % (vertexNumber-2) +1;
            int flowValue = rand() % 10 + 1;
            
            //If it's the point is the same vertex, try again
            if( g.V[edgeNumber].name == g.V[k].name)
            {
                //cout<< g.V[edgeNumber].name << " is the same vertex! Trying again!" << endl;
            }
            else
            {
                //cout<< "Connect " << g.V[edgeNumber].name <<" to: " << g.V[k].name << endl;
                Edge midE(g.V[edgeNumber].name, g.V[k].name, flowValue, flowValue);

                //Update values so no repeats and add to edge list
                //cout<< "Edge " << midE.begin << " to " << midE.end <<  " has flow of " << midE.flow << endl;
                g.addEdge(midE);

                //update edge values for vertex
                midEdges++;
                g.V[edgeNumber].edgesFrom++;
                g.V[k].edgesTo++;
            }
        }

        //Create edges from the middles ones if they have less than 2
        while (g.V[k].edgesFrom<2)
        {
            int edgeNumber = rand() % (vertexNumber-2) +1;
            int flowValue = rand() % 10 + 1;

            //If it's the point is the same vertex, try again
            if( g.V[edgeNumber].name == g.V[k].name)
            {
                //cout<< g.V[edgeNumber].name << " is the same vertex! Trying again!" << endl;
            }
            else if((g.V[edgeNumber].name == beenToMid[0])||(g.V[edgeNumber].name == alreadyBeenE[1]))
            {
                //cout<< g.V[edgeNumber].name << " is a repeat! Try again!" << endl;
            }
            else
            {
                //cout<< "Connect " << g.V[k].name <<" to: " << g.V[edgeNumber].name << endl;
                Edge midE(g.V[k].name, g.V[edgeNumber].name, flowValue, flowValue);

                //Update values so no repeats and add to edge list
                //cout<< "Edge " << midE.begin << " to " << midE.end <<  " has flow of " << midE.flow << endl;
                g.addEdge(midE);

                //update edge values for vertex
                midEdges++;
                g.V[edgeNumber].edgesTo++;
                g.V[k].edgesFrom++;
            }
        }
    }
    int allEdge = sourceEdges +endEdges +midEdges;

    
    /*cout<< "-------------------------------------------------"<< endl;
    for (int j = 0; j< vertexNumber; j++)
    {
        cout << "Graph vertex: " << g.V[j].name << endl;
    }
    for (int l = 0; l< allEdge; l++)
    {
        cout<< "Edge from " << g.E[l].begin << " to " << g.E[l].end<< " and has  a flow of " << g.E[l].flow << endl;
    }*/
    

    return g;
    
}