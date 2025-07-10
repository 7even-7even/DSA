// Including necessary header file
#include <bits/stdc++.h>
using namespace std;

// We mainly take input graph as a set of edges. This function is
// mainly a utility function to convert the edges to an adjacency
// list
vector<vector<int>> constructadj(int V,vector<vector<int>> &edges){
    
    // Graph represented as an adjacency list
    vector<vector<int> > adj(V);

    // Constructing adjacency list
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }
    
    return adj;
}

// Function to return list containing vertices in
// Topological order.
vector<int> topologicalSort(int V, vector<vector<int> >& edges)
{
    vector<vector<int>> adj = constructadj(V,edges);
    
    // Vector to store indegree of each vertex
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    // Queue to store vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (auto it : adj[node]) {
            indegree[it]--;

            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // Check for cycle
    if (result.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }

    return result;
}

int main()
{

    // Number of nodes
    int V = 6;

    // Edges
    vector<vector<int> > edges
        = {{0, 1}, {1, 2}, {2, 3},
           {4, 5}, {5, 1}, {5, 2}};

    vector<int> result = topologicalSort(V, edges);

    // Displaying result
    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}