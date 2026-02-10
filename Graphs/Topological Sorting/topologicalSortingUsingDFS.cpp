#include <iostream>
#include <list>
#include <vector>
#include <stack>
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
        // only for directed graph
        l[u].push_back(v);
    }

    // simple logic for topological sorting using dfs
    void dfs(int curr, vector<bool> &vis, stack<int> &s)
    {
        vis[curr] = true;

        for (int v : l[curr])
        {
            if (!vis[v])
            {
                dfs(v, vis, s);
            }
        }
        // we push the neighbors first, then at the end we push parent, so that parent will printed first
        s.push(curr);
    }

    void topologicalSort()
    {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, s);
            }
        }

        // now print all the elements of stack, so parent printed first
        while (s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(6);

    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);

    g.topologicalSort();
    return 0;
}
