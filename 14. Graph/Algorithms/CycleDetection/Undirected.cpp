#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph {
    int V;
    vector<vector<int>> adj;

public:
    UndirectedGraph(int v) : V(v) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfsUtil(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                if (dfsUtil(nbr, node, visited)) return true;
            } else if (nbr != parent) {
                return true;
            }
        }

        return false;
    }

    bool detectCycleDFS() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i)
            if (!visited[i])
                if (dfsUtil(i, -1, visited))
                    return true;
        return false;
    }

    bool detectCycleBFS() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                queue<pair<int, int>> q;
                q.push({i, -1});
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for (int nbr : adj[node]) {
                        if (!visited[nbr]) {
                            visited[nbr] = true;
                            q.push({nbr, node});
                        } else if (nbr != parent) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    UndirectedGraph g(V);
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v; cin >> u >> v;
        g.addEdge(u, v);
    }

    int choice;
    cout << "\n1. Detect cycle using DFS\n2. Detect cycle using BFS\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << (g.detectCycleDFS() ? "Cycle Detected (DFS)" : "No Cycle (DFS)") << endl;
            break;
        case 2:
            cout << (g.detectCycleBFS() ? "Cycle Detected (BFS)" : "No Cycle (BFS)") << endl;
            break;
        default:
            cout << "Invalid Choice\n";
    }

    return 0;
}
