/*
 * Multi-Stage Graph Problem using Dynamic Programming
 * 
 * Problem: Find the shortest path from source to destination in a multi-stage graph
 * where vertices are divided into stages and edges only go from one stage to the next.
 * 
 * Dynamic Programming Approach: Bottom-up
 * Time Complexity: O(V + E) where V = vertices, E = edges
 * Space Complexity: O(V)
 * 
 * Expected Output Example:
 * Enter number of stages: 4
 * Enter number of vertices in each stage:
 * Stage 0: 1
 * Stage 1: 2
 * Stage 2: 2
 * Stage 3: 1
 * 
 * Enter edges (from_vertex to_vertex weight):
 * 0 1 2
 * 0 2 1
 * 1 3 3
 * 1 4 2
 * 2 3 1
 * 2 4 4
 * 3 5 2
 * 4 5 3
 * 
 * Shortest path: 0 -> 2 -> 3 -> 5
 * Total cost: 4
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, weight;
    
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

class MultiStageGraphDP {
private:
    vector<vector<int>> stages;  // vertices in each stage
    vector<Edge> edges;
    int numStages;
    int totalVertices;
    
public:
    MultiStageGraphDP(int stages) {
        numStages = stages;
        totalVertices = 0;
    }
    
    void addStage(int vertexCount) {
        vector<int> stageVertices;
        for (int i = 0; i < vertexCount; i++) {
            stageVertices.push_back(totalVertices + i);
        }
        stages.push_back(stageVertices);
        totalVertices += vertexCount;
    }
    
    void addEdge(int from, int to, int weight) {
        edges.push_back(Edge(from, to, weight));
    }
    
    // Find shortest path using dynamic programming
    pair<int, vector<int>> findShortestPath() {
        // Initialize DP array
        vector<int> dp(totalVertices, INT_MAX);
        vector<int> parent(totalVertices, -1);
        
        // Set source vertex (first vertex of first stage)
        dp[0] = 0;
        
        // Process each stage
        for (int stage = 0; stage < numStages - 1; stage++) {
            for (int vertex : stages[stage]) {
                if (dp[vertex] == INT_MAX) continue;
                
                // Check all edges from current vertex
                for (const Edge& edge : edges) {
                    if (edge.from == vertex) {
                        int newDist = dp[vertex] + edge.weight;
                        if (newDist < dp[edge.to]) {
                            dp[edge.to] = newDist;
                            parent[edge.to] = vertex;
                        }
                    }
                }
            }
        }
        
        // Find destination vertex (last vertex of last stage)
        int destination = stages[numStages - 1].back();
        
        if (dp[destination] == INT_MAX) {
            return {-1, {}};  // No path exists
        }
        
        // Reconstruct path
        vector<int> path;
        int current = destination;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());
        
        return {dp[destination], path};
    }
    
    // Print the graph structure
    void printGraph() {
        cout << "\n--- Multi-Stage Graph Structure ---" << endl;
        cout << "Number of stages: " << numStages << endl;
        cout << "Total vertices: " << totalVertices << endl;
        
        for (int i = 0; i < numStages; i++) {
            cout << "Stage " << i << ": ";
            for (int vertex : stages[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
        
        cout << "\nEdges:" << endl;
        for (const Edge& edge : edges) {
            cout << "  " << edge.from << " -> " << edge.to 
                 << " (weight: " << edge.weight << ")" << endl;
        }
    }
    
    // Print adjacency matrix
    void printAdjacencyMatrix() {
        cout << "\n--- Adjacency Matrix ---" << endl;
        
        // Initialize matrix
        vector<vector<int>> matrix(totalVertices, vector<int>(totalVertices, INT_MAX));
        
        // Fill with edge weights
        for (const Edge& edge : edges) {
            matrix[edge.from][edge.to] = edge.weight;
        }
        
        // Set diagonal to 0
        for (int i = 0; i < totalVertices; i++) {
            matrix[i][i] = 0;
        }
        
        // Print header
        cout << "    ";
        for (int j = 0; j < totalVertices; j++) {
            printf("%3d ", j);
        }
        cout << endl;
        
        // Print matrix
        for (int i = 0; i < totalVertices; i++) {
            printf("%3d ", i);
            for (int j = 0; j < totalVertices; j++) {
                if (matrix[i][j] == INT_MAX) {
                    printf("INF ");
                } else {
                    printf("%3d ", matrix[i][j]);
                }
            }
            cout << endl;
        }
    }
    
    // Print all possible paths (for smaller graphs)
    void printAllPaths() {
        cout << "\n--- All Possible Paths ---" << endl;
        
        // Find all paths using DFS
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        vector<bool> visited(totalVertices, false);
        
        findAllPaths(0, stages[numStages - 1].back(), currentPath, visited, allPaths);
        
        cout << "Total paths from source to destination: " << allPaths.size() << endl;
        
        // Print first few paths
        int maxPaths = min(5, (int)allPaths.size());
        for (int i = 0; i < maxPaths; i++) {
            cout << "Path " << (i + 1) << ": ";
            int cost = calculatePathCost(allPaths[i]);
            for (int j = 0; j < allPaths[i].size(); j++) {
                cout << allPaths[i][j];
                if (j < allPaths[i].size() - 1) cout << " -> ";
            }
            cout << " (cost: " << cost << ")" << endl;
        }
        
        if (allPaths.size() > maxPaths) {
            cout << "... (showing only first " << maxPaths << " paths)" << endl;
        }
    }
    
private:
    void findAllPaths(int current, int destination, vector<int>& path, 
                     vector<bool>& visited, vector<vector<int>>& allPaths) {
        path.push_back(current);
        visited[current] = true;
        
        if (current == destination) {
            allPaths.push_back(path);
        } else {
            for (const Edge& edge : edges) {
                if (edge.from == current && !visited[edge.to]) {
                    findAllPaths(edge.to, destination, path, visited, allPaths);
                }
            }
        }
        
        path.pop_back();
        visited[current] = false;
    }
    
    int calculatePathCost(const vector<int>& path) {
        int cost = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            for (const Edge& edge : edges) {
                if (edge.from == path[i] && edge.to == path[i + 1]) {
                    cost += edge.weight;
                    break;
                }
            }
        }
        return cost;
    }
    
public:
    // Print stage-by-stage analysis
    void printStageAnalysis() {
        cout << "\n--- Stage-by-Stage Analysis ---" << endl;
        
        for (int stage = 0; stage < numStages; stage++) {
            cout << "Stage " << stage << ":" << endl;
            cout << "  Vertices: ";
            for (int vertex : stages[stage]) {
                cout << vertex << " ";
            }
            cout << endl;
            
            // Count incoming and outgoing edges
            int incoming = 0, outgoing = 0;
            for (const Edge& edge : edges) {
                bool isIncoming = false, isOutgoing = false;
                for (int vertex : stages[stage]) {
                    if (edge.to == vertex) isIncoming = true;
                    if (edge.from == vertex) isOutgoing = true;
                }
                if (isIncoming) incoming++;
                if (isOutgoing) outgoing++;
            }
            
            cout << "  Incoming edges: " << incoming << endl;
            cout << "  Outgoing edges: " << outgoing << endl;
            cout << endl;
        }
    }
    
    // Find optimal path with detailed breakdown
    void printOptimalPath(const vector<int>& path, int cost) {
        cout << "\n--- Optimal Path Analysis ---" << endl;
        cout << "Shortest path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Total cost: " << cost << endl;
        
        // Show cost breakdown
        cout << "\nCost breakdown:" << endl;
        for (int i = 0; i < path.size() - 1; i++) {
            for (const Edge& edge : edges) {
                if (edge.from == path[i] && edge.to == path[i + 1]) {
                    cout << "  " << path[i] << " -> " << path[i + 1] 
                         << ": " << edge.weight << endl;
                    break;
                }
            }
        }
        
        // Show stage progression
        cout << "\nStage progression:" << endl;
        for (int i = 0; i < path.size(); i++) {
            int stage = -1;
            for (int s = 0; s < numStages; s++) {
                for (int vertex : stages[s]) {
                    if (vertex == path[i]) {
                        stage = s;
                        break;
                    }
                }
                if (stage != -1) break;
            }
            cout << "  Vertex " << path[i] << " is in Stage " << stage << endl;
        }
    }
};

int main() {
    cout << "=== Multi-Stage Graph Problem using Dynamic Programming ===" << endl;
    
    // Get number of stages
    int numStages;
    cout << "Enter number of stages: ";
    cin >> numStages;
    
    if (numStages < 2) {
        cout << "Error: Number of stages must be at least 2!" << endl;
        return 1;
    }
    
    // Create MultiStageGraphDP object
    MultiStageGraphDP msgDP(numStages);
    
    // Get vertices in each stage
    cout << "\nEnter number of vertices in each stage:" << endl;
    for (int i = 0; i < numStages; i++) {
        int vertexCount;
        cout << "Stage " << i << ": ";
        cin >> vertexCount;
        
        if (vertexCount <= 0) {
            cout << "Error: Number of vertices must be positive!" << endl;
            return 1;
        }
        
        msgDP.addStage(vertexCount);
    }
    
    // Get edges
    cout << "\nEnter edges (from_vertex to_vertex weight):" << endl;
    cout << "Note: Edges must go from one stage to the next stage only" << endl;
    
    int edgeCount = 0;
    while (true) {
        int from, to, weight;
        cout << "Edge " << (edgeCount + 1) << " (or -1 -1 -1 to finish): ";
        cin >> from >> to >> weight;
        
        if (from == -1 && to == -1 && weight == -1) {
            break;
        }
        
        if (from < 0 || to < 0 || weight < 0) {
            cout << "Error: Invalid edge parameters!" << endl;
            return 1;
        }
        
        msgDP.addEdge(from, to, weight);
        edgeCount++;
    }
    
    // Print graph structure
    msgDP.printGraph();
    msgDP.printAdjacencyMatrix();
    msgDP.printStageAnalysis();
    
    // Find shortest path
    auto result = msgDP.findShortestPath();
    int shortestCost = result.first;
    vector<int> shortestPath = result.second;
    
    // Display results
    cout << "\n--- Results ---" << endl;
    
    if (shortestCost == -1) {
        cout << "No path exists from source to destination!" << endl;
    } else {
        msgDP.printOptimalPath(shortestPath, shortestCost);
        msgDP.printAllPaths();
    }
    
    // Additional information
    cout << "\n--- Additional Information ---" << endl;
    cout << "Time Complexity: O(V + E) where V = vertices, E = edges" << endl;
    cout << "Space Complexity: O(V)" << endl;
    cout << "Method: Dynamic Programming (Multi-Stage Graph)" << endl;
    cout << "Problem Type: Shortest path in directed acyclic graph" << endl;
    cout << "Special Property: Vertices are organized in stages" << endl;
    
    return 0;
}
