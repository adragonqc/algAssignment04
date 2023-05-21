#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include "max_flow_generator.h"
#include "flow_network_generator.h"

using namespace std;

void MFG::MFG(){
    

}


// Returns the maximum flow from s to t in the given graph, V is size of graph
int MFG::edmonds_karp(int rGraph[][V], int s, int t, int V)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    // int rGraph[V][V];
    // for (u = 0; u < V; u++) {
    //     for (v = 0; v < V; v++) {
    //         rGraph[u][v] = graph[u][v];
    //     }
    // }

    int parent[V];
    int max_flow = 0; // Initialize max flow

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent, V)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow; // Subtract path flow from the forward edge
            rGraph[v][u] += path_flow; // Add path flow to the backward edge
        
        }

        max_flow += path_flow;
    }

    // Return the maximum flow
    return max_flow;
}


//returns true if there is a path from source "s" to desitnation "t"
bool MFG::bfs(int rGraph[][V], int s, int t, int parent[], int V)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}