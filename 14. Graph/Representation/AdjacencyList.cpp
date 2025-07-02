#include<bits/stdc++.h>
using namespace std;
class Graph{
    unordered_map<int, list<int>> adj;
    bool directed;

    public:
    Graph(bool isDirected = false){
        directed = isDirected;
    }

    void addEdge(int u , int v){
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }
    }

    void display(){
        for(auto &pair : adj){
            cout << pair.first << " ";
            for(int edge : pair.second){
                cout << edge << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int nodes, edges, u, v, dir;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Is the graph directed? (1 = Yes, 0 = No): ";
    cin >> dir;

    Graph g(dir);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nGraph Adjacency List:\n";
    g.display();

    return 0;
}