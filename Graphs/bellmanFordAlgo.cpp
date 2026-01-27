#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Edge
{
public:
    int v;
    int wt;

    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(int src, vector<vector<Edge>> g, int V){
    vector<int> dist(V, INT32_MAX);
    dist[src] = 0;

    // performing edge relaxation 'V-1' times
    for(int i=0; i<V-1; i++){
        for(int u=0; u<V; u++){
            for(Edge e: g[u]){
                if(dist[e.v] > dist[u] + e.wt){ // edge relaxation
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    // printing the path from src to all the vertices of graph
    cout<<"Shortest path is : ";
    for(int i=0; i<V; i++){
        cout<<dist[i]<< " ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int V=5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, -4));
    g[1].push_back(Edge(4, -1));

    g[2].push_back(Edge(3, 2));

    g[3].push_back(Edge(4, 4));

    // finding shortest path using bellman ford algorithm
    bellmanFord(0, g, V);
    return 0;
}
