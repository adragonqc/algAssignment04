#ifndef MFG_H
#define MFG_H

class MFG {
public:
    void MFG();
    int edmonds_karp(int graph[][V], int s, int t, int V);
    bool bfs(int rGraph[][V], int s, int t, int parent[], int V));

private:
};

#endif