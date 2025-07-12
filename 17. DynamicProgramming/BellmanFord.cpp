/*
 * Bellman-Ford Algorithm using Dynamic Programming
 * 
 * Problem: Find shortest paths from a source vertex to all other vertices
 * in a weighted graph that may contain negative edges (but no negative cycles).
 * 
 * Dynamic Programming Approach: Bottom-up
 * Time Complexity: O(V * E) where V = vertices, E = edges
 * Space Complexity: O(V)
 * 
 * Expected Output Example:
 * Enter number of vertices: 5
 * Enter number of edges: 8
 * 
 * Enter edges (source destination weight):
 * 0 1 -1
 * 0 2 4
 * 1 2 3
 * 1 3 2
 * 1 4 2
 * 3 2 5
 * 3 1 1
 * 4 3 -3
 * 
 * Enter source vertex: 0
 * 
 * Shortest distances from vertex 0:
 * Vertex 0: 0
 * Vertex 1: -1
 * Vertex 2: 2
 * Vertex 3: -2
 * Vertex 4: 1
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

struct Edge {
    int source, destination, weight;
    
    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

class BellmanFordDP {
private:
    vector<Edge> edges;
    int V, E;
    
public:
    BellmanFordDP(int vertices, int edgeCount) {
        V = vertices;
        E = edgeCount;
    }
    
    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }
    
    // Bellman-Ford algorithm with negative cycle detection
    pair<bool, vector<int>> bellmanFord(int source) {
        // Initialize distances
        vector<int> distances(V, INT_MAX);
        distances[source] = 0;
        
        // Track parent vertices for path reconstruction
        vector<int> parent(V, -1);
        
        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            bool relaxed = false;
            
            for (const Edge& edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int weight = edge.weight;
                
                if (distances[u] != INT_MAX && 
                    distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    parent[v] = u;
                    relaxed = true;
                }
            }
            
            // Early termination if no relaxation occurred
            if (!relaxed) {
                cout << "Early termination at iteration " << (i + 1) << endl;
                break;
            }
        }
        
        // Check for negative cycles
        bool hasNegativeCycle = false;
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            
            if (distances[u] != INT_MAX && 
                distances[u] + weight < distances[v]) {
                hasNegativeCycle = true;
                cout << "Negative cycle detected involving edge " 
                     << u << " -> " << v << endl;
                break;
            }
        }
        
        return {!hasNegativeCycle, distances};
    }
    
    // Print shortest paths
    void printShortestPaths(int source, const vector<int>& distances) {
        cout << "\n--- Shortest Paths from Vertex " << source << " ---" << endl;
        
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            if (distances[i] == INT_MAX) {
                cout << "INFINITY (unreachable)" << endl;
            } else {
                cout << distances[i] << endl;
            }
        }
    }
    
    // Print the graph structure
    void printGraph() {
        cout << "\n--- Graph Structure ---" << endl;
        cout << "Vertices: " << V << endl;
        cout << "Edges: " << E << endl;
        cout << "\nEdge List:" << endl;
        
        for (const Edge& edge : edges) {
            cout << "  " << edge.source << " -> " << edge.destination 
                 << " (weight: " << edge.weight << ")" << endl;
        }
    }
    
    // Print adjacency matrix
    void printAdjacencyMatrix() {
        cout << "\n--- Adjacency Matrix ---" << endl;
        
        // Initialize matrix with INF
        vector<vector<int>> matrix(V, vector<int>(V, INT_MAX));
        
        // Set diagonal to 0
        for (int i = 0; i < V; i++) {
            matrix[i][i] = 0;
        }
        
        // Fill with edge weights
        for (const Edge& edge : edges) {
            matrix[edge.source][edge.destination] = edge.weight;
        }
        
        // Print header
        cout << "    ";
        for (int j = 0; j < V; j++) {
            cout << setw(4) << j;
        }
        cout << endl;
        
        // Print matrix
        for (int i = 0; i < V; i++) {
            cout << setw(3) << i << " ";
            for (int j = 0; j < V; j++) {
                if (matrix[i][j] == INT_MAX) {
                    cout << setw(4) << "INF";
                } else {
                    cout << setw(4) << matrix[i][j];
                }
            }
            cout << endl;
        }
    }
    
    // Find and print negative cycles
    void findNegativeCycles() {
        cout << "\n--- Negative Cycle Detection ---" << endl;
        
        vector<int> distances(V, 0);  // Start with all distances as 0
        
        // Run one more iteration to detect negative cycles
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            
            if (distances[u] + weight < distances[v]) {
                cout << "Negative cycle detected!" << endl;
                cout << "Edge " << u << " -> " << v << " with weight " << weight << endl;
                return;
            }
        }
        
        cout << "No negative cycles detected." << endl;
    }
    
    // Print detailed analysis
    void printAnalysis(int source, const vector<int>& distances) {
        cout << "\n--- Detailed Analysis ---" << endl;
        
        // Count reachable vertices
        int reachable = 0;
        int unreachable = 0;
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        
        for (int i = 0; i < V; i++) {
            if (distances[i] == INT_MAX) {
                unreachable++;
            } else {
                reachable++;
                minDist = min(minDist, distances[i]);
                maxDist = max(maxDist, distances[i]);
            }
        }
        
        cout << "Reachable vertices: " << reachable << "/" << V << endl;
        cout << "Unreachable vertices: " << unreachable << "/" << V << endl;
        
        if (reachable > 0) {
            cout << "Minimum distance: " << minDist << endl;
            cout << "Maximum distance: " << maxDist << endl;
        }
        
        // Check for negative edges
        int negativeEdges = 0;
        for (const Edge& edge : edges) {
            if (edge.weight < 0) negativeEdges++;
        }
        
        cout << "Negative edges: " << negativeEdges << "/" << E << endl;
    }
};

int main() {
    cout << "=== Bellman-Ford Algorithm using Dynamic Programming ===" << endl;
    
    // Get number of vertices
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    if (V <= 0) {
        cout << "Error: Number of vertices must be positive!" << endl;
        return 1;
    }
    
    // Get number of edges
    int E;
    cout << "Enter number of edges: ";
    cin >> E;
    
    if (E < 0) {
        cout << "Error: Number of edges must be non-negative!" << endl;
        return 1;
    }
    
    // Create BellmanFordDP object
    BellmanFordDP bfDP(V, E);
    
    // Get edges
    cout << "\nEnter edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cout << "Edge " << (i + 1) << ": ";
        cin >> src >> dest >> weight;
        
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            cout << "Error: Invalid vertex indices!" << endl;
            return 1;
        }
        
        bfDP.addEdge(src, dest, weight);
    }
    
    // Get source vertex
    int source;
    cout << "\nEnter source vertex: ";
    cin >> source;
    
    if (source < 0 || source >= V) {
        cout << "Error: Invalid source vertex!" << endl;
        return 1;
    }
    
    // Print graph structure
    bfDP.printGraph();
    bfDP.printAdjacencyMatrix();
    
    // Run Bellman-Ford algorithm
    auto result = bfDP.bellmanFord(source);
    bool noNegativeCycle = result.first;
    vector<int> distances = result.second;
    
    // Display results
    cout << "\n--- Results ---" << endl;
    
    if (noNegativeCycle) {
        bfDP.printShortestPaths(source, distances);
        bfDP.findNegativeCycles();
        bfDP.printAnalysis(source, distances);
    } else {
        cout << "Graph contains negative cycles. Shortest paths are not well-defined." << endl;
    }
    
    // Additional information
    cout << "\n--- Additional Information ---" << endl;
    cout << "Time Complexity: O(V * E) where V = " << V << ", E = " << E << endl;
    cout << "Space Complexity: O(V)" << endl;
    cout << "Method: Dynamic Programming (Bellman-Ford)" << endl;
    cout << "Handles: Negative edges (but not negative cycles)" << endl;
    
    return 0;
}
