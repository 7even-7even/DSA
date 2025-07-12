/*
 * Factorial.cpp
 * 
 * This program calculates the factorial of a number using recursion.
 * 
 * Time Complexity: O(n) - where n is the input number
 * Space Complexity: O(n) - due to recursion stack depth
 * 
 * Example Output:
 * Enter a number to calculate factorial: 5
 * Factorial of 5 = 120
 * 
 * Recursive Formula: n! = n × (n-1)!
 * Base Case: 0! = 1, 1! = 1
 */

#include <iostream>
using namespace std;

// Function to calculate factorial recursively
// Parameters: n - the number whose factorial we want to calculate
// Returns: factorial of n
long long factorial(int n) {
    // Base case: factorial of 0 and 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive case: n! = n × (n-1)!
    return n * factorial(n - 1);
}

// Function to calculate factorial iteratively (for comparison)
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    
    cout << "=== Factorial Calculator using Recursion ===" << endl;
    cout << "Enter a number to calculate factorial: ";
    cin >> n;
    
    // Input validation
    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers!" << endl;
        return 1;
    }
    
    if (n > 20) {
        cout << "Warning: Large numbers may cause overflow!" << endl;
    }
    
    cout << "\n--- Recursive Approach ---" << endl;
    cout << "Factorial of " << n << " = " << factorial(n) << endl;
    
    cout << "\n--- Iterative Approach (for comparison) ---" << endl;
    cout << "Factorial of " << n << " = " << factorialIterative(n) << endl;
    
    cout << "\n--- Complexity Analysis ---" << endl;
    cout << "Time Complexity: O(n)" << endl;
    cout << "Space Complexity: O(n) - recursion stack depth" << endl;
    
    cout << "\n--- Example Calculations ---" << endl;
    cout << "0! = 1" << endl;
    cout << "1! = 1" << endl;
    cout << "2! = 2" << endl;
    cout << "3! = 6" << endl;
    cout << "4! = 24" << endl;
    cout << "5! = 120" << endl;
    
    return 0;
}
