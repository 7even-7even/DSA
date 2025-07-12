/*
 * MColoring.cpp
 * 
 * This program solves the M-Coloring problem using backtracking.
 * 
 * Time Complexity: O(M^N) - where M is number of colors, N is number of vertices
 * Space Complexity: O(N) - for color assignment and recursion stack
 * 
 * Example Output:
 * Enter number of vertices: 4
 * Enter number of colors: 3
 * Enter adjacency matrix (1 for connected, 0 for not connected):
 * 0 1 1 1
 * 1 0 1 0
 * 1 1 0 1
 * 1 0 1 0
 * 
 * Solution found!
 * Vertex 0: Color 1
 * Vertex 1: Color 2
 * Vertex 2: Color 3
 * Vertex 3: Color 2
 * 
 * Problem: Color a graph with M colors so that no two adjacent vertices have the same color.
 */

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class MColoringSolver {
private:
    int V; // Number of vertices
    int M; // Number of colors
    vector<vector<int>> graph; // Adjacency matrix
    vector<int> colorAssignment; // Color assigned to each vertex
    bool solutionFound;
    
public:
    MColoringSolver(int vertices, int colors) : V(vertices), M(colors) {
        graph.resize(V, vector<int>(V, 0));
        colorAssignment.resize(V, -1);
        solutionFound = false;
    }
    
    // Function to check if it's safe to assign color c to vertex v
    bool isSafe(int vertex, int color) {
        // Check all adjacent vertices
        for (int i = 0; i < V; i++) {
            // If there's an edge and adjacent vertex has same color
            if (graph[vertex][i] == 1 && colorAssignment[i] == color) {
                return false;
            }
        }
        return true;
    }
    
    // Function to print the color assignment
    void printColorAssignment() {
        cout << "\nColor Assignment:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": Color " << colorAssignment[i] << endl;
        }
    }
    
    // Function to print the graph
    void printGraph() {
        cout << "\nGraph (Adjacency Matrix):" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    // Backtracking function to solve M-Coloring
    bool solveMColoring(int vertex) {
        // Base case: if all vertices are colored
        if (vertex == V) {
            return true;
        }
        
        // Try all colors for current vertex
        for (int color = 1; color <= M; color++) {
            // Check if color can be assigned to vertex
            if (isSafe(vertex, color)) {
                // Assign color
                colorAssignment[vertex] = color;
                
                // Recur to assign colors to rest of vertices
                if (solveMColoring(vertex + 1)) {
                    return true;
                }
                
                // If assigning color doesn't lead to solution, backtrack
                colorAssignment[vertex] = -1;
            }
        }
        
        // If no color can be assigned to this vertex, return false
        return false;
    }
    
    // Function to input graph
    void inputGraph() {
        cout << "Enter adjacency matrix (1 for connected, 0 for not connected):" << endl;
        cout << "Enter " << V << " rows, each with " << V << " numbers:" << endl;
        
        for (int i = 0; i < V; i++) {
            cout << "Row " << (i + 1) << ": ";
            for (int j = 0; j < V; j++) {
                cin >> graph[i][j];
                
                // Input validation
                if (graph[i][j] != 0 && graph[i][j] != 1) {
                    cout << "Error: Matrix must contain only 0s and 1s!" << endl;
                    return;
                }
            }
        }
        
        // Ensure graph is undirected (symmetric)
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][j] != graph[j][i]) {
                    graph[i][j] = graph[j][i] = max(graph[i][j], graph[j][i]);
                }
            }
        }
    }
    
    // Function to solve and display solution
    void solve() {
        cout << "\nOriginal graph:";
        printGraph();
        
        auto start = chrono::high_resolution_clock::now();
        bool solved = solveMColoring(0);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        if (solved) {
            cout << "\nSolution found!" << endl;
            printColorAssignment();
            cout << "Time taken: " << duration.count() << " microseconds" << endl;
        } else {
            cout << "\nNo solution exists with " << M << " colors!" << endl;
            cout << "Try increasing the number of colors." << endl;
        }
    }
    
    // Function to demonstrate step-by-step coloring
    void demonstrateStepByStep() {
        cout << "\n=== Step-by-Step Demonstration ===" << endl;
        
        // Use a simple example
        V = 4;
        M = 3;
        graph = {
            {0, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 1, 0}
        };
        colorAssignment = vector<int>(V, -1);
        
        cout << "Graph:";
        printGraph();
        
        cout << "\nStep 1: Try coloring vertex 0 with color 1" << endl;
        colorAssignment[0] = 1;
        cout << "Vertex 0: Color 1" << endl;
        
        cout << "\nStep 2: Try coloring vertex 1 with color 2" << endl;
        colorAssignment[1] = 2;
        cout << "Vertex 1: Color 2" << endl;
        
        cout << "\nStep 3: Try coloring vertex 2 with color 3" << endl;
        colorAssignment[2] = 3;
        cout << "Vertex 2: Color 3" << endl;
        
        cout << "\nStep 4: Try coloring vertex 3 with color 2" << endl;
        colorAssignment[3] = 2;
        cout << "Vertex 3: Color 2" << endl;
        
        cout << "\nFinal coloring:";
        printColorAssignment();
    }
    
    // Function to show complexity analysis
    void showComplexityAnalysis() {
        cout << "\n--- Complexity Analysis ---" << endl;
        cout << "Time Complexity: O(M^N)" << endl;
        cout << "  • For each vertex, we try M colors" << endl;
        cout << "  • For N vertices, this leads to M^N combinations" << endl;
        cout << "Space Complexity: O(N)" << endl;
        cout << "  • Color assignment array: O(N)" << endl;
        cout << "  • Recursion stack: O(N)" << endl;
        
        cout << "\n--- Graph Coloring Rules ---" << endl;
        cout << "1. No two adjacent vertices can have the same color" << endl;
        cout << "2. All vertices must be colored" << endl;
        cout << "3. Use minimum number of colors possible" << endl;
        cout << "4. Chromatic number is the minimum colors needed" << endl;
    }
    
    // Function to find chromatic number (minimum colors needed)
    int findChromaticNumber() {
        for (int colors = 1; colors <= V; colors++) {
            M = colors;
            colorAssignment = vector<int>(V, -1);
            if (solveMColoring(0)) {
                return colors;
            }
        }
        return V; // Worst case: need V colors
    }
    
    // Function to validate graph
    bool isValidGraph() {
        // Check if graph is valid (no self-loops, undirected)
        for (int i = 0; i < V; i++) {
            if (graph[i][i] != 0) return false; // No self-loops
        }
        return true;
    }
    
    // Function to show all possible colorings
    void showAllColorings() {
        cout << "\n=== All Possible Colorings ===" << endl;
        vector<vector<int>> allSolutions;
        
        // Reset for finding all solutions
        colorAssignment = vector<int>(V, -1);
        findAllColorings(0, allSolutions);
        
        cout << "Total possible colorings: " << allSolutions.size() << endl;
        
        // Show first few solutions
        int maxToShow = min(5, (int)allSolutions.size());
        for (int i = 0; i < maxToShow; i++) {
            cout << "\nColoring " << (i + 1) << ":" << endl;
            for (int j = 0; j < V; j++) {
                cout << "Vertex " << j << ": Color " << allSolutions[i][j] << endl;
            }
        }
        
        if (allSolutions.size() > maxToShow) {
            cout << "... and " << (allSolutions.size() - maxToShow) << " more solutions" << endl;
        }
    }
    
