/*
 * Fibonacci Series using Dynamic Programming (Memoization)
 * 
 * Problem: Find the nth Fibonacci number efficiently
 * Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 * Formula: F(n) = F(n-1) + F(n-2) where F(0) = 0, F(1) = 1
 * 
 * Dynamic Programming Approach: Memoization (Top-down)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Expected Output Example:
 * Enter the value of n: 10
 * The 10th Fibonacci number is: 55
 * 
 * Series up to 10th term: 0 1 1 2 3 5 8 13 21 34 55
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class FibonacciDP {
private:
    vector<long long> memo;
    
    // Recursive function with memoization
    long long fibonacciMemo(int n) {
        // Base cases
        if (n <= 1) return n;
        
        // Check if already computed
        if (memo[n] != -1) {
            return memo[n];
        }
        
        // Compute and store in memo
        memo[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
        return memo[n];
    }
    
public:
    // Constructor initializes memoization array
    FibonacciDP(int maxN) {
        memo.resize(maxN + 1, -1);
        memo[0] = 0;
        memo[1] = 1;
    }
    
    // Get nth Fibonacci number
    long long getFibonacci(int n) {
        if (n < 0) {
            cout << "Error: n must be non-negative!" << endl;
            return -1;
        }
        return fibonacciMemo(n);
    }
    
    // Print Fibonacci series up to nth term
    void printSeries(int n) {
        cout << "Fibonacci series up to " << n << "th term: ";
        for (int i = 0; i <= n; i++) {
            cout << getFibonacci(i);
            if (i < n) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Fibonacci Series using Dynamic Programming ===" << endl;
    cout << "Enter the value of n (0 to calculate nth Fibonacci number): ";
    
    int n;
    cin >> n;
    
    // Input validation
    if (n < 0) {
        cout << "Error: Please enter a non-negative number!" << endl;
        return 1;
    }
    
    // Handle large numbers
    if (n > 90) {
        cout << "Warning: Large numbers may cause overflow!" << endl;
    }
    
    // Create FibonacciDP object with sufficient size
    FibonacciDP fibDP(n + 10);
    
    // Calculate and display result
    long long result = fibDP.getFibonacci(n);
    
    if (result != -1) {
        cout << "The " << n << "th Fibonacci number is: " << result << endl;
        
        // Print the series
        fibDP.printSeries(n);
        
        // Additional information
        cout << "\n--- Additional Information ---" << endl;
        cout << "Time Complexity: O(n)" << endl;
        cout << "Space Complexity: O(n)" << endl;
        cout << "Method: Memoization (Top-down DP)" << endl;
    }
    
    return 0;
}
