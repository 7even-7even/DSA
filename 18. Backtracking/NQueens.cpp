/*
 * NQueens.cpp
 * 
 * This program solves the N-Queens problem using backtracking.
 * 
 * Time Complexity: O(N!) - where N is the board size
 * Space Complexity: O(N²) - for the board representation
 * 
 * Example Output:
 * Enter board size (N): 4
 * Solutions for 4-Queens problem:
 * Solution 1:
 * . Q . .
 * . . . Q
 * Q . . .
 * . . Q .
 * 
 * Solution 2:
 * . . Q .
 * Q . . .
 * . . . Q
 * . Q . .
 * 
 * Total solutions: 2
 * 
 * Problem: Place N queens on an N×N chessboard so that no two queens threaten each other.
 * Rules: Queens can move horizontally, vertically, and diagonally.
 */

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class NQueensSolver {
private:
    int N;
    vector<vector<int>> board;
    vector<vector<vector<int>>> allSolutions;
    
public:
    NQueensSolver(int size) : N(size) {
        // Initialize board with 0s (empty)
        board.resize(N, vector<int>(N, 0));
    }
    
    // Function to check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col) {
        // Check row
        for (int j = 0; j < N; j++) {
            if (board[row][j] == 1) return false;
        }
        
        // Check column
        for (int i = 0; i < N; i++) {
            if (board[i][col] == 1) return false;
        }
        
        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) return false;
        }
        
        // Check lower diagonal on left side
        for (int i = row, j = col; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 1) return false;
        }
        
        // Check upper diagonal on right side
        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1) return false;
        }
        
        // Check lower diagonal on right side
        for (int i = row, j = col; i < N && j < N; i++, j++) {
            if (board[i][j] == 1) return false;
        }
        
        return true;
    }
    
    // Function to print the current board state
    void printBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
    
    // Function to save current solution
    void saveSolution() {
        allSolutions.push_back(board);
    }
    
    // Backtracking function to solve N-Queens
    bool solveNQueens(int col) {
        // Base case: if all queens are placed
        if (col >= N) {
            saveSolution();
            return true;
        }
        
        // Consider this column and try placing queen in all rows
        for (int row = 0; row < N; row++) {
            // Check if queen can be placed on board[row][col]
            if (isSafe(row, col)) {
                // Place queen
                board[row][col] = 1;
                
                // Recur to place rest of queens
                solveNQueens(col + 1);
                
                // Backtrack: remove queen from board[row][col]
                board[row][col] = 0;
            }
        }
        
        // If queen can't be placed in any row in this column, return false
        return false;
    }
    
    // Function to solve and display all solutions
    void solve() {
        cout << "Solving " << N << "-Queens problem..." << endl;
        
        auto start = chrono::high_resolution_clock::now();
        solveNQueens(0);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        cout << "\nTotal solutions found: " << allSolutions.size() << endl;
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        
        // Display all solutions
        for (int sol = 0; sol < allSolutions.size(); sol++) {
            cout << "\nSolution " << (sol + 1) << ":" << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (allSolutions[sol][i][j] == 1) {
                        cout << "Q ";
                    } else {
                        cout << ". ";
                    }
                }
                cout << endl;
            }
        }
    }
    
    // Function to demonstrate step-by-step process
    void demonstrateStepByStep() {
        cout << "\n=== Step-by-Step Demonstration ===" << endl;
        cout << "This shows how backtracking works for 4-Queens:" << endl;
        
        // Reset board
        board = vector<vector<int>>(4, vector<int>(4, 0));
        N = 4;
        
        cout << "\nStep 1: Try placing queen at (0,0)" << endl;
        board[0][0] = 1;
        printBoard();
        
        cout << "\nStep 2: Try placing queen at (2,1) - safe position" << endl;
        board[2][1] = 1;
        printBoard();
        
        cout << "\nStep 3: Try placing queen at (1,2) - safe position" << endl;
        board[1][2] = 1;
        printBoard();
        
        cout << "\nStep 4: Cannot place queen in column 3, backtrack!" << endl;
        board[1][2] = 0;
        board[2][1] = 0;
        board[0][0] = 0;
        printBoard();
        
        cout << "\nStep 5: Try different position (1,0)" << endl;
        board[1][0] = 1;
        printBoard();
    }
    
    // Function to show complexity analysis
    void showComplexityAnalysis() {
        cout << "\n--- Complexity Analysis ---" << endl;
        cout << "Time Complexity: O(N!)" << endl;
        cout << "  • For each column, we try N rows" << endl;
        cout << "  • This leads to N! possible combinations" << endl;
        cout << "Space Complexity: O(N²)" << endl;
        cout << "  • Board representation: N×N matrix" << endl;
        cout << "  • Recursion stack: O(N)" << endl;
        
        cout << "\n--- Known Solutions for Different N ---" << endl;
        cout << "N=1: 1 solution" << endl;
        cout << "N=2: 0 solutions" << endl;
        cout << "N=3: 0 solutions" << endl;
        cout << "N=4: 2 solutions" << endl;
        cout << "N=5: 10 solutions" << endl;
        cout << "N=6: 4 solutions" << endl;
        cout << "N=7: 40 solutions" << endl;
        cout << "N=8: 92 solutions" << endl;
    }
};

int main() {
    int N;
    
    cout << "=== N-Queens Problem Solver using Backtracking ===" << endl;
    cout << "Enter board size (N): ";
    cin >> N;
    
    // Input validation
    if (N <= 0) {
        cout << "Error: Please enter a positive number!" << endl;
        return 1;
    }
    
    if (N > 12) {
        cout << "Warning: Large board sizes may take significant time!" << endl;
    }
    
    // Create solver and solve
    NQueensSolver solver(N);
    solver.solve();
    
    // Show complexity analysis
    solver.showComplexityAnalysis();
    
    // Demonstrate step-by-step for small N
    if (N <= 6) {
        solver.demonstrateStepByStep();
    }
    
    cout << "\n--- Algorithm Explanation ---" << endl;
    cout << "1. Start from the leftmost column" << endl;
    cout << "2. Try placing queen in each row of current column" << endl;
    cout << "3. Check if placement is safe (no conflicts)" << endl;
    cout << "4. If safe, place queen and recur for next column" << endl;
    cout << "5. If all queens placed, save solution" << endl;
    cout << "6. If no safe position, backtrack and try next row" << endl;
    
    cout << "\n--- Backtracking Strategy ---" << endl;
    cout << "• When a dead end is reached, go back to previous step" << endl;
    cout << "• Remove the last placed queen" << endl;
    cout << "• Try the next possible position" << endl;
    cout << "• Continue until all solutions are found" << endl;
    
    return 0;
}