private:
    // Function to find all possible colorings
    void findAllColorings(int vertex, vector<vector<int>>& solutions) {
        if (vertex == V) {
            solutions.push_back(colorAssignment);
            return;
        }
        
        for (int color = 1; color <= M; color++) {
            if (isSafe(vertex, color)) {
                colorAssignment[vertex] = color;
                findAllColorings(vertex + 1, solutions);
                colorAssignment[vertex] = -1;
            }
        }
    }
};

int main() {
    int V, M;
    
    cout << "=== M-Coloring Problem Solver using Backtracking ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of colors: ";
    cin >> M;
    
    // Input validation
    if (V <= 0 || M <= 0) {
        cout << "Error: Please enter positive numbers!" << endl;
        return 1;
    }
    
    if (M > V) {
        cout << "Warning: More colors than vertices may not be optimal!" << endl;
    }
    
    // Create solver and input graph
    MColoringSolver solver(V, M);
    solver.inputGraph();
    
    // Validate graph
    if (!solver.isValidGraph()) {
        cout << "Error: Invalid graph! Check for self-loops." << endl;
        return 1;
    }
    
    // Solve coloring problem
    solver.solve();
    
    // Show complexity analysis
    solver.showComplexityAnalysis();
    
    // Demonstrate step-by-step
    solver.demonstrateStepByStep();
    
    // Find chromatic number
    cout << "\n--- Chromatic Number Analysis ---" << endl;
    int chromaticNumber = solver.findChromaticNumber();
    cout << "Minimum colors needed (Chromatic Number): " << chromaticNumber << endl;
    
    if (M >= chromaticNumber) {
        cout << "Current number of colors is sufficient." << endl;
    } else {
        cout << "Current number of colors is insufficient." << endl;
    }
    
    // Show all possible colorings for small graphs
    if (V <= 6 && M <= 4) {
        solver.showAllColorings();
    }
    
    cout << "\n--- Algorithm Explanation ---" << endl;
    cout << "1. Start with the first vertex" << endl;
    cout << "2. Try assigning each color to current vertex" << endl;
    cout << "3. Check if color assignment is safe (no conflicts)" << endl;
    cout << "4. If safe, assign color and recur for next vertex" << endl;
    cout << "5. If all vertices colored, solution found" << endl;
    cout << "6. If dead end reached, backtrack and try next color" << endl;
    
    cout << "\n--- Backtracking Strategy ---" << endl;
    cout << "• When a dead end is reached, go back to previous vertex" << endl;
    cout << "• Remove the last color assignment" << endl;
    cout << "• Try the next possible color" << endl;
    cout << "• Continue until solution is found or all possibilities exhausted" << endl;
    
    cout << "\n--- Applications ---" << endl;
    cout << "• Map coloring (Four Color Theorem)" << endl;
    cout << "• Scheduling problems" << endl;
    cout << "• Register allocation in compilers" << endl;
    cout << "• Frequency assignment in wireless networks" << endl;
    cout << "• Sudoku solving" << endl;
    
    return 0;
}
