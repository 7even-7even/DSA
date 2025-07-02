#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});  // remove this if graph is directed
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto nbr : adj[node]) {
                int nextNode = nbr.first;
                int weight = nbr.second;

                if (dist[nextNode] > d + weight) {
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        cout << "\nShortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                cout << "Node " << i << " is unreachable\n";
            else
                cout << "Node " << i << " -> " << dist[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter " << E << " edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt);
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}
