/*
 * Floyd-Warshall Algorithm using Dynamic Programming
 * 
 * Problem: Find shortest paths between all pairs of vertices in a weighted graph.
 * Can handle negative edges but not negative cycles.
 * 
 * Dynamic Programming Approach: Bottom-up
 * Time Complexity: O(V^3) where V = number of vertices
 * Space Complexity: O(V^2)
 * 
 * Expected Output Example:
 * Enter number of vertices: 4
 * 
 * Enter adjacency matrix (use INF for no edge):
 * 0 INF -2 INF
 * 4 0 3 INF
 * INF INF 0 2
 * INF -1 INF 0
 * 
 * All-pairs shortest paths:
 * 0 -> 0: 0
 * 0 -> 1: -1
 * 0 -> 2: -2
 * 0 -> 3: 0
 * 1 -> 0: 4
 * 1 -> 1: 0
 * 1 -> 2: 2
 * 1 -> 3: 4
 * 2 -> 0: 5
 * 2 -> 1: 1
 * 2 -> 2: 0
 * 2 -> 3: 2
 * 3 -> 0: 3
 * 3 -> 1: -1
 * 3 -> 2: 1
 * 3 -> 3: 0
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

class FloydWarshallDP {
private:
    vector<vector<int>> graph;
    vector<vector<int>> dist;
    vector<vector<int>> next;
    int V;
    const int INF = INT_MAX;
    
public:
    FloydWarshallDP(int vertices) {
        V = vertices;
        graph.resize(V, vector<int>(V, INF));
        dist.resize(V, vector<int>(V, INF));
        next.resize(V, vector<int>(V, -1));
        
        // Initialize diagonal to 0
        for (int i = 0; i < V; i++) {
            graph[i][i] = 0;
            dist[i][i] = 0;
        }
    }
    
    void setEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        dist[u][v] = weight;
        if (weight != INF) {
            next[u][v] = v;
        }
    }
    
    // Floyd-Warshall algorithm
    bool floydWarshall() {
        // Copy graph to distance matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = graph[i][j];
                if (graph[i][j] != INF) {
                    next[i][j] = j;
                }
            }
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
        
        // Check for negative cycles
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                return false;  // Negative cycle detected
            }
        }
        
        return true;
    }
    
    // Print the distance matrix
    void printDistanceMatrix() {
        cout << "\n--- Distance Matrix ---" << endl;
        
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
                if (dist[i][j] == INF) {
                    cout << setw(4) << "INF";
                } else {
                    cout << setw(4) << dist[i][j];
                }
            }
            cout << endl;
        }
    }
    
    // Print all shortest paths
    void printAllShortestPaths() {
        cout << "\n--- All-Pairs Shortest Paths ---" << endl;
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << i << " -> " << j << ": ";
                if (dist[i][j] == INF) {
                    cout << "INFINITY (no path)" << endl;
                } else {
                    cout << dist[i][j] << endl;
                }
            }
        }
    }
    
    // Reconstruct and print a specific path
    void printPath(int start, int end) {
        if (next[start][end] == -1) {
            cout << "No path exists from " << start << " to " << end << endl;
            return;
        }
        
        cout << "Path from " << start << " to " << end << ": ";
        cout << start;
        
        int current = start;
        while (current != end) {
            current = next[current][end];
            cout << " -> " << current;
        }
        
        cout << " (distance: " << dist[start][end] << ")" << endl;
    }
    
    // Print all paths
    void printAllPaths() {
        cout << "\n--- All Paths ---" << endl;
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j) {
                    printPath(i, j);
                }
            }
        }
    }
    
    // Print the original graph
    void printOriginalGraph() {
        cout << "\n--- Original Graph ---" << endl;
        
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
                if (graph[i][j] == INF) {
                    cout << setw(4) << "INF";
                } else {
                    cout << setw(4) << graph[i][j];
                }
            }
            cout << endl;
        }
    }
    
    // Find the diameter of the graph
    void findDiameter() {
        int maxDist = -1;
        int minDist = INF;
        int totalPaths = 0;
        int reachablePairs = 0;
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j && dist[i][j] != INF) {
                    maxDist = max(maxDist, dist[i][j]);
                    minDist = min(minDist, dist[i][j]);
                    reachablePairs++;
                }
                if (i != j) totalPaths++;
            }
        }
        
        cout << "\n--- Graph Analysis ---" << endl;
        cout << "Diameter (maximum shortest path): " << maxDist << endl;
        cout << "Minimum shortest path: " << minDist << endl;
        cout << "Reachable pairs: " << reachablePairs << "/" << totalPaths << endl;
    }
    
    // Check for negative cycles
    bool hasNegativeCycle() {
        for (int i = 0; i < V; i++) {
            if (dist[i][i] < 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    cout << "=== Floyd-Warshall Algorithm using Dynamic Programming ===" << endl;
    
    // Get number of vertices
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    if (V <= 0) {
        cout << "Error: Number of vertices must be positive!" << endl;
        return 1;
    }
    
    // Create FloydWarshallDP object
    FloydWarshallDP fwDP(V);
    
    // Get adjacency matrix
    cout << "\nEnter adjacency matrix (use -1 for INF, or actual weights):" << endl;
    cout << "Note: Use -1 to represent INF (no edge)" << endl;
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int weight;
            cout << "Edge " << i << " -> " << j << ": ";
            cin >> weight;
            
            if (weight == -1) {
                fwDP.setEdge(i, j, INT_MAX);
            } else {
                fwDP.setEdge(i, j, weight);
            }
        }
    }
    
    // Print original graph
    fwDP.printOriginalGraph();
    
    // Run Floyd-Warshall algorithm
    bool noNegativeCycle = fwDP.floydWarshall();
    
    // Display results
    cout << "\n--- Results ---" << endl;
    
    if (noNegativeCycle) {
        fwDP.printDistanceMatrix();
        fwDP.printAllShortestPaths();
        fwDP.findDiameter();
        
        // Print some example paths
        cout << "\n--- Example Paths ---" << endl;
        for (int i = 0; i < min(V, 3); i++) {
            for (int j = 0; j < min(V, 3); j++) {
                if (i != j) {
                    fwDP.printPath(i, j);
                }
            }
        }
        
        if (V > 3) {
            cout << "... (showing only first 3x3 paths for brevity)" << endl;
        }
    } else {
        cout << "Graph contains negative cycles. Shortest paths are not well-defined." << endl;
    }
    
    // Additional information
    cout << "\n--- Additional Information ---" << endl;
    cout << "Time Complexity: O(V^3) where V = " << V << endl;
    cout << "Space Complexity: O(V^2)" << endl;
    cout << "Method: Dynamic Programming (Floyd-Warshall)" << endl;
    cout << "Handles: All-pairs shortest paths, negative edges" << endl;
    
    return 0;
}
