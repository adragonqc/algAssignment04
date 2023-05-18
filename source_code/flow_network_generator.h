#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
#include "flow_network_generator.h"
using namespace std;

class Edge{
  public:
    char begin;
    char end;
    int flow;
    int capacity;

    Edge( char b, char e, int currentFlow, int flowCap );
    void changeBegin(char b2);
    void changeEnd(char e2);
    void changeFlow(int f2);
};

class Vertex{
  public:
    char name;
    bool source;
    bool sink;

    int edgesFrom = 0;
    int edgesTo = 0;

    Vertex();
    Vertex( char id, bool start, bool end);
};

class Graph {
  public:
    vector<Vertex> V;
    vector<Edge> E;
    Vertex source;
    Vertex sink;

    string label;
    bool connectedEnd;

    Graph(string called);
    void setSource(Vertex addSource);
    void setSink(Vertex addSink);
    void addEdge(Edge addE);
    void addVertex(Vertex addV);
};

Graph GenerateNetwork(string label);