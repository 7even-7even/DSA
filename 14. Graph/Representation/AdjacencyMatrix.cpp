#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<vector<int>> adj;
    int nodes;
    bool directed;

public:
    Graph(int n, bool isDirected = false)
    {
        nodes = n;
        directed = isDirected;
        adj.resize(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
        if (!directed)
        {
            adj[v][u] = 1;
        }
    }

    void display()
    {
        cout << "   ";
        for (int i = 0; i < nodes; i++)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < nodes; i++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int nodes, edges, u, v, dir;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    cout << "Is the graph directed? (1 = Yes, 0 = No): ";
    cin >> dir;

    Graph g(nodes, dir);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nGraph Adjacency Matrix:\n";
    g.display();

    return 0;
}