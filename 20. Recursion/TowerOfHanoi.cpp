/*
 * TowerOfHanoi.cpp
 * 
 * This program solves the Tower of Hanoi puzzle using recursion.
 * 
 * Time Complexity: O(2^n) - where n is the number of disks
 * Space Complexity: O(n) - recursion stack depth
 * 
 * Example Output:
 * Enter number of disks: 3
 * Steps to solve Tower of Hanoi with 3 disks:
 * Move disk 1 from A to C
 * Move disk 2 from A to B
 * Move disk 1 from C to B
 * Move disk 3 from A to C
 * Move disk 1 from B to A
 * Move disk 2 from B to C
 * Move disk 1 from A to C
 * 
 * Total moves: 7
 * 
 * Rules:
 * 1. Only one disk can be moved at a time
 * 2. A larger disk cannot be placed on top of a smaller disk
 * 3. Only the top disk on any rod can be moved
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector> // Added for visualizeTowers function
using namespace std;

// Global variable to count moves
int moveCount = 0;

// Function to solve Tower of Hanoi recursively
// Parameters: n - number of disks, source - source rod, auxiliary - auxiliary rod, destination - destination rod
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: if only one disk, move it directly from source to destination
    if (n == 1) {
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        moveCount++;
        return;
    }
    
    // Recursive case: solve in three steps
    // Step 1: Move n-1 disks from source to auxiliary using destination as auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Step 2: Move the largest disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    moveCount++;
    
    // Step 3: Move n-1 disks from auxiliary to destination using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// Function to calculate minimum moves required (mathematical formula)
// Formula: 2^n - 1
long long calculateMinMoves(int n) {
    return (1LL << n) - 1;  // 2^n - 1
}

// Function to visualize the towers (simplified version)
void visualizeTowers(int n) {
    cout << "\n--- Tower Visualization ---" << endl;
    cout << "A: ";
    for (int i = n; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    cout << "B: " << endl;
    cout << "C: " << endl;
    cout << "-------------------" << endl;
}

// Function to demonstrate the solution step by step with visualization
void solveWithVisualization(int n) {
    cout << "\n=== Step-by-Step Solution with Visualization ===" << endl;
    
    // Initialize towers as stacks
    stack<int> towerA, towerB, towerC;
    
    // Fill tower A with disks (largest at bottom)
    for (int i = n; i >= 1; i--) {
        towerA.push(i);
    }
    
    // Function to print current state of towers
    auto printTowers = [&](const string& step) {
        cout << "\n" << step << endl;
        cout << "A: ";
        stack<int> tempA = towerA;
        vector<int> disksA;
        while (!tempA.empty()) {
            disksA.push_back(tempA.top());
            tempA.pop();
        }
        for (int i = disksA.size() - 1; i >= 0; i--) {
            cout << disksA[i] << " ";
        }
        cout << endl;
        
        cout << "B: ";
        stack<int> tempB = towerB;
        vector<int> disksB;
        while (!tempB.empty()) {
            disksB.push_back(tempB.top());
            tempB.pop();
        }
        for (int i = disksB.size() - 1; i >= 0; i--) {
            cout << disksB[i] << " ";
        }
        cout << endl;
        
        cout << "C: ";
        stack<int> tempC = towerC;
        vector<int> disksC;
        while (!tempC.empty()) {
            disksC.push_back(tempC.top());
            tempC.pop();
        }
        for (int i = disksC.size() - 1; i >= 0; i--) {
            cout << disksC[i] << " ";
        }
        cout << endl;
        cout << "-------------------" << endl;
    };
    
    printTowers("Initial State");
    
    // For demonstration, we'll show the first few moves
    if (n >= 1) {
        // Move disk 1 from A to C
        if (!towerA.empty()) {
            towerC.push(towerA.top());
            towerA.pop();
            printTowers("Move disk 1 from A to C");
        }
    }
    
    if (n >= 2) {
        // Move disk 2 from A to B
        if (!towerA.empty()) {
            towerB.push(towerA.top());
            towerA.pop();
            printTowers("Move disk 2 from A to B");
        }
        
        // Move disk 1 from C to B
        if (!towerC.empty()) {
            towerB.push(towerC.top());
            towerC.pop();
            printTowers("Move disk 1 from C to B");
        }
    }
    
    cout << "\n... (continuing with recursive solution)" << endl;
}

int main() {
    int n;
    
    cout << "=== Tower of Hanoi Solver using Recursion ===" << endl;
    cout << "Enter number of disks: ";
    cin >> n;
    
    // Input validation
    if (n <= 0) {
        cout << "Error: Please enter a positive number!" << endl;
        return 1;
    }
    
    if (n > 20) {
        cout << "Warning: Large number of disks will generate many moves!" << endl;
    }
    
    cout << "\n--- Recursive Solution ---" << endl;
    cout << "Steps to solve Tower of Hanoi with " << n << " disks:" << endl;
    towerOfHanoi(n, 'A', 'B', 'C');
    
    cout << "\nTotal moves: " << moveCount << endl;
    
    cout << "\n--- Mathematical Verification ---" << endl;
    long long expectedMoves = calculateMinMoves(n);
    cout << "Expected minimum moves: " << expectedMoves << endl;
    cout << "Formula: 2^" << n << " - 1 = " << expectedMoves << endl;
    
    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Time Complexity: O(2^n)" << endl;
    cout << "Space Complexity: O(n) - recursion stack depth" << endl;
    cout << "Number of moves: 2^n - 1" << endl;
    
    cout << "\n--- Example Solutions ---" << endl;
    cout << "1 disk: 1 move" << endl;
    cout << "2 disks: 3 moves" << endl;
    cout << "3 disks: 7 moves" << endl;
    cout << "4 disks: 15 moves" << endl;
    cout << "5 disks: 31 moves" << endl;
    
    // Show visualization for small number of disks
    if (n <= 5) {
        solveWithVisualization(n);
    }
    
    cout << "\n--- Rules Reminder ---" << endl;
    cout << "1. Only one disk can be moved at a time" << endl;
    cout << "2. A larger disk cannot be placed on top of a smaller disk" << endl;
    cout << "3. Only the top disk on any rod can be moved" << endl;
    
    return 0;
}
