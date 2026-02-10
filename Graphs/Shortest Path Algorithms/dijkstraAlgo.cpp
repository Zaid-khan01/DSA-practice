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

void dijkstra(int src, vector<vector<Edge>> g, int V)
{
    vector<int> dist(V, INT32_MAX); // distance vector that stores distance from source to each vertex
    dist[src] = 0;

    // priority queue for min heap, that stores vertex with their corresponding weight in min heap form
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (pq.size() > 0)
    {
        int u = pq.top().second;
        pq.pop();

        for(Edge e: g[u]){
            // Edge relaxation - directed or indirected
            if(dist[e.v]>dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    // print the path from source to all of the vertex
    cout<<"Shortest path is : ";
    for(int i=0; i<V; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    int V=6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(7, 3));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    // finding shortest path
    dijkstra(0, g, V);
    return 0;
}
