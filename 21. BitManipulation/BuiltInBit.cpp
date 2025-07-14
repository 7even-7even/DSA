// C++ program to demonstrate built-in bit manipulation functions using a class
// Functions: __builtin_popcount, __builtin_parity, __builtin_clz, __builtin_ctz
// Author: Siddharth (7even)

#include <iostream>
using namespace std;

class BitManipulationDemo {
public:
    // Count number of 1s in binary representation
    static int popcount(int n) {
        return __builtin_popcount(n);
    }

    // Parity: 1 if odd number of 1s, 0 if even
    static int parity(int n) {
        return __builtin_parity(n);
    }

    // Count leading zeros before first 1 (for 32-bit int)
    static int clz(int n) {
        return __builtin_clz(n);
    }

    // Count trailing zeros after last 1
    static int ctz(int n) {
        return __builtin_ctz(n);
    }

    // Display all results for a given number
    static void showAll(int n) {
        cout << "\nNumber: " << n << " (Binary: ";
        printBinary(n);
        cout << ")\n";
        cout << "1. __builtin_popcount:  " << popcount(n) << "\n";
        cout << "2. __builtin_parity:    " << parity(n) << "\n";
        cout << "3. __builtin_clz:       " << clz(n) << "\n";
        cout << "4. __builtin_ctz:       " << ctz(n) << "\n";
    }

    // Print binary representation
    static void printBinary(int n) {
        for (int i = 31; i >= 0; i--) {
            cout << ((n >> i) & 1);
        }
    }
};

int main() {
    int n;
    cout << "=== Built-in Bit Manipulation Demo ===\n";
    cout << "Enter an integer: ";
    cin >> n;

    BitManipulationDemo::showAll(n);

    cout << "\n--- Function Descriptions ---\n";
    cout << "1. __builtin_popcount(n):   Number of 1s in binary representation.\n";
    cout << "2. __builtin_parity(n):     Parity (1 if odd number of 1s, else 0).\n";
    cout << "3. __builtin_clz(n):        Count of leading zeros before first 1 (32-bit).\n";
    cout << "4. __builtin_ctz(n):        Count of trailing zeros after last 1.\n";

    cout << "\n--- Example ---\n";
    cout << "For n = 16 (binary 00000000000000000000000000010000):\n";
    cout << "  popcount: 1\n  parity: 1\n  clz: 27\n  ctz: 4\n";

    return 0;
}