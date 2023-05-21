#ifndef MFG_H
#define MFG_H

#include "flow_network_generator.h"

class Path{
    public:
        vector<Vertex> vertices;
        vector<Edge> edges;
        int maxCapacity;

        Path();

        void addVertex(Vertex v);
        void addEdge(Edge e);
        Graph max_flow(Graph a);
};

#endif