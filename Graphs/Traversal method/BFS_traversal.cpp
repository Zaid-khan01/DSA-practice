#include <iostream>
#include <list>
#include<queue>
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
    // function for BFS traversal
    void bfs(){
        queue<int> q;
        vector<bool> vis(5, false);
    
        q.push(0);
        vis[0] = true;
    
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
    
            for(int v : l[u]){ // v -> immediate neighbor
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.bfs();
    // g.printAdjList();
    return 0;
}
