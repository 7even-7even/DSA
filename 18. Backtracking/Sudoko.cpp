/*
 * Sudoko.cpp
 * 
 * This program solves Sudoku puzzles using backtracking.
 * 
 * Time Complexity: O(9^(N*N)) - where N*N is the number of empty cells
 * Space Complexity: O(N*N) - for the board representation
 * 
 * Example Output:
 * Enter Sudoku puzzle (use 0 for empty cells):
 * 5 3 0 0 7 0 0 0 0
 * 6 0 0 1 9 5 0 0 0
 * 0 9 8 0 0 0 0 6 0
 * 8 0 0 0 6 0 0 0 3
 * 4 0 0 8 0 3 0 0 1
 * 7 0 0 0 2 0 0 0 6
 * 0 6 0 0 0 0 2 8 0
 * 0 0 0 4 1 9 0 0 5
 * 0 0 0 0 8 0 0 7 9
 * 
 * Solution:
 * 5 3 4 6 7 8 9 1 2
 * 6 7 2 1 9 5 3 4 8
 * 1 9 8 3 4 2 5 6 7
 * 8 5 9 7 6 1 4 2 3
 * 4 2 6 8 5 3 7 9 1
 * 7 1 3 9 2 4 8 5 6
 * 9 6 1 5 3 7 2 8 4
 * 2 8 7 4 1 9 6 3 5
 * 3 4 5 2 8 6 1 7 9
 */

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class SudokuSolver {
private:
    static const int N = 9;
    vector<vector<int>> board;
    bool solutionFound;
    
public:
    SudokuSolver() {
        board.resize(N, vector<int>(N, 0));
        solutionFound = false;
    }
    
    // Function to check if a number can be placed at (row, col)
    bool isValid(int row, int col, int num) {
        // Check row
        for (int j = 0; j < N; j++) {
            if (board[row][j] == num) return false;
        }
        
        // Check column
        for (int i = 0; i < N; i++) {
            if (board[i][col] == num) return false;
        }
        
        // Check 3x3 box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) return false;
            }
        }
        
        return true;
    }
    
    // Function to find empty cell (returns false if no empty cell found)
    bool findEmptyCell(int& row, int& col) {
        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                if (board[row][col] == 0) return true;
            }
        }
        return false;
    }
    
    // Function to print the Sudoku board
    void printBoard() {
        cout << endl;
        for (int i = 0; i < N; i++) {
            if (i % 3 == 0 && i != 0) {
                cout << "- - - - - - - - - - - -" << endl;
            }
            for (int j = 0; j < N; j++) {
                if (j % 3 == 0 && j != 0) {
                    cout << "| ";
                }
                if (board[i][j] == 0) {
                    cout << ". ";
                } else {
                    cout << board[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Backtracking function to solve Sudoku
    bool solveSudoku() {
        int row, col;
        
        // If no empty cell, puzzle is solved
        if (!findEmptyCell(row, col)) {
            return true;
        }
        
        // Try digits 1 to 9
        for (int num = 1; num <= 9; num++) {
            // Check if number can be placed
            if (isValid(row, col, num)) {
                // Place number
                board[row][col] = num;
                
                // Recursively solve rest of puzzle
                if (solveSudoku()) {
                    return true;
                }
                
                // If placing num doesn't lead to solution, backtrack
                board[row][col] = 0;
            }
        }
        
        // No solution exists
        return false;
    }
    
    // Function to input Sudoku puzzle
    void inputPuzzle() {
        cout << "Enter Sudoku puzzle (use 0 for empty cells):" << endl;
        cout << "Enter 9 rows, each with 9 numbers separated by spaces:" << endl;
        
        for (int i = 0; i < N; i++) {
            cout << "Row " << (i + 1) << ": ";
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
                
                // Input validation
                if (board[i][j] < 0 || board[i][j] > 9) {
                    cout << "Error: Numbers must be between 0 and 9!" << endl;
                    return;
                }
            }
        }
    }
    
    // Function to solve and display solution
    void solve() {
        cout << "\nOriginal puzzle:";
        printBoard();
        
        auto start = chrono::high_resolution_clock::now();
        bool solved = solveSudoku();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        if (solved) {
            cout << "Solution found!" << endl;
            cout << "Solution:";
            printBoard();
            cout << "Time taken: " << duration.count() << " microseconds" << endl;
        } else {
            cout << "No solution exists for this puzzle!" << endl;
        }
    }
    
    // Function to demonstrate step-by-step solving
    void demonstrateStepByStep() {
        cout << "\n=== Step-by-Step Demonstration ===" << endl;
        
        // Use a simple example
        vector<vector<int>> demo = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
        
        board = demo;
        cout << "Original puzzle:";
        printBoard();
        
        cout << "Step 1: Find first empty cell (0,2)" << endl;
        cout << "Step 2: Try placing 1, 2, 3... until valid number found" << endl;
        cout << "Step 3: Place valid number and recur for next empty cell" << endl;
        cout << "Step 4: If dead end reached, backtrack and try next number" << endl;
        
        // Solve the demo
        if (solveSudoku()) {
            cout << "\nFinal solution:";
            printBoard();
        }
    }
    
    // Function to show complexity analysis
    void showComplexityAnalysis() {
        cout << "\n--- Complexity Analysis ---" << endl;
        cout << "Time Complexity: O(9^(N*N))" << endl;
        cout << "  • For each empty cell, we try 9 numbers" << endl;
        cout << "  • In worst case, all 81 cells are empty" << endl;
        cout << "  • This leads to 9^81 possible combinations" << endl;
        cout << "Space Complexity: O(N*N)" << endl;
        cout << "  • Board representation: 9×9 matrix" << endl;
        cout << "  • Recursion stack: O(N*N) in worst case" << endl;
        
        cout << "\n--- Sudoku Rules ---" << endl;
        cout << "1. Each row must contain numbers 1-9 without repetition" << endl;
        cout << "2. Each column must contain numbers 1-9 without repetition" << endl;
        cout << "3. Each 3×3 box must contain numbers 1-9 without repetition" << endl;
        cout << "4. Some cells are pre-filled (given numbers)" << endl;
    }
    
    // Function to validate Sudoku puzzle
    bool isValidPuzzle() {
        // Check rows
        for (int i = 0; i < N; i++) {
            vector<bool> used(10, false);
            for (int j = 0; j < N; j++) {
                if (board[i][j] != 0) {
                    if (used[board[i][j]]) return false;
                    used[board[i][j]] = true;
                }
            }
        }
        
        // Check columns
        for (int j = 0; j < N; j++) {
            vector<bool> used(10, false);
            for (int i = 0; i < N; i++) {
                if (board[i][j] != 0) {
                    if (used[board[i][j]]) return false;
                    used[board[i][j]] = true;
                }
            }
        }
        
        // Check 3x3 boxes
        for (int box = 0; box < N; box++) {
            vector<bool> used(10, false);
            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = board[startRow + i][startCol + j];
                    if (num != 0) {
                        if (used[num]) return false;
                        used[num] = true;
                    }
                }
            }
        }
        
        return true;
    }
};

int main() {
    cout << "=== Sudoku Solver using Backtracking ===" << endl;
    
    SudokuSolver solver;
    
    // Input puzzle
    solver.inputPuzzle();
    
    // Validate input
    if (!solver.isValidPuzzle()) {
        cout << "Error: Invalid Sudoku puzzle! Check for duplicate numbers." << endl;
        return 1;
    }
    
    // Solve puzzle
    solver.solve();
    
    // Show complexity analysis
    solver.showComplexityAnalysis();
    
    // Demonstrate step-by-step
    solver.demonstrateStepByStep();
    
    cout << "\n--- Algorithm Explanation ---" << endl;
    cout << "1. Find an empty cell in the puzzle" << endl;
    cout << "2. Try placing numbers 1-9 in that cell" << endl;
    cout << "3. Check if placement is valid (no conflicts)" << endl;
    cout << "4. If valid, place number and recur for next empty cell" << endl;
    cout << "5. If no solution found, backtrack and try next number" << endl;
    cout << "6. Continue until puzzle is solved or no solution exists" << endl;
    
    cout << "\n--- Backtracking Strategy ---" << endl;
    cout << "• When a dead end is reached, go back to previous step" << endl;
    cout << "• Remove the last placed number" << endl;
    cout << "• Try the next possible number" << endl;
    cout << "• Continue until solution is found or all possibilities exhausted" << endl;
    
    cout << "\n--- Tips for Solving ---" << endl;
    cout << "• Start with cells that have fewer possibilities" << endl;
    cout << "• Use pencil marks to track possible numbers" << endl;
    cout << "• Look for naked singles and hidden singles" << endl;
    cout << "• Use elimination techniques to reduce possibilities" << endl;
    
    return 0;
}
