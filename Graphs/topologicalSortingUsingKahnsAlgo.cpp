#include <iostream>
#include <list>
#include <vector>
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
        // only for directed graph
        l[u].push_back(v);
    }

    void topoSorting(){
        vector<int> indegree(V, 0);
        queue<int> q;
        // calculate indegree (incoming edges to node) for each of the node
        for(int u=0; u<V; u++){
            for(int v: l[u]){
                indegree[v]++;
            }
        }

        // if indegree = 0, push in queue
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // perform BFS (Kahn's algo) logic to all neighbors node
        vector<int> res;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            // if neighbor exist, then decrease their indegree by 1, and if indegree == 0, then push them in queue
            for(int v: l[curr]){
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // print the topological order
        for(int i: res){
            cout<<i<<" ";
        }
        cout<<endl;
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

    g.topoSorting();
    return 0;
}
