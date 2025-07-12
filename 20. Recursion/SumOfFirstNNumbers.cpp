/*
 * SumOfFirstNNumbers.cpp
 * 
 * This program calculates the sum of first N natural numbers using recursion.
 * 
 * Time Complexity: O(n) - where n is the input number
 * Space Complexity: O(n) - recursion stack depth
 * 
 * Example Output:
 * Enter a number: 5
 * Sum of first 5 numbers = 15
 * 
 * Recursive Formula: sum(n) = n + sum(n-1)
 * Base Case: sum(1) = 1
 * Mathematical Formula: sum(n) = n*(n+1)/2
 */

#include <iostream>
using namespace std;

// Function to calculate sum of first n numbers recursively
// Parameters: n - the number up to which we want to calculate sum
// Returns: sum of first n natural numbers
long long sumRecursive(int n) {
    // Base case: sum of first 1 number is 1
    if (n == 1) {
        return 1;
    }
    
    // Recursive case: sum(n) = n + sum(n-1)
    return n + sumRecursive(n - 1);
}

// Function to calculate sum using mathematical formula (for comparison)
// Formula: sum(n) = n*(n+1)/2
long long sumFormula(int n) {
    return (long long)n * (n + 1) / 2;
}

// Function to calculate sum iteratively (for comparison)
long long sumIterative(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Function to calculate sum using tail recursion (optimized)
// Parameters: n - current number, acc - accumulator for sum
// Returns: sum of first n natural numbers
long long sumTailRecursive(int n, long long acc = 0) {
    // Base case: when n reaches 0, return accumulated sum
    if (n == 0) {
        return acc;
    }
    
    // Tail recursive case: add current number to accumulator
    return sumTailRecursive(n - 1, acc + n);
}

int main() {
    int n;
    
    cout << "=== Sum of First N Numbers using Recursion ===" << endl;
    cout << "Enter a number: ";
    cin >> n;
    
    // Input validation
    if (n <= 0) {
        cout << "Error: Please enter a positive number!" << endl;
        return 1;
    }
    
    if (n > 1000000) {
        cout << "Warning: Very large numbers may cause stack overflow!" << endl;
    }
    
    cout << "\n--- Recursive Approach ---" << endl;
    cout << "Sum of first " << n << " numbers = " << sumRecursive(n) << endl;
    
    cout << "\n--- Tail Recursive Approach (Optimized) ---" << endl;
    cout << "Sum of first " << n << " numbers = " << sumTailRecursive(n) << endl;
    
    cout << "\n--- Mathematical Formula Approach ---" << endl;
    cout << "Sum of first " << n << " numbers = " << sumFormula(n) << endl;
    
    cout << "\n--- Iterative Approach (for comparison) ---" << endl;
    cout << "Sum of first " << n << " numbers = " << sumIterative(n) << endl;
    
    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Recursive Approach:" << endl;
    cout << "  Time Complexity: O(n)" << endl;
    cout << "  Space Complexity: O(n) - recursion stack depth" << endl;
    cout << "\nTail Recursive Approach:" << endl;
    cout << "  Time Complexity: O(n)" << endl;
    cout << "  Space Complexity: O(1) - optimized by compiler" << endl;
    cout << "\nMathematical Formula:" << endl;
    cout << "  Time Complexity: O(1)" << endl;
    cout << "  Space Complexity: O(1)" << endl;
    
    cout << "\n--- Example Calculations ---" << endl;
    cout << "Sum of first 1 number = 1" << endl;
    cout << "Sum of first 2 numbers = 3" << endl;
    cout << "Sum of first 3 numbers = 6" << endl;
    cout << "Sum of first 4 numbers = 10" << endl;
    cout << "Sum of first 5 numbers = 15" << endl;
    cout << "Sum of first 10 numbers = 55" << endl;
    
    cout << "\n--- Mathematical Verification ---" << endl;
    cout << "Formula: sum(n) = n*(n+1)/2" << endl;
    cout << "For n = " << n << ": " << n << "*(" << n << "+1)/2 = " << n << "*" << (n+1) << "/2 = " << sumFormula(n) << endl;
    
    return 0;
}
