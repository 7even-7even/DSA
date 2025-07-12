/*
 * Fibonacci.cpp
 * 
 * This program generates Fibonacci numbers using recursion.
 * 
 * Time Complexity: O(2^n) - exponential due to overlapping subproblems
 * Space Complexity: O(n) - recursion stack depth
 * 
 * Example Output:
 * Enter the number of Fibonacci terms: 8
 * Fibonacci Series: 0 1 1 2 3 5 8 13
 * 
 * Recursive Formula: F(n) = F(n-1) + F(n-2)
 * Base Cases: F(0) = 0, F(1) = 1
 */

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate nth Fibonacci number recursively
// Parameters: n - the position in Fibonacci sequence
// Returns: nth Fibonacci number
long long fibonacci(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n <= 1) {
        return n;
    }
    
    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate Fibonacci using dynamic programming (memoization)
// This is much more efficient than pure recursion
long long fibonacciDP(int n, vector<long long>& memo) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    
    // If already calculated, return from memo
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Calculate and store in memo
    memo[n] = fibonacciDP(n - 1, memo) + fibonacciDP(n - 2, memo);
    return memo[n];
}

// Function to generate Fibonacci series iteratively (for comparison)
vector<long long> fibonacciIterative(int n) {
    vector<long long> series;
    if (n >= 1) series.push_back(0);
    if (n >= 2) series.push_back(1);
    
    for (int i = 2; i < n; i++) {
        series.push_back(series[i-1] + series[i-2]);
    }
    return series;
}

int main() {
    int n;
    
    cout << "=== Fibonacci Series using Recursion ===" << endl;
    cout << "Enter the number of Fibonacci terms: ";
    cin >> n;
    
    // Input validation
    if (n <= 0) {
        cout << "Error: Please enter a positive number!" << endl;
        return 1;
    }
    
    if (n > 45) {
        cout << "Warning: Large numbers may cause overflow and slow execution!" << endl;
    }
    
    cout << "\n--- Recursive Approach (Individual Terms) ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << endl;
    }
    
    cout << "\n--- Dynamic Programming Approach (Memoization) ---" << endl;
    vector<long long> memo(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cout << "F(" << i << ") = " << fibonacciDP(i, memo) << endl;
    }
    
    cout << "\n--- Iterative Approach (Complete Series) ---" << endl;
    vector<long long> series = fibonacciIterative(n);
    cout << "Fibonacci Series: ";
    for (int i = 0; i < series.size(); i++) {
        cout << series[i];
        if (i < series.size() - 1) cout << " ";
    }
    cout << endl;
    
    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Pure Recursion:" << endl;
    cout << "  Time Complexity: O(2^n) - exponential" << endl;
    cout << "  Space Complexity: O(n) - recursion stack depth" << endl;
    cout << "\nDynamic Programming (Memoization):" << endl;
    cout << "  Time Complexity: O(n)" << endl;
    cout << "  Space Complexity: O(n)" << endl;
    
    cout << "\n--- Example Fibonacci Series ---" << endl;
    cout << "F(0) = 0" << endl;
    cout << "F(1) = 1" << endl;
    cout << "F(2) = 1" << endl;
    cout << "F(3) = 2" << endl;
    cout << "F(4) = 3" << endl;
    cout << "F(5) = 5" << endl;
    cout << "F(6) = 8" << endl;
    cout << "F(7) = 13" << endl;
    
    return 0;
}
