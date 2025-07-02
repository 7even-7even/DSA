#include <bits/stdc++.h>
using namespace std;
class Graph
{
    unordered_map<int, list<int>> adj;
    bool directed;

public:
    Graph(bool isDirected = false)
    {
        directed = isDirected;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        if (!directed)
        {
            adj[v].push_back(u);
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(src);
        visited[src] = true;

        cout << "\nBFS Traversal: ";
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int adjacent : adj[node])
            {
                if (!visited[adjacent])
                {
                    q.push(adjacent);
                    visited[adjacent] = true;
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int node, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int start)
    {
        unordered_map<int, bool> visited;
        cout << "DFS Traversal: ";
        dfsHelper(start, visited);
        cout << endl;
    }

    void display()
    {
        cout << "\nAdjacency List:\n";
        for (auto &pair : adj)
        {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int nodes, edges, u, v, dir;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Is the graph directed? (1 = Yes, 0 = No): ";
    cin >> dir;

    Graph g(dir);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int src;
    cout << "\nEnter the source vertex: ";
    cin >> src;
    g.bfs(src);

    g.dfs(src);

    g.display();

    return 0;
}