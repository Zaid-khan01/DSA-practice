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

    // function for printing adjacency list of individual vertex
    void printAdjList()
    {
        cout << "Adjacency list of this graph is : " << endl;
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int neigh : l[i])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    // function for dfs traversal helper function
    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;

        for (int v : l[u])
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs()
    {
        int src = 0;
        vector<bool> vis(5, false);

        dfsHelper(src, vis);
    }
};

int main(int argc, char const *argv[])
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout<<"DFS : ";
    g.dfs();
    // g.printAdjList();
    return 0;
}
