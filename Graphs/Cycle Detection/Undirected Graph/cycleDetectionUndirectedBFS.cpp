#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l; // dynamic array for storing neighbors of particular vertex

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    // add edge between vertex = storing in adjacency list
    void addEdge(int u, int v)
    {
        /*
        for undirected graph, we know that both vertex that are connected through an edge stores each other
        in their own adjacency list
        */
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // helper function for cycle detection using BFS
    bool isCycleUndirBFS(int src, vector<bool> &vis){
        queue<pair<int, int>>q;

        q.push({src, -1});
        vis[src] = true;

        while(q.size()>0){
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            list<int> neighbors = l[u];
            for(int v: neighbors){
                if(!vis[v]){
                    q.push({v, u});
                    vis[v] = true;
                }
                else if(v!=parU){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);

        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(isCycleUndirBFS(i, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    if(g.isCycle()){
        cout<<"Graph contains cycle"<<endl;
    }
    else{
        cout<<"Graph doesn't contains cycle"<<endl;
    }
    // g.printAdjList();
    return 0;
}
