#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int find(vector<int>& parent, int i){
    if(parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(vector<int>& parent, int x, int y){
    parent[x] = y;
}

int kruskal(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(V, -1);
    int mstWeight = 0;
    int edgeCount = 0;
    
    for(auto& edge : edges) {
        int u = find(parent, edge.u);
        int v = find(parent, edge.v);
        if(u != v) {
            Union(parent, u, v);
            mstWeight += edge.w;
            edgeCount++;
            if(edgeCount == V-1) break;
        }
    }
    return mstWeight;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 8},
        {1, 3, 18},
        {2, 3, 4}
    };
    
    int mstWeight = kruskal(edges, V);
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
    return 0;
}
